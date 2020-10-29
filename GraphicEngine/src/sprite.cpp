#include "GL/glew.h";
#include "GLFW/glfw3.h";
#include "sprite.h"
#include "stb_image.h"

Sprite::Sprite(Renderer* renderer):Entity(Entity::_renderer){
	texImporter = new TextureImporter();
}

Sprite::~Sprite() {
	glDeleteTextures(1, &_texture);
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

void Sprite::setTexture(const char* path) {
	generateTexture(path);
	float vertex[32] = {
	 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,
	 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,
	-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,
	-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f
	};
	unsigned int index[] = {
		0, 1, 3,
		1, 2, 3
	};
	_renderer->bindVAO();
	_renderer->bindEBO(index);
	_renderer->bindVBO(vertex, 32);
}

void Sprite::generateTexture(const char* path) {
	//se carga la textura
	glGenTextures(1, &_texture);
	bindTexture();
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	texImporter->loadImage(_height,_width,_nrChannels, path);
	if (texImporter->getData()) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _width, _height, 0, GL_RGB, GL_UNSIGNED_BYTE, texImporter->getData());
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		std::cout << "Error - Couldn't load texture" << std::endl;
	}

	texImporter->freeSpace();
}

unsigned int Sprite::getTexture() {
	return _texture;
}

void Sprite::bindTexture() {
	glBindTexture(GL_TEXTURE_2D, _texture);
	//glBindTextureUnit(0, _texture);
}