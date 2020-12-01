#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "shader.h"
#include <fstream>
#include <sstream>
Shader::Shader() {

}

Shader::~Shader() {

}

void Shader::CreateShader(const char* vertexPath, const char* fragmentPath) {
	string vertexCode;
	string fragmentCode;
	ifstream vertexFile;
	stringstream vertexCodeBuffer;
	stringstream fragmentCodeBuffer;
	vertexFile.open(vertexPath);
	if (vertexFile.is_open()) {
		vertexCodeBuffer << vertexFile.rdbuf();
		vertexFile.close();
	}
	else {
		cout << "Couln't open vertex file" << endl;
	}
	ifstream fragmentFile;
	fragmentFile.open(fragmentPath);
	if (fragmentFile.is_open()) {
		fragmentCodeBuffer << fragmentFile.rdbuf();
		fragmentFile.close();
	}
	else {
		cout << "Couln't open fragment file" << endl;
	}
	vertexCode = vertexCodeBuffer.str();
	fragmentCode = fragmentCodeBuffer.str();
	//-----------------------compile-----------------------------------------

	id = glCreateProgram();

	unsigned int vertexId = compileShader(GL_VERTEX_SHADER, vertexCode);
	unsigned int fragmentId = compileShader(GL_FRAGMENT_SHADER, fragmentCode);

	glAttachShader(id, vertexId);
	glAttachShader(id, fragmentId);

	glLinkProgram(id);
	glValidateProgram(id);

	glDeleteShader(vertexId);
	glDeleteShader(fragmentId);
}

unsigned int Shader::getId() {
	return id;
}
void Shader::use() {
	glUseProgram(id);
}

unsigned int Shader::compileShader(unsigned int type, string& source) {
	unsigned int shaderId = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(shaderId, 1, &src, nullptr);
	glCompileShader(shaderId);

	int result;
	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &result);

	if (result == GL_FALSE) {
		int length;
		glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)_malloca(length * sizeof(char));
		glGetShaderInfoLog(shaderId, length, &length, message);
		std::cout << "Failed to compile" << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << "shader" << std::endl;
		std::cout << message << std::endl;
		glDeleteShader(shaderId);
		return 0;
	}
	return shaderId;
}