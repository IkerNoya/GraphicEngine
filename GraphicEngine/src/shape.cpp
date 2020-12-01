#include "GL/glew.h"
#include "shape.h"

#include <stdlib.h>

#include "GLFW/glfw3.h"


Shape::Shape(Type shape, Renderer* renderer):Entity(Entity::_renderer) {
	type = shape;
	switch (shape)
	{
	case triangle:
		_shape = GL_TRIANGLES;
		cout << "Tri" << endl;
		break;
	case rectangle:
		_shape = GL_QUADS;
		cout << "Quads" << endl;
		break;
	default:
		break;
	}
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

	createVAO();
	createEBO(triIndex, 3);
	createVBO(triVertex, 18);
}
void Shape::initRectangleVertex() {
	createVAO();
	createEBO(quadIndex, 6);
	createVBO(quadVertex, 24);
}
void Shape::setColorVertex(){
	if (_shape == GL_TRIANGLES) {
		triVertex[3] = *_material->getR(); triVertex[4] = *_material->getG(); triVertex[5] = *_material->getB();
		triVertex[9] = *_material->getR(); triVertex[10] = *_material->getG(); triVertex[11] = *_material->getB();
		triVertex[15] = *_material->getR(); triVertex[16] = *_material->getG(); triVertex[17] = *_material->getB();
	}
	else if (_shape == GL_QUADS){
		quadVertex[3] = *_material->getR(); quadVertex[4] = *_material->getG(); quadVertex[5] = *_material->getB();
		quadVertex[9] = *_material->getR(); quadVertex[10] = *_material->getG(); quadVertex[11] = *_material->getB();
		quadVertex[15] = *_material->getR(); quadVertex[16] = *_material->getG(); quadVertex[17] = *_material->getB();
		quadVertex[21] = *_material->getR(); quadVertex[22] = *_material->getG(); quadVertex[23] = *_material->getB();
	}
}
void Shape::setColor(float r, float g, float b) {
	_material->setColor(r, g, b);
	setColorVertex();
}
void Shape::draw(Shader& shader) {
	if (type == triangle)
		_renderer->drawShape(_shape, getVBO(), getVAO(), triVertex, 18, shader, getTRS());
	else if (type == rectangle)
		_renderer->drawShape(_shape, getVBO(), getVAO(), quadVertex, 24, shader, getTRS());
}