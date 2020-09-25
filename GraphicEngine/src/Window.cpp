#include "window.h"
#include <stdlib.h>
#include <iostream>
#include "GL/glew.h"
#include "GLFW/glfw3.h"

Window::Window() {

}
Window::~Window() {

}
int Window::StartWindow(int width, int height, const char* windowName, GLFWwindow* &window) {
	//Initialize the library /
	if (!glfwInit())
		return -1;

	// Create a windowed mode window and its OpenGL context /
	window = glfwCreateWindow(width, height, windowName, NULL, NULL);
}