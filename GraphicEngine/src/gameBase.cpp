#include "gameBase.h"
#include <stdlib.h>
#include <string>
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

