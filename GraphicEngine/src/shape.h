#ifndef SHAPE_H
#define SHAPE_H
#include "export.h"
#include "entity.h"
#include "Shader.h"
enum ENGINE_API Type {
	triangle, rectangle
};
class ENGINE_API Shape :public Entity {
	//float _color[3];
	Type type;
	unsigned int _shape;
	unsigned int _vbo;
	unsigned int _ebo;
	unsigned int _vao;

	float triVertex[18] = {
   -0.5f, -0.5f, 0, 1,1,1,
   0.0f, 0.5f, 0, 1,1,1,
   0.5f, -0.5f, 0, 1,1,1
	};
	unsigned int triIndex[3] = {
		0, 1, 2
	};

	float quadVertex[24] = {
	-0.5f, -0.5f, 0, 1,1,1,
	-0.5f, 0.5f, 0, 1,1,1,
	0.5f, 0.5f, 0, 1,1,1,
	0.5f, -0.5f, 0, 1,1,1
	};
	unsigned int quadIndex[6] = {
		0, 1, 3,
		1, 2, 3
	};
	void initTriangleVertex();
	void initRectangleVertex();
	void setColorVertex();
public:
	Shape(Type shape, Renderer* renderer);
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
	void draw(Shader& shader);
};
#endif // !SHAPE_H