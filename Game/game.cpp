#include "game.h"

float speed = 450;

float timerr = 0.0f; 
//int seconds = 0;
float rotate = 0.0f;

Game::Game() : GameBase(){
	shape = new Shape(rectangle, renderer);
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
	shape->init();
	shape->setPosition(300, 300,0);
	shape->setScale(300, 300, 300);
	shape->setColor(1,0.5f, 0);

	sprite1->setTexture("res/raw/meme.jpg");
	sprite2->setTexture("res/raw/spriteSheet.png");
	idle->addFrame(0, 0, 525 / 7, 75, 525, 75, 1.0f, 7, 7);
	sprite2->setAnimation(idle);
	sprite2->SetCurrentAnimationIndex(0);
	sprite3->setTexture("res/raw/Sun.png");
	sprite1->setColor(1, 1, 1);
	sprite2->setColor(1, 1, 1);
	sprite3->setColor(1, 1, 1);
	sprite1->setPosition(300, 300, 0);
	sprite1->setScale(100, 100, 100);
	sprite2->setPosition(window->getWidth()/2, window->getHeight()/2, 0);
	sprite2->setScale(100,100,100);
	sprite3->setPosition(window->getWidth() / 2, 600.0f, 0);
	sprite3->setScale(100,100,100);
}

void Game::updateGame() {
	shape->draw(colorShader);
	sprite1->draw(textureShader);
	sprite2->draw(textureShader);
	sprite2->updateAnimation(getTime());
	sprite3->draw(textureShader);

#pragma region SPRITE_INPUT
	if (input.getKey(D)) {
		sprite2->setPosition(sprite2->transform.position.x + speed * time.deltaTime(), sprite2->transform.position.y, sprite2->transform.position.z);
	}
	if (input.getKey(A)) {
		sprite2->setPosition(sprite2->transform.position.x - speed * time.deltaTime(), sprite2->transform.position.y, sprite2->transform.position.z);
	}
	if (input.getKey(S)) {
		sprite2->setPosition(sprite2->transform.position.x, sprite2->transform.position.y - speed * time.deltaTime(), sprite2->transform.position.z);
	}
	if (input.getKey(W)) {
		sprite2->setPosition(sprite2->transform.position.x, sprite2->transform.position.y + speed * time.deltaTime(), sprite2->transform.position.z);
	}

#pragma endregion

#pragma region SHAPE_INPUT

	if (input.getKey(SPACE)) {
		shape->setColor(1, 0, 0);
	}
	if (input.getKey(RIGHT)) {
		sprite1->setPosition(sprite1->transform.position.x + speed * time.deltaTime(), sprite1->transform.position.y, sprite1->transform.position.z);
	}
	if (input.getKey(LEFT)) {
		sprite1->setPosition(sprite1->transform.position.x - speed * time.deltaTime(), sprite1->transform.position.y, sprite1->transform.position.z);
	}
	if (input.getKey(UP)) {
		sprite1->setPosition(sprite1->transform.position.x, sprite1->transform.position.y + speed * time.deltaTime(), sprite1->transform.position.z);
	}
	if (input.getKey(DOWN)) {
		sprite1->setPosition(sprite1->transform.position.x, sprite1->transform.position.y - speed * time.deltaTime(), sprite1->transform.position.z);
	}
#pragma endregion

	collisionmanager->CheckCollision2D(sprite2, sprite1, speed, speed);
		
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
	if (idle != NULL) {
		delete idle;
	}
}