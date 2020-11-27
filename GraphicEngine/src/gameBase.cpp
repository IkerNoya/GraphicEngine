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
	window = new Window(1280.0f, 720.0f);
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
	window->StartWindow("Graphics Engine");
	if (!window->GetWindow())
	{
		glfwTerminate();
		return -1;
	}
	input->setInputWindow(window->GetWindow());

	glfwMakeContextCurrent(window->GetWindow());
	glViewport(0, 0, 1280, 720);
	glewExperimental = GL_TRUE;

	glewInit();
	if (glewInit() != GLEW_OK) {
		std::cout << "Error in Glew Init" << std::endl;
		return 0;
	}
	glGetIntegerv(GL_CONTEXT_COMPATIBILITY_PROFILE_BIT, nullptr);
	std::cout << glGetString(GL_VERSION) << std::endl;
	renderer->setDefaultView();
	renderer->setDefaultProjection();
	glm::mat4 model = glm::mat4(1.0f);
	textureShader = renderer->createTextureProgram();
	renderer->drawCamera(textureShader, renderer->getView(), renderer->getProjection(), model);
	renderer->setSpriteAttrib(textureShader);
	return 0;
}

void GameBase::update() {
	while (!glfwWindowShouldClose(window->GetWindow())) {
		animationTime.tick();
		time.tick();
		time.reset();
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
	return animationTime;
}

