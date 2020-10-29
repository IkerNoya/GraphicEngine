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
	unsigned int _textureShader;
public:
	Renderer();
	~Renderer();
	void setVertexShader(const std::string& vertexShader);
	void setFragmentShader(const std::string& fragmentShader);
	void setTextureShader(const std::string& textureShader);
	unsigned int getVertexShader();
	unsigned int getFragmentShader();
	unsigned int getTextureShader();
	unsigned int compileShader(unsigned int type, const std::string& source);
	int createColorProgram();
	int createTextureProgram();
	void createVertexAttrib(unsigned int &program);
	void createColorAttrib(unsigned int &program);
	void createTextureAttrib(unsigned int &program);
	std::string CreateVertexShader();
	std::string CreateFragmentShader();
	std::string CreateTextureShader();
	void startProgram(unsigned int &shader, glm::mat4 model, glm::mat4 projection, glm::mat4 view);
	void bindVBO(float* vertex, int vertexAmmount);
	void draw(unsigned int shape);
	void drawTexture();
};

#endif // !RENDERER_H