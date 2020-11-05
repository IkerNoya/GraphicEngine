#include "GL/glew.h";
#include "GLFW/glfw3.h";
#include "sprite.h"
#include "stb_image.h"

Sprite::Sprite(Renderer* renderer):Entity(Entity::_renderer){
	texImporter = new TextureImporter();
	mat = new Material();
}

Sprite::~Sprite() {
	glDeleteTextures(1, &_texture);
	if (_vertex != NULL) {
		delete _vertex;
	}
	if (mat != NULL) {
		delete mat;
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

#pragma endregion

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

void Sprite::setTexture(const char* path) {
	stbi_set_flip_vertically_on_load(true);
	generateTexture(path);
	_vertex = new float[32] {
	 0.5f,  0.5f, 0.0f,   1,1,1,   1.0f, 1.0f,
	 0.5f, -0.5f, 0.0f,   1,1,1,   1.0f, 0.0f,
	-0.5f, -0.5f, 0.0f,   1,1,1,   0.0f, 0.0f,
	-0.5f,  0.5f, 0.0f,   1,1,1,   0.0f, 1.0f
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
	glGenTextures(1, &_texture);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, _texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	texImporter->loadImage(_width, _height, _nrChannels, path);
	texImporter->freeSpace();
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

void Sprite::setColor(float r, float g, float b) {
	mat->setColor(r, g, b);
}

void Sprite::draw(unsigned int &shader, glm::mat4 trs) {
	_renderer->drawTexture(getVBO(), shader, trs);
	bindTexture();
}