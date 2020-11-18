#include "game.h"

float x1a = 0.0f; 
float y1a = 0.0f; 
float z1a = -1.0f;
float x2b = 0.0f; 
float y2b = 0.0f; 
float z2b = -1.0f;

float timerr = 0.0f; 
//int seconds = 0;
float rotate = 0.0f;

Game::Game() : GameBase(){

	sprite1 = new Sprite(renderer, false, false);
	sprite2 = new Sprite(renderer, true, true);
	sprite3 = new Sprite(renderer, false, true);
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
	sprite2->setPosition(0.5f, 0, -1.0f);
	sprite2->setScale(1, 0.2f, 0.5f);
	sprite3->setPosition(0, 0.75f, -1.0f);
	sprite3->setScale(0.25f, 0.25f, 0.5f);
}

void Game::updateGame() {
	sprite1->draw(textureShader);
	sprite2->draw(textureShader);
	sprite2->updateAnimation(getTime());
	sprite3->draw(textureShader);
	if (input->getKey(D)) {
		x1a += 0.0004f * static_cast<float>(time.deltaTime());
		sprite1->setPosition(x1a, y1a, z1a);
	}
	if (input->getKey(RIGHT)) {
		x2b += 0.0004f * static_cast<float>(time.deltaTime());
		sprite2->setPosition(x2b, y2b, z2b);
	}
	if (input->getKey(A)) {
		x1a -= 0.0004f * static_cast<float>(time.deltaTime());
		sprite1->setPosition(x1a, y1a, z1a);
	}
	if (input->getKey(LEFT)) {
		x2b -= static_cast<float>(0.0004f * time.deltaTime());
		sprite2->setPosition(x2b, y2b, z2b);
	}
	if (input->getKey(W)) {
		y1a += 0.0004f * static_cast<float>(time.deltaTime());
		sprite1->setPosition(x1a, y1a, z1a);
	}
	if (input->getKey(UP)) {
		y2b += 0.0004f * static_cast<float>(time.deltaTime());
		sprite2->setPosition(x2b, y2b, z2b);
	}
	if (input->getKey(S)) {
		y1a -= 0.0004f * static_cast<float>(time.deltaTime());
		sprite1->setPosition(x1a, y1a, z1a);
	}
	if (input->getKey(DOWN)) {
		y2b -= 0.0004f * static_cast<float>(time.deltaTime());
		sprite2->setPosition(x2b, y2b, z2b);
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