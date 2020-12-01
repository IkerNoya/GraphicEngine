#ifndef BASEGAME_H
#define BASEGAME_H

#include "export.h"
#include "window.h"
#include "renderer.h"
#include "shape.h"
#include "material.h"
#include "sprite.h";
#include "Time.h"
#include "input.h"
#include "collision_manager.h"
#include "camera.h"

struct Renderer;
struct Shape;

struct Window;
struct Input;
struct Sprite;
struct Time;
struct CollisionManager;

class ENGINE_API GameBase { // consultar
protected:
	Window* window;
	Renderer* renderer;
	Time animationTime;
	Time time;
	Input input;
	CollisionManager* collisionmanager;
	Camera* camera;
	Shader textureShader;
	Shader colorShader;
	
	//unsigned int textureShader;
	//unsigned int colorShader;
public:
	GameBase();
	~GameBase();
	int init();
	void update();
	void unload();
	virtual void initGame() = 0;
	virtual void updateGame() = 0;
	virtual void unloadGame() = 0;

	Time& getTime();
};
#endif // !BASEGAME_H