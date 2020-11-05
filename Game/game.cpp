#include "game.h"

Game::Game() : GameBase(){
	
}

Game::~Game() {

}

int Game::executeGame() {
	//init();
	return 0;
}

void Game::initGame() {
	//shape = new Shape(GL_QUADS, renderer);
	sprite1 = new Sprite(renderer, false, false);
	sprite2 = new Sprite(renderer, false, true);
	sprite3 = new Sprite(renderer, false, true);

	sprite1->setTexture("res/raw/meme.jpg");
	sprite2->setTexture("res/raw/spriteSheet.png");
	sprite3->setTexture("res/raw/Sun.png");
	renderer->setSpriteAttrib(textureShader);
	sprite1->setColor(1, 1, 1);
	sprite2->setColor(1, 1, 1);
	sprite3->setColor(1, 1, 1);
	sprite1->setPosition(0, 0, -1.0f);
	sprite1->setScale(0.5f, 0.5f, 0.5f);
	sprite2->setPosition(0.5f, 0, -1.0f);
	sprite2->setScale(1, 0.2f, 0.5f);
	sprite3->setPosition(0, 0.75f, -1.0f);
	sprite3->setScale(0.25f, 0.25f, 0.5f);
}

void Game::updateGame() {
	sprite1->draw(textureShader, sprite1->getTRS());
	sprite2->draw(textureShader, sprite2->getTRS());
	sprite3->draw(textureShader, sprite3->getTRS());
	/*
	if (input->getKey(D)) {
		x1 += 2 * time->deltaTime();
		sprite1->setPosition(x1, y1, z1);
	}
	if (input->getKey(RIGHT)) {
		x2 += 2 * time->deltaTime();
		sprite2->setPosition(x2, y2, z2);
	}
	if (input->getKey(A)) {
		x1 -= 2 * time->deltaTime();
		sprite1->setPosition(x1, y1, z1);
	}
	if (input->getKey(LEFT)) {
		x2 -= 2 * time->deltaTime();
		sprite2->setPosition(x2, y2, z2);
	}
	if (input->getKey(W)) {
		y1 += 2 * time->deltaTime();
		sprite1->setPosition(x1, y1, z1);
	}
	if (input->getKey(UP)) {
		y2 += 2 * time->deltaTime();
		sprite2->setPosition(x2, y2, z2);
	}
	if (input->getKey(S)) {
		y1 -= 2 * time->deltaTime();
		sprite1->setPosition(x1, y1, z1);
	}
	if (input->getKey(DOWN)) {
		y2 -= 2 * time->deltaTime();
		sprite2->setPosition(x2, y2, z2);
	}
	if (input->getKey(E)) {
		rotate -= 2 * time->deltaTime();
	}
	if (input->getKey(Q)) {
		rotate += 2 * time->deltaTime();
	
	}
	timer += time->deltaTime();
	sprite1->setRotZ(rotate);*/
}

void Game::unloadGame() {
	/*if (shape != NULL) {
		delete shape;
		shape = NULL;
	}*/
	if (sprite1 != NULL) {
		delete sprite1;
		sprite1 = NULL;
	}
	if (sprite2 != NULL) {
		delete sprite2;
		sprite2 = NULL;
	}
	if (sprite3 != NULL) {
		delete sprite3;
		sprite3 = NULL;
	}
}