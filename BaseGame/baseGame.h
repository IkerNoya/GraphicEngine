#ifndef BASEGAME_H
#define BASEGAME_H
#include <stdlib.h>
#include "GL/glew.h"
#include "GLFW/glfw3.h"
class BaseGame {

public:
	BaseGame();
	~BaseGame();
	int OpenWindow();
};
#endif // !BASEGAME_H

