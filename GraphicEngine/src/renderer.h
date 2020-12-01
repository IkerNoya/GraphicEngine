#ifndef RENDERER_H
#define RENDERER_H
#include "export.h"
#include <iostream>
#include "vec3.hpp"
#include "mat4x4.hpp"
#include "vec4.hpp"
#include "shader.h"

class ENGINE_API Renderer {
public:
	Renderer();
	~Renderer();
	void setSpriteAttrib(Shader &shader);
	void setShapeAttrib(Shader& program);
	void createVertexAttrib(unsigned int posAttrib, int dataSize);
	void createColorAttrib(unsigned int colorAttrib, int dataSize);
	void createTextureAttrib(unsigned int colorAttrib, int dataSize);
	void startProgram(Shader &shader, glm::mat4 model);
	void bindSpriteBuffers(unsigned int vbo, unsigned int vao, float* vertex, float size);
	void bindShapeBuffers(unsigned int vbo, unsigned int vao, float* vertex, float size);
	void UnbindBuffers();
	void drawCamera(Shader &shader, glm::mat4 view, glm::mat4 projection, glm::mat4 model);
	void drawShape(unsigned int shape, unsigned int vbo, unsigned int vao, float* vertex, int size,Shader &shader, glm::mat4 trs);
	void drawTexture(unsigned int vbo, unsigned int vao, float* vertex, Shader &shader, glm::mat4 trs);
};

#endif // !RENDERER_H