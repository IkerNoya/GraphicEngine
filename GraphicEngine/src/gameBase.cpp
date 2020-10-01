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
	shape->setColor(1.0f, 1.0f, 0.0f);
	shape->initTriangleVertex();
	glm::vec4 vec(1.0f, 0.0f, 0.0f, 1.0f);
	glm::mat4 trans = shape->getTRS();
	vec = trans * vec;
	glGetIntegerv(GL_CONTEXT_COMPATIBILITY_PROFILE_BIT, nullptr);
	std::cout << glGetString(GL_VERSION) << std::endl;
	int shader = renderer->createShader();

	renderer->createVertexAttrib(shader);
	renderer->createColorAttrib(shader);
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	float a = 0;
	float rotate = 0;
	float scale = 1;
	//Loop until the user closes the window /
	while (!glfwWindowShouldClose(newWindow))
	{
		// Render here /
		glClearColor(0.1f, 0.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		renderer->startProgram(shader, shape->getTRS());
		shape->setPosition(a, 0.0f, 0.0f);
		shape->setRotZ(rotate);
		shape->setScale(scale, scale, 1);
		renderer->DrawTriangle();

		// Swap front and back buffers /
		glfwSwapBuffers(newWindow);

		// Poll for and process events */
		if (a < 1.5f)
			a += 0.01f;
		else
			a = -1.5f;
		rotate -= 0.05f;
		if (scale <= 1 && scale >= 0.1f )
			scale -= 0.005f;
		std::cout << scale << std::endl;
		glfwPollEvents();
	}
	glDeleteProgram(shader);
	glfwTerminate();
	return 0;
}