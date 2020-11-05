#ifndef GAME_H
#define GAME_H
#include "gameBase.h"
class Game : public GameBase{
private:
	Sprite* sprite1;
	Sprite* sprite2;
	Sprite* sprite3;
public:
	Game();
	~Game();
	int executeGame();
	void initGame() override;
	void updateGame() override;
	void unloadGame() override;
};
#endif // !GAME_H

