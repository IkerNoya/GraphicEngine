#ifndef TEXTURE_IMPORTER
#define TEXTURE_IMPORTER
#include <iostream>
class TextureImporter {
	int _height;
	int _width;
	int _nrChannels;
	unsigned char* _data;
	unsigned int _texture;
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
	unsigned int getTexture();
	void generateTexture();
};
#endif // !TEXTURE_IMPORTER

