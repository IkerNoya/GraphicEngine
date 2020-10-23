#include "textureImporter.h"
#include "stb_image.h"
#include "GL/glew.h";
#include "GLFW/glfw3.h";

#define STB_IMAGE_IMPLEMENTATION
TextureImporter::TextureImporter() {
	_height = 0;
	_width = 0;
	_nrChannels = 0;
}

TextureImporter::TextureImporter(int height, int width, int nrChannels, const char* path) {
	_height = height;
	_width = width;
	_nrChannels = nrChannels;
	_data = stbi_load(path, &_width, &_height, &_nrChannels, 0);
}

TextureImporter::~TextureImporter() {

}

void TextureImporter::setHeight(int height) {
	_height = height;
}

int TextureImporter::getHeight() {
	return _height;
}

void TextureImporter::setWidth(int width) {
	_width = width;
}

int TextureImporter::getWidth() {
	return _width;
}

void TextureImporter::setNrChanels(int nrChannels) {
	_nrChannels = nrChannels;
}

int TextureImporter::getNrChannels() {
	return _nrChannels;
}

void TextureImporter::generateTexture() {
	unsigned int texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//se carga la textura
	if (_data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _width, _height, 0, GL_RGB, GL_UNSIGNED_BYTE, _data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}else {
		std::cout << "Error - Couldn't load texture" << std::endl;
	}
	stbi_image_free(_data);
}