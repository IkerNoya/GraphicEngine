#ifndef TEXTURE_IMPORTER
#define TEXTURE_IMPORTER
#include <iostream>
class TextureImporter {
	int _height;
	int _width;
	int _nrChannels;
	unsigned char* _data;
public:
	TextureImporter();
	TextureImporter(int height, int width, int nrChannels, const char* path);
	~TextureImporter();
	void setHeight(int height);
	int getHeight();
	void setWidth(int width);
	int getWidth();
	void setNrChanels(int nrChannels);
	int getNrChannels();
	void generateTexture();
};
#endif // !TEXTURE_IMPORTER

