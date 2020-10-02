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
	void SetColor(float r, float g, float b);
	float GetR();
	float GetG();
	float GetB();
	float GetColorRGB();
};

#endif