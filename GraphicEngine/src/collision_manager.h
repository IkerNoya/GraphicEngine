#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H

#include"entity.h"
#include"vec3.hpp"
enum ENGINE_API collisionPosition {
	none, topCollision, rightCollision, bottomCollision, leftCollision
};
class ENGINE_API CollisionManager {
	
private:
	Entity* _entity;
	collisionPosition partialCollision(Entity* entity, Entity* obstacle);
public:
	CollisionManager();
	~CollisionManager();
	bool CheckTrigger2D(Entity* entity1, Entity* entity2);
	bool CheckCollision2D(Entity* entity1, Entity* entity2, float speedEntity1);
};

#endif