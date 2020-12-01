#include "GL/glew.h"
#include "renderer.h"
#include <stdlib.h>
#include <iostream>
#include "GLFW/glfw3.h"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"
#include "stb_image.h"
#include <fstream>

Renderer::Renderer() {

}

Renderer::~Renderer() {

}

void Renderer::setSpriteAttrib(Shader &shader) {
	unsigned int texturePosAttrib = glGetAttribLocation(shader.getId(), "position");
	unsigned int textureColorAttrib = glGetAttribLocation(shader.getId(), "customColor");
	unsigned int uvAttrib = glGetAttribLocation(shader.getId(), "aTexCoord");
	glUniform1i((glGetUniformLocation(shader.getId(), "ourTexture")), 0);
	createVertexAttrib(texturePosAttrib, 8);
	createColorAttrib(textureColorAttrib, 8);
	createTextureAttrib(uvAttrib, 8);
}
void Renderer::setShapeAttrib(Shader& shader) {
	unsigned int shapePosAttrib = glGetAttribLocation(shader.getId(), "position");
	unsigned int shapeColorAttrib = glGetAttribLocation(shader.getId(), "customColor");

	createVertexAttrib(shapePosAttrib, 6);
	createColorAttrib(shapeColorAttrib, 6);
}
void Renderer::createVertexAttrib(unsigned int posAttrib, int dataSize){
	glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, sizeof(float) * dataSize, 0);
	glEnableVertexAttribArray(posAttrib);
}
void Renderer::createColorAttrib(unsigned int colorAttrib, int dataSize){
	glVertexAttribPointer(colorAttrib, 3, GL_FLOAT, GL_FALSE, sizeof(float) * dataSize, (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(colorAttrib);
}
void Renderer::createTextureAttrib(unsigned int uvAttribute, int dataSize) {
	glVertexAttribPointer(uvAttribute, 2, GL_FLOAT, GL_FALSE, dataSize * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(uvAttribute);
}

void Renderer::startProgram(Shader &shader, glm::mat4 model) {
	unsigned int transformLoc = glGetUniformLocation(shader.getId(), "transform");
	shader.use();
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(model));
}
void Renderer::bindSpriteBuffers(unsigned int vbo, unsigned int vao, float* vertex, float size) {
	int memorySize = sizeof(float) * size;
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBindVertexArray(vao);
	glBufferData(GL_ARRAY_BUFFER, memorySize, vertex, GL_STATIC_DRAW);
}
void Renderer::bindShapeBuffers(unsigned int vbo) {
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
}
void Renderer::UnbindBuffers() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
void Renderer::drawCamera(Shader &shader, glm::mat4 view, glm::mat4 projection, glm::mat4 model) {
	unsigned int transformLoc = glGetUniformLocation(shader.getId(), "transform");
	unsigned int projectionLoc = glGetUniformLocation(shader.getId(), "projection");
	unsigned int viewLoc = glGetUniformLocation(shader.getId(), "view");
	shader.use();
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view)); 
}
void Renderer::drawShape(unsigned int shape, unsigned int vbo, Shader &shader, glm::mat4 trs) {
	bindShapeBuffers(vbo);
	setShapeAttrib(shader);
	startProgram(shader, trs);
	if (shape == GL_TRIANGLES) {
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
	}
	else if (shape == GL_QUADS) {
		glDrawElements(GL_QUADS, 6, GL_UNSIGNED_INT, 0);
	}
	UnbindBuffers();
}
void Renderer::drawTexture(unsigned int vbo, unsigned int vao, float* vertex, Shader &shader, glm::mat4 trs) {
	bindSpriteBuffers(vbo, vao, vertex, 32);
	setSpriteAttrib(shader);
	startProgram(shader, trs);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	UnbindBuffers();
}
