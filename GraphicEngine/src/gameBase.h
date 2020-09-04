#ifndef BASEGAME_H
#define BASEGAME_H

#include "export.h"
#include "window.h"
#include "renderer.h"

class ENGINE_API GameBase { // consultar
	Window* window;
	Renderer* renderer;
public:
	GameBase();
	~GameBase();
	int compileShader(int type, const char*& source);
	int createShader(const GLchar*& vertexShader, const GLchar*& fragmentShader);
	int init();
};
#endif // !BASEGAME_H