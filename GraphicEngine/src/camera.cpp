#include "camera.h"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"

Camera::Camera(Type type):Entity(Entity::_renderer) {
	_type = type;
	view = glm::mat4(1.0f);
	projection = glm::mat4(1.0f);
}
Camera::~Camera() {
}
void Camera::setDefaultView() {
	//                                 pos                        direction                          up
	view = glm::lookAt(glm::vec3(transform.position.x, transform.position.y, transform.position.y), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
}
void Camera::setProjectionType(Type type) {
	_type = type;
	switch (type)
	{
	case orthographic:
		//                      x      width   y    height   near   far
		projection = glm::ortho(0.0f, 1280.0f, 0.0f, 720.0f, 0.1f, 10.0f);
		break;

	case perspective:
		//                               FOV              Aspect      near  front
		projection = glm::perspective(glm::radians(90.0f), 1280.0f / 720.0f, 0.1f, 100.0f);
		break;

	default:
		break;
	}
}
Type Camera::getType() {
	return _type;
}
void Camera::drawCamera(unsigned int& shader) {
	_renderer->drawCamera(shader, view, projection, getTRS());
}