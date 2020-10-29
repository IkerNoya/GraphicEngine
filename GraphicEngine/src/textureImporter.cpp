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

void TextureImporter::loadImage(int height, int width, int nrChannels, const char* path) {
	_data = stbi_load(path, &width, &height, &nrChannels, 0);
	if (_data) {
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, _data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		std::cout << "Error - Couldn't load texture" << std::endl;
	}
}

unsigned char* TextureImporter::getData() {
	return _data;
}

void TextureImporter::freeSpace() {
	stbi_image_free(_data);
}

