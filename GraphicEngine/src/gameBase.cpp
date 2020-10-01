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
	shape = new Shape(GL_QUADS, renderer);
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
	if (!window)
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
	vec = trans * vec;
	glGetIntegerv(GL_CONTEXT_COMPATIBILITY_PROFILE_BIT, nullptr);
	std::cout << glGetString(GL_VERSION) << std::endl;
	int shader = renderer->createShader();

	renderer->createVertexAttrib(shader);
	renderer->createColorAttrib(shader);
	
	float rotate = 0;
	//Loop until the user closes the window /
	while (!glfwWindowShouldClose(newWindow))
	{
		// Render here /
		glClearColor(0.1f, 0.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		renderer->startProgram(shader, shape->getTRS());
		shape->setPosition(0.0f, 0.0f, 0.0f);
		shape->setRotZ(rotate);
		renderer->draw(shape->getType());
		// Swap front and back buffers /
		glfwSwapBuffers(newWindow);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		// Poll for and process events */
		rotate -= 0.05f;
		glfwPollEvents();
	}
	glDeleteProgram(shader);
	glfwTerminate();
	return 0;
}