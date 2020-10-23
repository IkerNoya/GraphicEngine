#include "textureImporter.h"
//stb se encarga de cargar imagenes
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

TextureImporter::TextureImporter() {
	_data = 0;
}

TextureImporter::TextureImporter(int height, int width, int nrChannels, const char* path) {
	_data = stbi_load(path, &width, &height, &nrChannels, 0);
}

TextureImporter::~TextureImporter() {

}

void TextureImporter::loadImage(int height, int width, int nrChannels, const char* path) {
	_data = stbi_load(path, &width, &height, &nrChannels, 0);
}

unsigned char* TextureImporter::getData() {
	return _data;
}

void TextureImporter::freeSpace() {
	stbi_image_free(_data);
}

