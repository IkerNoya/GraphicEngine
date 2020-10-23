#include "textureImporter.h"
#include "stb_image.h"

#define STB_IMAGE_IMPLEMENTATION
TextureImporter::TextureImporter() {
	_height = 0;
	_width = 0;
	_nrChannels = 0;
}

TextureImporter::TextureImporter(int height, int width, int nrChannels) {
	_height = height;
	_width = width;
	_nrChannels = nrChannels;
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

void TextureImporter::loadImage() {
	
}

void TextureImporter::generateTexture() {

}