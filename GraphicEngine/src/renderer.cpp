#include "GL/glew.h"
#include "renderer.h"
#include <stdlib.h>
#include <iostream>
#include "GLFW/glfw3.h"
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
unsigned int Renderer::compileShader(GLenum type, const std::string& source) {
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

int Renderer::createShader() {
	unsigned int program = glCreateProgram();
	setVertexShader(CreateVertexShader());
	setFragmentShader(CreateVertexShader());
	

	glAttachShader(program, _vertexShader);
	glAttachShader(program, _fragmentShader);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(_vertexShader);
	glDeleteShader(_fragmentShader);

	unsigned int posAttrib = glGetAttribLocation(program, "position");
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, 0);
	glEnableVertexAttribArray(posAttrib);

	unsigned int colorAttrib = glGetAttribLocation(program, "customColor");
	glVertexAttribPointer(colorAttrib, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)(2 * sizeof(float)));
	glEnableVertexAttribArray(colorAttrib);

	return program;
}
std::string Renderer::CreateVertexShader() {
	std::string vertexShader =
		"#version 330 core\n"
		"\n"
		"in vec2 position;\n"
		"in vec3 customColor;\n"
		"out vec3 color;\n"
		"\n"
		"void main()\n"
		"{\n"
		"  color = customColor;\n"
		"  gl_Position = vec4(position, 0.0, 1.0);\n"
		"}\n"
		;
	return vertexShader;
}
std::string Renderer::CreateFragmentShader() {
	std::string fragmentShader = 
		"#version 330 core\n"
		"\n"
		"in vec3 color;\n"
		"out vec3 outColor;\n"
		"\n"
		"void main()\n"
		"{\n"
		"outColor=vec4(color, 1.0);\n"
		"}\n"
		;
	return fragmentShader;
}

void Renderer::DrawTriangle() {
	glDrawArrays(GL_TRIANGLES, 0, 3);
}