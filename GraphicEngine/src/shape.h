#ifndef SHAPE_H
#define SHAPE_H
#include "export.h"
#include "entity.h"

class ENGINE_API Shape :public Entity {
	//float _color[3];
	unsigned int _shape;
	unsigned int _vbo;
	unsigned int _ebo;
	unsigned int _vao;
	void initTriangleVertex();
	void initRectangleVertex();
public:
	Shape(unsigned int shape, Renderer* renderer);
	~Shape();
	unsigned int getType();
	void createVBO(float* vertex, int vertexAmmount);
	unsigned int getVBO();
	void createEBO(unsigned int* index, int indexAmmount);
	unsigned int getEBO();
	void createVAO();
	unsigned int getVAO();
	void init();
	void setColor(float r, float g, float b);
	void draw(unsigned int& shader, glm::mat4 trs);
};
#endif // !SHAPE_H