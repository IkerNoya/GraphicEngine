#include "GL/glew.h"
#include "camera.h"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"
#include "shader.h"

Camera::Camera(RenderType type):Entity(Entity::_renderer) {
	_type = type;
	view = glm::mat4(1.0f);
	projection = glm::mat4(1.0f);
	_width = 800;
	_height = 600;
}
Camera::~Camera() {
}

void Camera::setWidth(int width) {
	_width = width;
}
int Camera::getWidth() {
	return _width;
}
void Camera::setHeight(int height) {
	_height = height;
}
int Camera::getHeight() {
	return _height;
}

void Camera::setViewport(int width, int height) {
	setWidth(width);
	setHeight(height);
	glViewport(0, 0, width, height);
}

void Camera::setDefaultView(float x, float y, float z) {
	//                                 pos                        direction                          up
	view = glm::lookAt(glm::vec3(x,y,z), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	std::cout << "x: " << x << std::endl;
	std::cout << "y: " << y << std::endl;
	std::cout << "z: " << z << std::endl;
}

void Camera::setProjectionType(RenderType type) {
	_type = type;
	switch (type)
	{
	case orthographic:
		//                       x                 width           y               height            near   far
		projection = glm::ortho(0.0f, static_cast<float>(_width), 0.0f, static_cast<float>(_height), 0.1f, 100.0f);
		break;

	case perspective:
		//                               FOV                                        Aspect                            near  front
		projection = glm::perspective(glm::radians(45.0f), static_cast<float>(_width) / static_cast<float>(_height), 0.1f, 100.0f);
		break;

	default:
		break;
	}
}
RenderType Camera::getType() {
	return _type;
}
glm::mat4 Camera::getView() {
	return view;
}
glm::mat4 Camera::getProjection() {
	return projection;
}
void Camera::drawCamera(Shader& shader) {
	_renderer->drawCamera(shader, view, projection, getTRS());
}