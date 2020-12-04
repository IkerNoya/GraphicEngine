#include "game.h"

float speed = 450;
float timerr = 0.0f; 
float rotate = 0.0f;

Game::Game() : GameBase(){
	square = new Shape(rectangle, renderer);
	cursedImage = new Sprite(renderer, false);
	idleSprite = new Sprite(renderer, true);
	sun = new Sprite(renderer, true);
	idleAnim = new Animation();
}

Game::~Game() {

}

int Game::executeGame() {
	return 0;
}

void Game::initGame() {
	square->init();
	square->setPosition(300, 300,0);
	square->setScale(300, 300, 300);
	square->setColor(1,0.5f, 0);

	cursedImage->setTexture("res/raw/meme.jpg");
	idleSprite->setTexture("res/raw/spriteSheet.png");
	sun->setTexture("res/raw/Sun.png");

	idleAnim->addFrame(0, 0, 525 / 7, 75, 525, 75, 1.0f, 7, 7);
	idleSprite->setAnimation(idleAnim);
	idleSprite->SetCurrentAnimationIndex(0);

	cursedImage->setColor(1, 1, 1);
	idleSprite->setColor(1, 1, 1);
	sun->setColor(1, 1, 1);

	cursedImage->setPosition(300, 300, 0);
	idleSprite->setPosition(window->getWidth()/2, window->getHeight()/2, 0);
	sun->setPosition(window->getWidth() / 2, 600.0f, 0);

	cursedImage->setScale(100, 100, 100);
	idleSprite->setScale(100,100,100);
	sun->setScale(100,100,100);
}

void Game::updateGame() {
	square->draw(colorProgram);
	cursedImage->draw(textureProgram);
	idleSprite->draw(textureProgram);
	idleSprite->updateAnimation(getTime());
	sun->draw(textureProgram);

#pragma region SPRITE_INPUT
	if (input.getKey(D)) {
		idleSprite->setPosition(idleSprite->transform.position.x + speed * time.deltaTime(), idleSprite->transform.position.y, idleSprite->transform.position.z);
	}
	if (input.getKey(A)) {
		idleSprite->setPosition(idleSprite->transform.position.x - speed * time.deltaTime(), idleSprite->transform.position.y, idleSprite->transform.position.z);
	}
	if (input.getKey(S)) {
		idleSprite->setPosition(idleSprite->transform.position.x, idleSprite->transform.position.y - speed * time.deltaTime(), idleSprite->transform.position.z);
	}
	if (input.getKey(W)) {
		idleSprite->setPosition(idleSprite->transform.position.x, idleSprite->transform.position.y + speed * time.deltaTime(), idleSprite->transform.position.z);
	}

#pragma endregion

#pragma region SHAPE_INPUT

	if (input.getKey(SPACE)) {
		sun->setColor(1, 0, 0);
	}
	if (input.getKey(RIGHT)) {
		sun->setPosition(sun->transform.position.x + speed * time.deltaTime(), sun->transform.position.y, sun->transform.position.z);
	}
	if (input.getKey(LEFT)) {
		sun->setPosition(sun->transform.position.x - speed * time.deltaTime(), sun->transform.position.y, sun->transform.position.z);
	}
	if (input.getKey(UP)) {
		sun->setPosition(sun->transform.position.x, sun->transform.position.y + speed * time.deltaTime(), sun->transform.position.z);
	}
	if (input.getKey(DOWN)) {
		sun->setPosition(sun->transform.position.x, sun->transform.position.y - speed * time.deltaTime(), sun->transform.position.z);
	}
#pragma endregion

	collisionmanager->CheckCollision2D(idleSprite, cursedImage, speed * time.deltaTime());
		
}

void Game::unloadGame() {
	if (cursedImage != NULL) {
		delete cursedImage;
	}
	if (idleSprite != NULL) {
		delete idleSprite;
	}
	if (sun != NULL) {
		delete sun;
	}
	if (idleAnim != NULL) {
		delete idleAnim;
	}
	if (square != NULL) {
		delete square;
	}
}