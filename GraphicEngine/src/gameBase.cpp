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
	window->StartWindow(800, 600, "Graphics Engine");
	return 0;
}