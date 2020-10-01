#ifndef SHAPE_H
#define SHAPE_H
#include "export.h"
#include "entity.h"

class ENGINE_API Shape :public Entity {
	float _color[3];
	//float* vertex;
public:
	Shape();
	~Shape();
	void initTriangleVertex();
	void initRectangleVertex();
	void setColor(float r, float g, float b);
};
#endif // !SHAPE_H