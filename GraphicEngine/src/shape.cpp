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
float* Shape::initTriangleVertex() {
	 float vertexTriangle[15] = {
		-0.5f, 0.0f, _color[0],_color[1],_color[2],
		0.0f, 0.5f, _color[0],_color[1],_color[2],
		0.5f, 0.0f, _color[0],_color[1],_color[2]
	};
	 return vertexTriangle;
}
float* Shape::initRectangleVertex() {
	float vertex[20] = {
		-0.5f, -0.5f, _color[0],_color[1],_color[2],
		-0.5f, 0.5f, _color[0],_color[1],_color[2],
		0.5f, 0.5f, _color[0],_color[1],_color[2],
		0.5f, -0.5f, _color[0],_color[1],_color[2]
	};
	return vertex;
}
void Shape::setColor(float r, float g, float b) {
	_color[0] = r;
	_color[1] = g;
	_color[2] = b;
}
void Shape::CreateTriangle(float x1, float y1, float x2, float y2, float x3, float y3) {	// Cambiar a structs con Vectores 2
	float vertex[15] = { *initTriangleVertex() };
	_renderer->bindVBO(vertex);
}
void Shape::CreateRectangle(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {   // Cambiar a structs con Vectores 2
	float vertex[20] = { *initRectangleVertex() };
	_renderer->bindVBO(vertex);
}