#ifndef BASEGAME_H
#define BASEGAME_H

#include "export.h"
#include "window.h"

class ENGINE_API GameBase { // consultar
	Window* window;
public:
	GameBase();
	~GameBase();
	int init();
};
#endif // !BASEGAME_H

