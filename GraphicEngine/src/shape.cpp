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
void Shape::setColor(float r, float g, float b) {
	_color[0] = r;
	_color[1] = g;
	_color[2] = b;
}
void Shape::CreateTriangle(float x1, float y1, float x2, float y2, float x3, float y3) {	// Cambiar a structs con Vectores 2
	float vertex[15] = {
		x1, y1, _color[0],_color[1],_color[2],
		x2, y2, _color[0],_color[1],_color[2],
		x3, y3, _color[0],_color[1],_color[2]
	};

	_renderer->bindVBO(vertex);
}
void Shape::CreateRectangle(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {   // Cambiar a structs con Vectores 2
	float vertexs[20] = {
		x1, y1, _color[0],_color[1],_color[2],
		x2, y2, _color[0],_color[1],_color[2],
		x3, y3, _color[0],_color[1],_color[2],
		x4, y4, _color[0],_color[1],_color[2]
	};
}