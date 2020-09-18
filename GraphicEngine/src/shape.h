#ifndef SHAPE_H
#define SHAPE_H
#include "export.h"
#include "entity.h"

class ENGINE_API Shape:public Entity{
public:
	Shape();
	~Shape();
	void CreateTriangle(float x1, float y1, float x2, float y2, float x3, float y3);
};
#endif // !SHAPE_H

	