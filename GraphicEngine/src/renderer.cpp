#include "renderer.h"
#include <stdlib.h>
#include <iostream>
#include "GL/glew.h"
#include "GLFW/glfw3.h"
Renderer::Renderer() {

}
Renderer::~Renderer() {

}

void Renderer::CreateTriangle(float x1, float y1, float x2, float y2, float x3, float y3) {
	float vertexs[6] = {
		x1, y1,
		x2, y2,
		x3, y3,
	};

	GLuint buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(vertexs), vertexs, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
}
void Renderer::DrawTriangle() {
	glDrawArrays(GL_TRIANGLES, 0, 3);
}