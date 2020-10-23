#include "GL/glew.h"
#include "renderer.h"
#include <stdlib.h>
#include <iostream>
#include "GLFW/glfw3.h"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"
#include <fstream>

Renderer::Renderer() {

}

Renderer::~Renderer() {
	glDeleteShader(_vertexShader);
	glDeleteShader(_fragmentShader);
	glDeleteShader(_textureShader);
}

void Renderer::setVertexShader(const std::string& vertexShader) {
	_vertexShader = compileShader(GL_VERTEX_SHADER, vertexShader);
}
void Renderer::setFragmentShader(const std::string& fragmentShader) {
	_fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentShader);
}
void Renderer::setTextureShader(const std::string& textureShader) {
	_textureShader = compileShader(GL_FRAGMENT_SHADER, textureShader);
}
unsigned int Renderer::getVertexShader() {
	return _vertexShader;
}
unsigned int Renderer::getFragmentShader() {
	return _fragmentShader;
}
unsigned int Renderer::getTextureShader() {
	return _textureShader;
}
unsigned int Renderer::compileShader(unsigned int type, const std::string& source) {
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);

	if (result == GL_FALSE) {
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)_malloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);
		std::cout << "Failed to compile" << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << "shader" << std::endl;
		std::cout << message << std::endl;
		glDeleteShader(id);
		return 0;
	}

	return id;
}

void Renderer::createVertexAttrib(int program)
{
	unsigned int posAttrib = glGetAttribLocation(program, "position");
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, 0);
	glEnableVertexAttribArray(posAttrib);
}
void Renderer::createColorAttrib(int program)
{
	unsigned int colorAttrib = glGetAttribLocation(program, "customColor");
	glVertexAttribPointer(colorAttrib, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)(2 * sizeof(float)));
	glEnableVertexAttribArray(colorAttrib);
}
void Renderer::createTextureAttrib(int program) {
	unsigned int textureAttrib = glGetAttribLocation(program, "aTexCoord");
	glVertexAttribPointer(textureAttrib, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(textureAttrib);
}
int Renderer::createShader() {
	unsigned int program = glCreateProgram();
	setVertexShader(CreateVertexShader());
	setFragmentShader(CreateFragmentShader());


	glAttachShader(program, _vertexShader);
	glAttachShader(program, _fragmentShader);
	glAttachShader(program, _textureShader);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(_vertexShader);
	glDeleteShader(_fragmentShader);
	glDeleteShader(_textureShader);

	return program;
}
std::string Renderer::CreateVertexShader() {
	std::string vertexShader =
		"#version 330 core\n"
		"\n"
		"layout (location = 0) in vec3 position;\n"
		"layout (location = 1) in vec3 customColor;\n"
		"layout (location = 2) in vec2 aTexCoord;\n"
		"\n"
		"out vec3 color;\n"
		"out vec2 TexCoord;\n"
		"\n"
		"uniform mat4 transform;\n"
		"uniform mat4 view;\n"
		"uniform mat4 projection;\n"
		"\n"
		"void main()\n"
		"{\n"
		"  color = customColor;\n"
		"  TexCoord = aTexCoord;\n"
		"  gl_Position = projection * view * transform * vec4(position, 1.0);\n"
		"}\n"
		;
	return vertexShader;
}
std::string Renderer::CreateFragmentShader() {
	std::string fragmentShader = 
		"#version 330 core\n"
		"\n"
		"in vec3 color;\n"
		"out vec4 outColor;\n"
		"\n"
		"void main()\n"
		"{\n"
		"outColor=vec4(color, 1.0);\n"
		"}\n"
		;
	return fragmentShader;
}
std::string Renderer::CreateTextureShader() {
	std::string textureShader =
		"#version 330 core\n"
		"out vec4 Texture\n"
		"\n"
		"in vec2 TexCoord;\n"
		"\n"
		"uniform sampler2D ourTexture;\n"
		"\n"
		"void main()\n"
		"{\n"
		"Texture = texture(ourTexture, TexCoord)\n"
		"}\n"
		;
	return textureShader;
}
void Renderer::startProgram(int& shader, glm::mat4 model, glm::mat4 proj, glm::mat4 view) {
	unsigned int transformLoc = glGetUniformLocation(shader, "transform");
	unsigned int projectionLoc = glGetUniformLocation(shader, "projection");
	unsigned int viewLoc = glGetUniformLocation(shader, "view");
	glUseProgram(shader);
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(proj));
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
}
void Renderer::bindVBO(float* vertex, int vertexAmmount) {
	unsigned int vbo;
	int vertexSize = sizeof(vertex) * vertexAmmount;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vertexSize, vertex, GL_STATIC_DRAW);
}
void Renderer::draw(unsigned int shape) {
	int size;
	if (shape == GL_TRIANGLES) {
		size = 3;
		glDrawArrays(GL_TRIANGLES, 0, size);
	}
	else if (shape == GL_QUADS) {
		size = 4;
		glDrawArrays(GL_QUADS, 0, size);
	}
}