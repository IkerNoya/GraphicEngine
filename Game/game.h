#ifndef GAME_H
#define GAME_H
#include "gameBase.h"
class Game : public GameBase{

public:
	Game();
	~Game();
	int executeGame();
};
#endif // !GAME_H

