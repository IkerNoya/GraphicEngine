#include "GL/glew.h";
#include "GLFW/glfw3.h";
#include "sprite.h"

Sprite::Sprite(Renderer* renderer, const char* path):Entity(Entity::_renderer){
	texImporter = new TextureImporter();
	_path = path;
}

Sprite::~Sprite() {

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


void Sprite::createTexture(int height, int width, int nrChannels, const char* path) {
	_height = height; _width = width; _nrChannels = nrChannels;
	texImporter->loadImage(_height, _width, _nrChannels, _path);
}

void Sprite::generateTexture() {
	glGenTextures(1, &_texture);
	glBindTexture(GL_TEXTURE_2D, _texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//se carga la textura
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