#ifndef RENDERER_H
#define RENDERER_H
#include "export.h"
class ENGINE_API Renderer {

public:
	Renderer();
	~Renderer();
	void CreateTriangle(float x1, float y1, float x2, float y2, float x3, float y3);
	void DrawTriangle();
};

#endif // !RENDERER_H