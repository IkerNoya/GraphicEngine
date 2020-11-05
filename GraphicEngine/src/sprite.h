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
	int _size;
	float* _vertex;
	unsigned int _vbo;
	unsigned int _ebo;
	unsigned int _vao;

	Material* mat;
	TextureImporter* texImporter;
public:
	Sprite(Renderer* renderer);
	~Sprite();
	void setHeight(int height);
	int getHeight();
	void setWidth(int width);
	int getWidth();
	void setNrChanels(int nrChannels);
	int getNrChannels();
	void createVBO(float* vertex, int vertexAmmount);
	unsigned int getVBO();
	void createEBO(unsigned int* index, int indexAmmount);
	unsigned int getEBO();
	void createVAO();
	unsigned int getVAO();
	void setTexture(const char* path);
	void generateTexture(const char* path);
	unsigned int getTexture();
	void bindTexture();
	float* getVertex();
	void setColor(float r, float g, float b);
	void draw(unsigned int &shader, glm::mat4 trs);
};
#endif // !SPRITE_H

