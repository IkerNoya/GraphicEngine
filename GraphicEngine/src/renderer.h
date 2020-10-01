#ifndef RENDERER_H
#define RENDERER_H
#include "export.h"
#include <iostream>
#include "vec3.hpp"
#include "mat4x4.hpp"
#include "vec4.hpp"

class ENGINE_API Renderer {
	//unsigned para que no de negativo/errores
	unsigned int _vertexShader;
	unsigned int _fragmentShader;
public:
	Renderer();
	~Renderer();
	void setVertexShader(const std::string& vertexShader);
	void setFragmentShader(const std::string& fragmentShader);
	unsigned int getVertexShader();
	unsigned int getFragmentShader();
	unsigned int compileShader(unsigned int type, const std::string& source);
	int createShader();
	void createVertexAttrib(int program);
	void createColorAttrib(int program);
	std::string CreateVertexShader();
	std::string CreateFragmentShader();
	void startProgram(int &shader, glm::mat4 model);
	void bindVBO(float vertex[15]);
	void DrawTriangle();
	void DrawRectangle(float vertex[20]);
};

#endif // !RENDERER_H