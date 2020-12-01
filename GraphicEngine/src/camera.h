#ifndef CAMERA_H
#define CAMERA_H
#include "export.h"
#include "entity.h"
#include "vec3.hpp"
#include "mat4x4.hpp"
#include "vec4.hpp"
#include "shader.h"

enum ENGINE_API RenderType {
	orthographic, perspective
};

class ENGINE_API Camera : public Entity {
	RenderType _type;
	glm::mat4 view;
	glm::mat4 projection;
	int _width;
	int _height;
public:
	Camera(RenderType type);
	~Camera();
	void setWidth(int width);
	int getWidth();
	void setHeight(int height);
	int getHeight();
	void setViewport(int width, int height);
	void setDefaultView(float x, float y, float z);
	void setProjectionType(RenderType type);
	RenderType getType();
	glm::mat4 getView();
	glm::mat4 getProjection();
	void drawCamera(Shader& shader);
};
#endif // !CAMERA_H

