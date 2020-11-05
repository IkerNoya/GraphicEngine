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
	unsigned int _posAttrib;
	unsigned int _colorAttrib;
	glm::mat4 view;
	glm::mat4 projection;
public:
	Renderer();
	~Renderer();
	void setVertexShader(const std::string& vertexShader);
	void setFragmentShader(const std::string& fragmentShader);
	void setTextureShader(const std::string& textureShader);
	unsigned int getVertexShader();
	unsigned int getFragmentShader();
	unsigned int getTextureShader();
	void setDefaultView();
	void setDefaultProjection();
	glm::mat4 getView();
	glm::mat4 getProjection();
	unsigned int compileShader(unsigned int type, const std::string& source);
	int createColorProgram();
	int createTextureProgram();
	void setSpriteAttrib(unsigned int& program);
	void createVertexAttrib();
	void createColorAttrib();
	void createTextureAttrib();
	std::string CreateVertexShader();
	std::string CreateFragmentShader();
	std::string CreateTextureShader();
	void startProgram(unsigned int &shader, glm::mat4 model);
	void bindEBO(unsigned int* index, int indexAmmount);
	void bindVAO();
	void bindSpriteBuffers(unsigned int vbo);
	void bindShapeBuffers();
	void UnbindBuffers();
	void draw(unsigned int shape);
	void drawTexture(unsigned int vbo, unsigned int& shader, glm::mat4 trs);
};

#endif // !RENDERER_H