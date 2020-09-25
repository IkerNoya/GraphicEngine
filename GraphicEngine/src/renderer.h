#ifndef RENDERER_H
#define RENDERER_H
#include "export.h"
#include <iostream>
#include "GL/glew.h"
#include "GLFW/glfw3.h"
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
	unsigned int compileShader(GLenum type, const std::string& source);
	int createShader();
	std::string CreateVertexShader();
	std::string CreateFragmentShader();
	void DrawTriangle();
	void DrawRectangle();
};

#endif // !RENDERER_H