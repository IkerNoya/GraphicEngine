#ifndef BASEGAME_H
#define BASEGAME_H

#include <iostream>
#include "export.h"
#include "window.h"
#include "renderer.h"

class ENGINE_API GameBase { // consultar
	Window* window;
	Renderer* renderer;
public:
	GameBase();
	~GameBase();
	int compileShader(int type, const std::string& source);
	int createShader(const std::string& vertexShader, const std::string& fragmentShader);
	int init();
};
#endif // !BASEGAME_H