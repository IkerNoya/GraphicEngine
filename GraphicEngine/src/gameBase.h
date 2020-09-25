#ifndef BASEGAME_H
#define BASEGAME_H

#include "export.h"
#include "window.h"
#include "renderer.h"
#include "shape.h"

struct Renderer;
struct Shape;
struct Window;

class ENGINE_API GameBase { // consultar
	Window* window;
	Renderer* renderer;
	Shape* shape;
public:
	GameBase();
	~GameBase();
	int init();
};
#endif // !BASEGAME_H