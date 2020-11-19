#include "GL/glew.h";
#include "GLFW/glfw3.h";
#include "sprite.h"
#include "stb_image.h"

Sprite::Sprite(Renderer* renderer, bool transparency):Entity(Entity::_renderer){
	texImporter = new TextureImporter();
	mat = new Material();
	_transparency = transparency;
	uv[0].u = 0.0f; uv[0].v = 0.0f;
	uv[1].u = 0.0f; uv[1].v = 0;
	uv[2].u = 0;    uv[2].v = 0;
	uv[3].u = 0;    uv[3].v = 0.0f;

}

Sprite::~Sprite() {
	glDeleteTextures(1, &_texture);
	/*if (_vertex != NULL) {
		delete _vertex;
	}*/
	if (mat != NULL) {
		delete mat;
	} 
	if (anim != NULL) {
		delete anim;
	}
	/*if (_vertex != NULL) {
		delete _vertex;
	}*/
}
#pragma region SETTERS/GETTERS
void Sprite::setColorBuffer() {
	vertex[3] = *mat->getR(); vertex[4] = *mat->getG(); vertex[5] = *mat->getB();
	vertex[11] = *mat->getR(); vertex[12] = *mat->getG(); vertex[13] = *mat->getB();
	vertex[19] = *mat->getR(); vertex[20] = *mat->getG(); vertex[21] = *mat->getB();
	vertex[27] = *mat->getR(); vertex[28] = *mat->getG(); vertex[29] = *mat->getB();
}

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
	float _vertex[] = {
	 1,  1, 0.0f, *mat->getR(), *mat->getG(), *mat->getB(),  uv[0].u, uv[0].v,
	 1, -1, 0.0f, *mat->getR(), *mat->getG(), *mat->getB(),  uv[1].u, uv[1].v,
	-1, -1, 0.0f, *mat->getR(), *mat->getG(), *mat->getB(),  uv[2].u, uv[2].v,
	-1,  1, 0.0f, *mat->getR(), *mat->getG(), *mat->getB(),  uv[3].u, uv[3].v
	};
	_size = 32;

	createVAO();
	createEBO(index, 6);
	createVBO(vertex, _size);

}

void Sprite::generateTexture(const char* path) {
	texImporter->loadImage(_width, _height, _nrChannels, path, _transparency, _texture);
}

unsigned int Sprite::getTexture() {
	return _texture;
}

void Sprite::bindTexture() {
	glBindTexture(GL_TEXTURE_2D, _texture);
	glActiveTexture(GL_TEXTURE0);
}

void Sprite::setAnimCoords(float u0, float v0, float u1, float v1, float u2, float v2, float u3, float v3) {
	vertex[6] = u0;   vertex[7] = v0;
	vertex[14] = u1;  vertex[15] = v1;
	vertex[22] = u2;  vertex[23] = v2;
	vertex[30] = u3;  vertex[31] = v3;

}
void Sprite::updateAnimation(Time& time) {
	if (anim != NULL) {
		anim->update(time);
		_currentFrame = anim->getCurrentFrame();

		if (_currentFrame != _previousFrame) {
			setAnimCoords(anim->getAnimation()[_currentFrame].frameCoordinates[0].u, anim->getAnimation()[_currentFrame].frameCoordinates[0].v,
						  anim->getAnimation()[_currentFrame].frameCoordinates[1].u, anim->getAnimation()[_currentFrame].frameCoordinates[1].v,
				          anim->getAnimation()[_currentFrame].frameCoordinates[2].u, anim->getAnimation()[_currentFrame].frameCoordinates[2].v,
				          anim->getAnimation()[_currentFrame].frameCoordinates[3].u, anim->getAnimation()[_currentFrame].frameCoordinates[3].v);
			_previousFrame = _currentFrame;
		}
		setAnimation(anim);
	}
}

void Sprite::setColor(float r, float g, float b) {
	mat->setColor(r, g, b);
	setColorBuffer();
}

void Sprite::draw(unsigned int &shader) {
	if (_transparency) {
		blendSprite();
		bindTexture();
		_renderer->drawTexture(getVBO(), getVAO(), vertex, shader, getTRS());
		unblendSprite();
		glDisable(GL_TEXTURE_2D);
	}
	else {
		bindTexture();
		_renderer->drawTexture(getVBO(), getVAO(), vertex, shader, getTRS());
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
void Sprite::SetCurrentAnimationIndex(int currentAnimation) {
	if (anim != NULL) anim->setCurrentAnimation(currentAnimation);
}
