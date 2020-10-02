#ifndef SHAPE_H
#define SHAPE_H
#include "export.h"
#include "entity.h"

class ENGINE_API Shape :public Entity {
	//float _color[3];
	unsigned int _shape;
	void initTriangleVertex();
	void initRectangleVertex();
public:
	Shape(unsigned int shape, Renderer* renderer);
	~Shape();
	unsigned int getType();
	void init();
	void setColor(float r, float g, float b);
};
#endif // !SHAPE_H