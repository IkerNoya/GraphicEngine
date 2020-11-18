#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H

#include"entity.h"
#include"vec3.hpp"

class ENGINE_API CollisionManager {
private:
	Entity* _entity;
public:
	CollisionManager();
	~CollisionManager();
	bool CheckCollision2D(Entity* entity1, Entity* entity2, glm::vec3 boxColliderEntity1, glm::vec3 boxColliderEntity2);
};

#endif