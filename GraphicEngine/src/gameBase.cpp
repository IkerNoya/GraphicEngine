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
	sprite1 = new Sprite(renderer);
	sprite2 = new Sprite(renderer);
	time = new Time();
}
GameBase::~GameBase() {
	if (window != NULL)
		delete window;
	if (renderer != NULL)
		delete renderer;
	if (shape != NULL)
		delete shape;
	if (sprite1 != NULL)
		delete sprite1;
	if (sprite1 != NULL)
		delete sprite2;
	if (time != NULL) {
		delete time;
	}
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
	glViewport(0, 0, 800, 600);
	glewExperimental = GL_TRUE;

	glewInit();
	if (glewInit() != GLEW_OK) {
		std::cout << "Error in Glew Init" << std::endl;
		return 0;
	}
	/*shape->setColor(1.0f, 1.0f, 0.0f);
	shape->init();*/
	glm::vec4 vec(1.0f, 0.0f, 0.0f, 1.0f);
	glm::mat4 trans = sprite1->getTRS();
	renderer->setDefaultProjection();
	renderer->setDefaultView();
	vec = trans * vec;
	glGetIntegerv(GL_CONTEXT_COMPATIBILITY_PROFILE_BIT, nullptr);
	std::cout << glGetString(GL_VERSION) << std::endl;
	unsigned int shader = renderer->createTextureProgram();
	//sprite1->setColor(1, 1, 1);
	sprite1->setTexture("res/raw/meme.jpg");
	sprite2->setTexture("res/raw/prueba.jpg");
	//sprite2->setColor(1, 1, 1);
	renderer->setSpriteAttrib(shader);
	sprite1->setPosition(0, 0, -1.0f);
	sprite2->setPosition(0.5f, 0, -1.0f);
	float rotate = 0;
	float x = 0; float y = 0; float z = -1;
	float timer = 0; int seconds = 0;
	while (!glfwWindowShouldClose(newWindow))
	{
		time->tick();
		time->reset();
		if (timer >= 1) {
			seconds++;
			std::cout << seconds << std::endl;
			timer = 0;
		}
		glClearColor(0.1f, 0.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		//renderer->draw(shape->getType());
		sprite1->draw(shader, sprite1->getTRS());
		sprite2->draw(shader, sprite2->getTRS());
		sprite2->bindTexture();
		sprite1->bindTexture();
		// Swap front and back buffers /
		glfwSwapBuffers(newWindow);
		if (glfwGetKey(newWindow, GLFW_KEY_RIGHT) == GLFW_PRESS) {
			x += 2 * time->deltaTime();
			sprite1->setPosition(x, y, z);
		}
		if (glfwGetKey(newWindow, GLFW_KEY_LEFT) == GLFW_PRESS) {
			x -= 2 * time->deltaTime();
			sprite1->setPosition(x, y, z);
		}
		if (glfwGetKey(newWindow, GLFW_KEY_UP) == GLFW_PRESS) {
			y += 2 * time->deltaTime();
			sprite1->setPosition(x, y, z);
		}
		if (glfwGetKey(newWindow, GLFW_KEY_DOWN) == GLFW_PRESS) {
			y -= 2 * time->deltaTime();
			sprite1->setPosition(x, y, z);
		}
		if (glfwGetKey(newWindow, GLFW_KEY_E) == GLFW_PRESS) {
			rotate -= 2 * time->deltaTime();
		}
		if (glfwGetKey(newWindow, GLFW_KEY_Q) == GLFW_PRESS) {
			rotate += 2 * time->deltaTime();
		}
		timer += time->deltaTime();
		sprite1->setRotZ(rotate);
		glfwPollEvents();
	}
	glDeleteProgram(shader);
	glfwTerminate();
	return 0;
}