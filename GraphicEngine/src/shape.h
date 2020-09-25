#ifndef SHAPE_H
#define SHAPE_H
#include "export.h"
#include "entity.h"

class ENGINE_API Shape:public Entity{
	float _color[3];
public:
	Shape();
	~Shape();
	void setColor(float r, float g, float b);
	void CreateTriangle(float x1, float y1, float x2, float y2, float x3, float y3);
	void CreateRectangle(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
};
#endif // !SHAPE_H

	