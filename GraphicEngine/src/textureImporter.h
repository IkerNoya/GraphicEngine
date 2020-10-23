#ifndef TEXTURE_IMPORTER
#define TEXTURE_IMPORTER
#include <iostream>
#include "export.h"

class ENGINE_API TextureImporter {
	unsigned char* _data;
public:
	TextureImporter();
	TextureImporter(int height, int width, int nrChannels, const char* path);
	~TextureImporter();
	void loadImage(int height, int width, int nrChannels, const char* path);
	unsigned char *getData(); // returns the image
	void freeSpace();
};
#endif // !TEXTURE_IMPORTER

