#include "GL/glew.h";
#include "GLFW/glfw3.h";
#include "sprite.h"
#include "stb_image.h"

Sprite::Sprite(Renderer* renderer, bool isAnimated, bool transparency):Entity(Entity::_renderer){
	texImporter = new TextureImporter();
	mat = new Material();
	_isAnimated = isAnimated;
	_transparency = transparency;
	if (!_isAnimated) {
		uv[0].u = 1.0f; uv[0].v = 1.0f;
		uv[1].u = 1.0f; uv[1].v = 0;
		uv[2].u = 0;    uv[2].v = 0;
		uv[3].u = 0;    uv[3].v = 1.0f;
	}
}

Sprite::~Sprite() {
	glDeleteTextures(1, &_texture);
	if (_vertex != NULL) {
		delete _vertex;
	}
	if (mat != NULL) {
		delete mat;
	} 
	if (anim != NULL) {
		delete anim;
	}
	if (_vertex != NULL) {
		delete _vertex;
	}
}

#pragma region SETTERS/GETTERS

void Sprite::setHeight(int height) {
	_height = height;
}
int Sprite::getHeight() {
	return _height;
}
void Sprite::setWidth(int width) {
	_width = width;
}
int Sprite::getWidth() {
	return _width;
}
void Sprite::setNrChanels(int nrChannels) {
	_nrChannels = nrChannels;
}
int Sprite::getNrChannels() {
	return _nrChannels;
}
void Sprite::createVBO(float* vertex, int vertexAmmount) {
	int vertexSize = sizeof(vertex) * vertexAmmount;
	glGenBuffers(1, &_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glBufferData(GL_ARRAY_BUFFER, vertexSize, vertex, GL_STATIC_DRAW);
}
unsigned int Sprite::getVBO() {
	return _vbo;
}

void Sprite::createEBO(unsigned int* index, int indexAmmount) {
	unsigned int indexSize = sizeof(index) * indexAmmount;
	glGenBuffers(1, &_ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexSize, index, GL_STATIC_DRAW);

}
unsigned int Sprite::getEBO() {
	return _ebo;
}
void Sprite::createVAO() {
	glGenVertexArrays(1, &_vao);
	glBindVertexArray(_vao);
}
unsigned int Sprite::getVAO() {
	return _vao;
}
void Sprite::setAnimation(Animation* animation) {
	anim = animation;
	_previousFrame = std::numeric_limits<unsigned int>::max_digits10;
}
Animation* Sprite::getAnimation() {
	return anim;
}
#pragma endregion

void Sprite::setTexture(const char* path) {
	stbi_set_flip_vertically_on_load(true);
	generateTexture(path);
	_vertex = new float[32] {
	 1,  1, 0.0f, *mat->getR(), *mat->getG(), *mat->getB(),  uv[0].u, uv[0].v,
	 1, -1, 0.0f, *mat->getR(), *mat->getG(), *mat->getB(),  uv[1].u, uv[1].v,
	-1, -1, 0.0f, *mat->getR(), *mat->getG(), *mat->getB(),  uv[2].u, uv[2].v,
	-1,  1, 0.0f, *mat->getR(), *mat->getG(), *mat->getB(),  uv[3].u, uv[3].v
	};
	_size = 32;
	unsigned int index[] = {
		0, 1, 3,
		1, 2, 3
	};
	createVAO();
	createEBO(index, 6);
	createVBO(_vertex, _size);
}

void Sprite::generateTexture(const char* path) {
	texImporter->loadImage(_width, _height, _nrChannels, path, _transparency, _texture);
}

unsigned int Sprite::getTexture() {
	return _texture;
}

void Sprite::bindTexture() {
	glBindTexture(GL_TEXTURE_2D, _texture);
}

float* Sprite::getVertex() {
	return _vertex;
}

void Sprite::setAnimCoords(float u0, float v0, float u1, float v1, float u2, float v2, float u3, float v3) {
	uv[0].u = u0; uv[0].v = v0;
	uv[1].u = u1; uv[1].v = v1;
	uv[2].u = u2; uv[2].v = v2;
	uv[3].u = u3; uv[3].v = v3;
}
void Sprite::updateAnimation(Time& time) {
	if (anim != NULL) {
		anim->update(time);
		_currentFrame = anim->getCurrentFrame();
		if (_currentFrame != _previousFrame) {
			setAnimCoords(anim->GetFrames()[_currentFrame].frameCoordinates[0].u, anim->GetFrames()[_currentFrame].frameCoordinates[0].v,
				anim->GetFrames()[_currentFrame].frameCoordinates[1].u, anim->GetFrames()[_currentFrame].frameCoordinates[1].v,
				anim->GetFrames()[_currentFrame].frameCoordinates[2].u, anim->GetFrames()[_currentFrame].frameCoordinates[2].v,
				anim->GetFrames()[_currentFrame].frameCoordinates[3].u, anim->GetFrames()[_currentFrame].frameCoordinates[3].v);
			_previousFrame = _currentFrame;
		}
		setAnimation(anim);
	}
}

void Sprite::setColor(float r, float g, float b) {
	mat->setColor(r, g, b);
}

void Sprite::draw(unsigned int &shader, glm::mat4 trs) {
	if (_transparency) {
		blendSprite();
		bindTexture();
		_renderer->drawTexture(getVBO(), shader, trs);
		unblendSprite();
		glDisable(GL_TEXTURE_2D);
	}
	else {
		bindTexture();
		_renderer->drawTexture(getVBO(), shader, trs);
		glDisable(GL_TEXTURE_2D);
	}
}
void Sprite::blendSprite() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}
void Sprite::unblendSprite() {
	glDisable(GL_BLEND);
}