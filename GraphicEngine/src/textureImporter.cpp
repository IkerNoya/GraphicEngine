#include "textureImporter.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"
//stb se encarga de cargar imagenes
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

TextureImporter::TextureImporter() {
	_data = 0;
}

TextureImporter::TextureImporter(int height, int width, int nrChannels, const char* path) {
	_data = stbi_load(path, &width, &height, &nrChannels, 0);
	if (_data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, _data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		std::cout << "Error - Couldn't load texture" << std::endl;
	}
}

TextureImporter::~TextureImporter() {

}

void TextureImporter::loadImage(int height, int width, int nrChannels, const char* path, bool transparency, unsigned int &texture) {
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	_data = stbi_load(path, &width, &height, &nrChannels, 0);
	if (_data) {
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		if(!transparency)
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, _data);
		else
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, _data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		std::cout << "Error - Couldn't load texture" << std::endl;
	}

	freeSpace();
}

unsigned char* TextureImporter::getData() {
	return _data;
}

void TextureImporter::freeSpace() {
	stbi_image_free(_data);
}

