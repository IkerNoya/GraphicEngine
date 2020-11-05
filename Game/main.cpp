#include "game.h"
int main() {
	Game* game = new Game();
	//game->executeGame();
	if (game != NULL) {
		game->init();
		game->initGame();
		game->update();
		game->unloadGame();
		game->unload();
	}
	if (game != NULL) {
		delete game;
		game = NULL;
	}
}