#ifndef SPRITE_H
#define SPRITE_H
#define SPRITE_H
#include "export.h"
#include "entity.h"
#include "textureImporter.h"
#include "material.h"

class ENGINE_API Sprite : public Entity {
	int _height;
	int _width;
	int _nrChannels;
	unsigned int _texture;
	const char* _path;

	Material* mat;
	TextureImporter* texImporter;
public:
	float* _vertex;
	Sprite(Renderer* renderer);
	~Sprite();
	void setHeight(int height);
	int getHeight();
	void setWidth(int width);
	int getWidth();
	void setNrChanels(int nrChannels);
	int getNrChannels();
	void setTexture(const char* path);
	void generateTexture(const char* path);
	unsigned int getTexture();
	void bindTexture();
	float* getVertex();
	void setColor(float r, float g, float b);
};
#endif // !SPRITE_H

