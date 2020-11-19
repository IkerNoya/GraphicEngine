#include "game.h"

float x = 0;
float y = 0;
float z = -1;

float timerr = 0.0f; 
//int seconds = 0;
float rotate = 0.0f;

Game::Game() : GameBase(){

	sprite1 = new Sprite(renderer, false);
	sprite2 = new Sprite(renderer, true);
	sprite3 = new Sprite(renderer, true);
	idle = new Animation();
}

Game::~Game() {

}

int Game::executeGame() {
	//init();
	return 0;
}

void Game::initGame() {
	//shape = new Shape(GL_QUADS, renderer);
	sprite1->setTexture("res/raw/meme.jpg");
	sprite2->setTexture("res/raw/spriteSheet.png");
	idle->addFrame(0, 0, 525 / 7, 75, 525, 75, 1.0f, 7, 7);
	sprite2->setAnimation(idle);
	sprite2->SetCurrentAnimationIndex(0);
	sprite3->setTexture("res/raw/Sun.png");
	renderer->setSpriteAttrib(textureShader);
	sprite1->setColor(1, 1, 1);
	sprite2->setColor(1, 1, 1);
	sprite3->setColor(1, 1, 1);
	sprite1->setPosition(0, 0, -1.0f);
	sprite1->setScale(0.25f, 0.25f, 0.5f);
	sprite2->setPosition(x, y, z);
	sprite3->setPosition(0, 0.75f, -1.0f);
	sprite3->setScale(0.25f, 0.25f, 0.5f);
	sprite2->setScale(0.25f, 0.25f, 0.25f);
}

void Game::updateGame() {
	sprite1->draw(textureShader);
	sprite2->draw(textureShader);
	sprite2->updateAnimation(getTime());
	sprite3->draw(textureShader);
	if (input->getKey(W)) {
		z += 0.0004f;
		sprite2->setPosition(x, y, z);
	}
	if (input->getKey(S)) {
		z -= 0.0004f;
		sprite2->setPosition(x, y, z);
	}
	if (input->getKey(D)) {
		x += 0.0004f;
		sprite2->setPosition(x, y, z);
	}
	if (input->getKey(A)) {
		x -= 0.0004f;
		sprite2->setPosition(x, y, z);
	}
	if (input->getKey(Q)) {
		y -= 0.0004f;
		sprite2->setPosition(x, y, z);
	}
	if (input->getKey(E)) {
		y += 0.0004f;
		sprite2->setPosition(x, y, z);
	}
	if (collisionmanager->CheckCollision2D(sprite1, sprite3,
		sprite1->transform.scale + glm::vec3(0.25f, 0.25f, 0.5f),
		sprite3->transform.scale + glm::vec3(0.25f, 0.25f, 0.5f))) {
	}
}

void Game::unloadGame() {
	if (sprite1 != NULL) {
		delete sprite1;
	}
	if (sprite2 != NULL) {
		delete sprite2;
	}
	if (sprite3 != NULL) {
		delete sprite3;
	}
}