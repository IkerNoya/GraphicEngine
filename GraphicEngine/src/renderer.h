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
	//glm::mat4 view;
	//glm::mat4 projection;

public:
	Renderer();
	~Renderer();
	void setVertexShader(const std::string& vertexShader);
	void setFragmentShader(const std::string& fragmentShader);
	void setTextureShader(const std::string& textureShader);
	unsigned int getVertexShader();
	unsigned int getFragmentShader();
	unsigned int getTextureShader();
	void setDefaultView(glm::mat4 view);
	void setDefaultProjection(glm::mat4 projection);
	/*glm::mat4 getView();
	glm::mat4 getProjection();*/
	unsigned int compileShader(unsigned int type, const std::string& source);
	int createColorProgram();
	int createTextureProgram();
	void setSpriteAttrib(unsigned int& program);
	void setShapeAttrib(unsigned int& program);
	void createVertexAttrib(unsigned int posAttrib, int dataSize);
	void createColorAttrib(unsigned int colorAttrib, int dataSize);
	void createTextureAttrib(unsigned int colorAttrib, int dataSize);
	std::string CreateVertexShader();
	std::string CreateFragmentShader();
	std::string CreateTextureShader();
	void startProgram(unsigned int &shader, glm::mat4 model);
	void bindSpriteBuffers(unsigned int vbo, unsigned int vao, float* vertex, float size);
	void bindShapeBuffers(unsigned int vbo);
	void UnbindBuffers();
	void drawCamera(unsigned int& shader, glm::mat4 view, glm::mat4 projection, glm::mat4 model);
	void drawShape(unsigned int shape, unsigned int vbo, unsigned int& shader, glm::mat4 trs);
	void drawTexture(unsigned int vbo, unsigned int vao, float* vertex, unsigned int& shader, glm::mat4 trs);
};

#endif // !RENDERER_H