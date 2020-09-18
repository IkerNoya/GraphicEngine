#include "GL/glew.h"
#include "shape.h"

#include <stdlib.h>

#include "GLFW/glfw3.h"

Shape::Shape():Entity(Entity::_renderer) {

}
Shape::~Shape() {

}
float color[3]{
	1.0f, 1.0f, 0.0f
};
void Shape::CreateTriangle(float x1, float y1, float x2, float y2, float x3, float y3) {
	float vertexs[15] = {
		x1, y1, color[0],color[1],color[2],
		x2, y2, color[0],color[1],color[2],
		x3, y3, color[0],color[1],color[2]
	};

	unsigned int vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexs), vertexs, GL_STATIC_DRAW);
}