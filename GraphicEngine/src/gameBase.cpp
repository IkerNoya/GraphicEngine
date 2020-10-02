#include "GL/glew.h"
#include "gameBase.h"
#include <stdlib.h>
#include <iostream>
#include "GLFW/glfw3.h"
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"


GameBase::GameBase() {
	window = new Window();
	renderer = new Renderer();
	shape = new Shape(GL_TRIANGLES, renderer);
}
GameBase::~GameBase() {
	if (window != NULL)
		delete window;
	if (renderer != NULL)
		delete renderer;
	if (shape != NULL)
		delete shape;
}

int GameBase::init() {
	GLFWwindow* newWindow;

	window->StartWindow(800, 600, "Graphics Engine", newWindow);
	if (!newWindow)
	{
		glfwTerminate();
		return -1;
	}

	// Make the window's context current /
	glfwMakeContextCurrent(newWindow);

	glewExperimental = GL_TRUE;

	glewInit();
	if (glewInit() != GLEW_OK) {
		std::cout << "Error in Glew Init" << std::endl;
		return 0;
	}
	shape->setColor(1.0f, 1.0f, 0.0f);
	shape->init();
	glm::vec4 vec(1.0f, 0.0f, 0.0f, 1.0f);
	glm::mat4 trans = shape->getTRS();
	glm::mat4 proj = glm::mat4(1.0f);
	glm::mat4 ViewMatrix = glm::mat4(1.0f);
	//                               FOV              Aspect      near  front
	proj = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
	//                                 pos                        direction                          up
	ViewMatrix = glm::lookAt(glm::vec3(0.0f,0.0f,1.0f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	vec = trans * vec;
	glGetIntegerv(GL_CONTEXT_COMPATIBILITY_PROFILE_BIT, nullptr);
	std::cout << glGetString(GL_VERSION) << std::endl;
	int shader = renderer->createShader();

	renderer->createVertexAttrib(shader);
	renderer->createColorAttrib(shader);
	shape->setPosition(0, 0, -1.0f);
	
	float rotate = 0;
	float x = 0; float y = 0; float z = -1;
	//Loop until the user closes the window /
	while (!glfwWindowShouldClose(newWindow))
	{
		// Render here /
		glClearColor(0.1f, 0.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		renderer->startProgram(shader, shape->getTRS(), proj, ViewMatrix);
		renderer->draw(shape->getType());
		// Swap front and back buffers /
		glfwSwapBuffers(newWindow);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		if (glfwGetKey(newWindow, GLFW_KEY_RIGHT) == GLFW_PRESS) {
			x += 0.02f;
			shape->setPosition(x, y, z);
		}
		if (glfwGetKey(newWindow, GLFW_KEY_LEFT) == GLFW_PRESS) {
			x -= 0.02f;
			shape->setPosition(x, y, z);
		}
		if (glfwGetKey(newWindow, GLFW_KEY_UP) == GLFW_PRESS) {
			y += 0.02f;
			shape->setPosition(x, y, z);
		}
		if (glfwGetKey(newWindow, GLFW_KEY_DOWN) == GLFW_PRESS) {
			y -= 0.02f;
			shape->setPosition(x, y, z);
		}
		if (glfwGetKey(newWindow, GLFW_KEY_E) == GLFW_PRESS) {
			rotate -= 0.04f;
		}
		if (glfwGetKey(newWindow, GLFW_KEY_Q) == GLFW_PRESS) {
			rotate += 0.04f;
		}
		shape->setRotZ(rotate);
		glfwPollEvents();
	}
	glDeleteProgram(shader);
	glfwTerminate();
	return 0;
}