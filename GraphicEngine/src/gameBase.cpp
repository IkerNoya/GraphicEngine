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
	input = new Input();
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
	input->setInputWindow(newWindow);

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
	sprite1->setScale(0.5f, 0.5f, 0.5f);
	sprite2->setScale(0.5f, 0.5f, 0.5f);
	float rotate = 0;
	float x1 = 0; float y1 = 0; float z1 = -1;
	float x2 = 0; float y2 = 0; float z2 = -1;
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
		if (input->getKey(D)) {
			x1 += 2 * time->deltaTime();
			sprite1->setPosition(x1, y1, z1);
		}
		if (input->getKey(L)) {
			x2 += 2 * time->deltaTime();
			sprite2->setPosition(x2, y2, z2);
		}
		if (input->getKey(A)) {
			x1 -= 2 * time->deltaTime();
			sprite1->setPosition(x1, y1, z1);
		}
		if (input->getKey(J)) {
			x2 -= 2 * time->deltaTime();
			sprite2->setPosition(x2, y2, z2);
		}
		if (input->getKey(W)) {
			y1 += 2 * time->deltaTime();
			sprite1->setPosition(x1, y1, z1);
		}
		if (input->getKey(I)) {
			y2 += 2 * time->deltaTime();
			sprite2->setPosition(x2, y2, z2);
		}
		if (input->getKey(S)) {
			y1 -= 2 * time->deltaTime();
			sprite1->setPosition(x1, y1, z1);
		}
		if (input->getKey(K)) {
			y2 -= 2 * time->deltaTime();
			sprite2->setPosition(x2, y2, z2);
		}
		if (input->getKey(E)) {
			rotate -= 2 * time->deltaTime();
		}
		if (input->getKey(Q)) {
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