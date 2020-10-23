#ifndef SPRITE_H
#define SPRITE_H
#define SPRITE_H
#include "export.h"
#include "entity.h"
#include "textureImporter.h"

class ENGINE_API Sprite : public Entity {
	int _height;
	int _width;
	int _nrChannels;
	unsigned int _texture;
	const char* _path;
	TextureImporter* texImporter;
public:
	Sprite(Renderer* renderer, const char* path);
	~Sprite();
	void setHeight(int height);
	int getHeight();
	void setWidth(int width);
	int getWidth();
	void setNrChanels(int nrChannels);
	int getNrChannels();
	void createTexture(int height, int width, int nrChannels, const char* path);
	void generateTexture();
	unsigned int getTexture();
};
#endif // !SPRITE_H

