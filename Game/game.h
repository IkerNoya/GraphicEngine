#ifndef GAME_H
#define GAME_H
#include "gameBase.h"
class Game : public GameBase{

public:
	Game();
	~Game();
	int executeGame();
	void initGame() override;
	void updateGame() override;
	void unloadGame() override;
};
#endif // !GAME_H

