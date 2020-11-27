#include "window.h"
#include <stdlib.h>
#include <iostream>
#include "GL/glew.h"
#include "GLFW/glfw3.h"

Window::Window(float width, float height) {
	_width = width;
	_height = height;
}
Window::~Window() {

}
float Window::getWidth() {
	return _width;
}
float Window::getHeight() {
	return _height;
}
int Window::StartWindow(const char* windowName) {
	//Initialize the library /
	if (!glfwInit())
		return -1;

	// Create a windowed mode window and its OpenGL context /
	_window = glfwCreateWindow(_width, _height, windowName, NULL, NULL);
}
GLFWwindow* Window::GetWindow() {
	return _window;
}