#ifndef TEXTURE_IMPORTER
#define TEXTURE_IMPORTER

class TextureImporter {
	int _height;
	int _width;
	int _nrChannels;
public:
	TextureImporter();
	TextureImporter(int height, int width, int nrChannels);
	~TextureImporter();
	void setHeight(int height);
	int getHeight();
	void setWidth(int width);
	int getWidth();
	void setNrChanels(int nrChannels);
	int getNrChannels();
	void loadImage();
	void generateTexture();
};
#endif // !TEXTURE_IMPORTER

