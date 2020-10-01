#include "GL/glew.h"
#include "renderer.h"
#include <stdlib.h>
#include <iostream>
#include "GLFW/glfw3.h"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"

Renderer::Renderer() {
	
}
Renderer::~Renderer() {
	glDeleteShader(_vertexShader);
	glDeleteShader(_fragmentShader);
}

void Renderer::setVertexShader(const std::string& vertexShader) {
	_vertexShader = compileShader(GL_VERTEX_SHADER, vertexShader);
}
void Renderer::setFragmentShader(const std::string& fragmentShader) {
	_fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentShader);
}
unsigned int Renderer::getVertexShader() {
	return _vertexShader;
}
unsigned int Renderer::getFragmentShader() {
	return _fragmentShader;
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

int Renderer::createShader() {
	unsigned int program = glCreateProgram();
	setVertexShader(CreateVertexShader());
	setFragmentShader(CreateFragmentShader());
	

	glAttachShader(program, _vertexShader);
	glAttachShader(program, _fragmentShader);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(_vertexShader);
	glDeleteShader(_fragmentShader);

	return program;
}
std::string Renderer::CreateVertexShader() {
	std::string vertexShader =
		"#version 330 core\n"
		"\n"
		"layout (location = 0) in vec3 position;\n"
		"in vec3 customColor;\n"
		"out vec3 color;\n"
		"\n"
		"uniform mat4 transform;"
		"\n"
		"void main()\n"
		"{\n"
		"  color = customColor;\n"
		"  gl_Position = transform * vec4(position, 1.0);\n"
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
void Renderer::startProgram(int& shader, glm::mat4 model) {
	unsigned int transformLoc = glGetUniformLocation(shader, "transform");
	glUseProgram(shader);
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(model));
}
void Renderer::bindVBO(float* vertex, int vertexAmmount) {
	unsigned int vbo;
	int vertexSize = sizeof(vertex) * vertexAmmount;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vertexSize, vertex, GL_STATIC_DRAW);
}
void Renderer::DrawTriangle() {
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void Renderer::DrawRectangle() {
	glDrawArrays(GL_QUADS, 0, 4);
}