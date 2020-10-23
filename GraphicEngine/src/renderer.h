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
	void setTextureShader(const std::string& textureShader);
	unsigned int getVertexShader();
	unsigned int getFragmentShader();
	unsigned int compileShader(unsigned int type, const std::string& source);
	int createShader();
	void createVertexAttrib(int program);
	void createColorAttrib(int program);
	std::string CreateVertexShader();
	std::string CreateFragmentShader();
	std::string CreateTextureShader();
	void startProgram(int &shader, glm::mat4 model, glm::mat4 projection, glm::mat4 view);
	void bindVBO(float* vertex, int vertexAmmount);
	void draw(unsigned int shape);
};

#endif // !RENDERER_H