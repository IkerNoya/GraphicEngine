#ifndef SPRITE_H
#define SPRITE_H
#define SPRITE_H
#include "export.h"
#include "entity.h"
#include "textureImporter.h"
#include "material.h"
#include "animation.h"
struct UV {
	float u;
	float v;
};
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
	bool _isAnimated;
	bool _transparency;
	int _currentFrame;
	int _previousFrame;


	Material* mat;
	TextureImporter* texImporter;
	Animation* anim;
	UV uv[4];
public:
	Sprite(Renderer* renderer, bool isAnimated, bool transparency);
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
	void setAnimation(Animation* animation);
	Animation* getAnimation();
	void setTexture(const char* path);
	void generateTexture(const char* path);
	unsigned int getTexture();
	void bindTexture();
	float* getVertex();
	void setAnimCoords(float u0, float v0, float u1, float v1, float u2, float v2, float u3, float v3);
	void updateAnimation(Time & time);
	void setColor(float r, float g, float b);
	void draw(unsigned int &shader, glm::mat4 trs);
	void blendSprite();
	void unblendSprite();
};
#endif // !SPRITE_H

