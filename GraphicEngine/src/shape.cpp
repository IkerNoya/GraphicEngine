#include "GL/glew.h"
#include "shape.h"

#include <stdlib.h>

#include "GLFW/glfw3.h"


Shape::Shape(unsigned int shape, Renderer* renderer):Entity(Entity::_renderer) {
	_shape = shape;
	_material = new Material();
}
Shape::~Shape() {
	if (_material != NULL)
		delete _material;
}
unsigned int Shape::getType() {
	return _shape;
}
void Shape::createVBO(float* vertex, int vertexAmmount) {
	int vertexSize = sizeof(vertex) * vertexAmmount;
	glGenBuffers(1, &_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glBufferData(GL_ARRAY_BUFFER, vertexSize, vertex, GL_STATIC_DRAW);
}
unsigned int Shape::getVBO() {
	return _vbo;
}

void Shape::createEBO(unsigned int* index, int indexAmmount) {
	unsigned int indexSize = sizeof(index) * indexAmmount;
	glGenBuffers(1, &_ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexSize, index, GL_STATIC_DRAW);

}
unsigned int Shape::getEBO() {
	return _ebo;
}
void Shape::createVAO() {
	glGenVertexArrays(1, &_vao);
	glBindVertexArray(_vao);
}
unsigned int Shape::getVAO() {
	return _vao;
}
void Shape::init() {
	if (_shape == GL_TRIANGLES) {
		initTriangleVertex();
	}
	else if (_shape == GL_QUADS) {
		initRectangleVertex();
	}
}
void Shape::initTriangleVertex() {
	float vertex[18] = {
	   -0.5f, -0.5f, 0, *_material->getR(),*_material->getG(),*_material->getB(),
	   0.0f, 0.5f, 0, *_material->getR(),*_material->getG(),*_material->getB(),
	   0.5f, -0.5f, 0, *_material->getR(),*_material->getG(),*_material->getB()
	};
	unsigned int index[] = {
		0, 1, 3,
	};
	createVAO();
	createEBO(index, 3);
	createVBO(vertex, 18);
}
void Shape::initRectangleVertex() {
	float vertex[24] = {
	-0.5f, -0.5f, 0, *_material->getR(),*_material->getG(),*_material->getB(),
	-0.5f, 0.5f, 0, *_material->getR(),*_material->getG(),*_material->getB(),
	0.5f, 0.5f, 0, *_material->getR(),*_material->getG(),*_material->getB(),
	0.5f, -0.5f, 0, *_material->getR(),*_material->getG(),*_material->getB()
	};
	unsigned int index[] = {
		0, 1, 3,
		1, 2, 3
	};
	createVAO();
	createEBO(index, 6);
	createVBO(vertex, 24);
}
void Shape::setColor(float r, float g, float b) {
	_material->setColor(r, g, b);
}
void Shape::draw(unsigned int& shader, glm::mat4 trs) {
	_renderer->drawShape(_shape, getVBO(), shader, trs);
}