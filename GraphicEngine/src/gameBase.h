#ifndef BASEGAME_H
#define BASEGAME_H

#include "export.h"
#include "window.h"
#include "renderer.h"
#include "shape.h"
#include "material.h"
#include "input.h"

struct Renderer;
struct Shape;
struct Window;
struct Input;

class ENGINE_API GameBase { // consultar
	Window* window;
	Renderer* renderer;
	Shape* shape;
	Input* input;
public:
	GameBase();
	~GameBase();
	int init();
};
#endif // !BASEGAME_H