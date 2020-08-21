#ifndef BASEGAME_H
#define BASEGAME_H

#include "export.h"
class ENGINE_API GameBase { // consultar

public:
	GameBase();
	~GameBase();
	int StartWindow(int width, int height, const char* windowName);
};
#endif // !BASEGAME_H

