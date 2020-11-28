#ifndef CAMERA_H
#define CAMERA_H
#include "export.h"
#include "entity.h"
#include "vec3.hpp"
#include "mat4x4.hpp"
#include "vec4.hpp"

enum ENGINE_API Type {
	orthographic, perspective
};

class ENGINE_API Camera : public Entity {
	Type _type;
	glm::mat4 view;
	glm::mat4 projection;
	int _width;
	int _height;
public:
	Camera(Type type);
	~Camera();
	void setWidth(int width);
	int getWidth();
	void setHeight(int height);
	int getHeight();
	void setViewport(int width, int height);
	void setDefaultView();
	void setProjectionType(Type type);
	Type getType();
	glm::mat4 getView();
	glm::mat4 getProjection();
	void drawCamera(unsigned int& shader);
};
#endif // !CAMERA_H

