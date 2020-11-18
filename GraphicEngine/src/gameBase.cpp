#include "GL/glew.h"
#include "gameBase.h"
#include <stdlib.h>
#include <iostream>
#include "GLFW/glfw3.h"
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"

float timer = 0.0f;
int seconds = 0;

GameBase::GameBase() {
	window = new Window();
	renderer = new Renderer();
	input = new Input();
	collisionmanager = new CollisionManager();

}
GameBase::~GameBase() {
	if (window != NULL) {
		delete window;
		window = NULL;
	}
	if (renderer != NULL) {
		delete renderer;
		renderer = NULL;
	}

	if (input != NULL) {
		delete input;
		input = NULL;
	}
	if (collisionmanager != NULL) {
		delete collisionmanager;
		collisionmanager = NULL;
	}
}

int GameBase::init() {
	window->StartWindow(800, 600, "Graphics Engine");
	if (!window->GetWindow())
	{
		glfwTerminate();
		return -1;
	}
	input->setInputWindow(window->GetWindow());

	glfwMakeContextCurrent(window->GetWindow());
	glViewport(0, 0, 800, 600);
	glewExperimental = GL_TRUE;

	glewInit();
	if (glewInit() != GLEW_OK) {
		std::cout << "Error in Glew Init" << std::endl;
		return 0;
	}
	renderer->setDefaultProjection();
	renderer->setDefaultView();
	glGetIntegerv(GL_CONTEXT_COMPATIBILITY_PROFILE_BIT, nullptr);
	std::cout << glGetString(GL_VERSION) << std::endl;
	textureShader = renderer->createTextureProgram();
	renderer->setSpriteAttrib(textureShader);
	return 0;
}

void GameBase::update() {
	while (!glfwWindowShouldClose(window->GetWindow())) {
		time.tick();
		glClearColor(0.1f, 0.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		updateGame();
		glfwSwapBuffers(window->GetWindow());
		glfwPollEvents();
	}

}
void GameBase::unload() {
	glDeleteProgram(textureShader);
	glfwTerminate();

}
Time& GameBase::getTime() {
	return time;
}

