#include "GL/glew.h"
#include "shape.h"

#include <stdlib.h>

#include "GLFW/glfw3.h"


Shape::Shape():Entity(Entity::_renderer) {

}
Shape::~Shape() {
	/*if (vertex != NULL)
		delete[] vertex;*/
}
void Shape::initTriangleVertex() {
	float vertex[15] = {
	   -0.5f, 0.0f, _color[0],_color[1],_color[2],
	   0.0f, 0.5f, _color[0],_color[1],_color[2],
	   0.5f, 0.0f, _color[0],_color[1],_color[2]
	};
	_renderer->bindVBO(vertex, 15);
}
void Shape::initRectangleVertex() {
	float vertex[20] = {
	-0.5f, -0.5f, _color[0],_color[1],_color[2],
	-0.5f, 0.5f, _color[0],_color[1],_color[2],
	0.5f, 0.5f, _color[0],_color[1],_color[2],
	0.5f, -0.5f, _color[0],_color[1],_color[2]
	};
	_renderer->bindVBO(vertex, 20);
}
void Shape::setColor(float r, float g, float b) {
	_color[0] = r;
	_color[1] = g;
	_color[2] = b;
}