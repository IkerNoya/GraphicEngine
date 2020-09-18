#include "GL/glew.h"
#include "gameBase.h"
#include <stdlib.h>
#include <iostream>
#include "GLFW/glfw3.h"

GameBase::GameBase() {
	window = new Window();
	renderer = new Renderer();
	shape = new Shape();
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
	glGetIntegerv(GL_CONTEXT_COMPATIBILITY_PROFILE_BIT, nullptr);
	std::cout << glGetString(GL_VERSION) << std::endl;
	shape->setColor(1.0f,1.0f,0.0f);
	shape->CreateTriangle(-0.5f, -0.5f, 0.5f, -0.5f, 0.0f, 0.5f);

	int shader = renderer->createShader();
	glUseProgram(shader);

	glBindBuffer(GL_ARRAY_BUFFER, 0);


	//Loop until the user closes the window /
	while (!glfwWindowShouldClose(newWindow))
	{
		// Render here /
		glClearColor(0.1f, 0.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		renderer->DrawTriangle();

		// Swap front and back buffers /
		glfwSwapBuffers(newWindow);

		// Poll for and process events */
		glfwPollEvents();
	}
	glDeleteProgram(shader);
	glfwTerminate();
	return 0;
}