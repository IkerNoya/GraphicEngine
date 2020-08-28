#include "gameBase.h"
#include <stdlib.h>
#include <iostream>
#include "GL/glew.h"
#include "GLFW/glfw3.h"
GameBase::GameBase() {
	window = new Window();
}
GameBase::~GameBase() {
	if (window != NULL)
		delete window;
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

	//Loop until the user closes the window /
	while (!glfwWindowShouldClose(newWindow))
	{
		// Render here /
		glClearColor(0.8f, 1.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Swap front and back buffers /
		glfwSwapBuffers(newWindow);

		// Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}