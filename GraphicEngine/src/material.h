#ifndef MATERIAL_H
#define MATERIAL_H

#include "export.h"

class ENGINE_API Material {
private:
	float _color[3];
public:
	Material();
	Material(float r, float g, float b);
	~Material();
	void setColor(float r, float g, float b);
	void setR(float r);
	void setG(float g);
	void setB(float b);
	float getR();
	float getG();
	float getB();
	float getColorRGB();
};

#endif