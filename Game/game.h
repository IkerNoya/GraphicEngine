#ifndef GAME_H
#define GAME_H
#include "gameBase.h"
class Game : public GameBase{
private:
	Shape* square;
	Sprite* cursedImage;
	Sprite* idleSprite;
	Sprite* sun;
	Animation* idleAnim;

public:
	Game();
	~Game();
	int executeGame();
	void initGame() override;
	void updateGame() override;
	void unloadGame() override;
};
#endif // !GAME_H

