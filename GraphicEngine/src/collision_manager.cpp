#include "collision_manager.h"

CollisionManager::CollisionManager() {

}

CollisionManager::~CollisionManager() {

}

bool CollisionManager::CheckCollision2D(Entity* entity1, Entity* entity2, glm::vec3 boxColliderEntity1, glm::vec3 boxColliderEntity2) {
	if (entity1->transform.position.x + boxColliderEntity1.x >= entity2->transform.position.x &&
		entity2->transform.position.x + boxColliderEntity2.x >= entity1->transform.position.x &&
		entity1->transform.position.y + boxColliderEntity1.y >= entity2->transform.position.y &&
		entity2->transform.position.y + boxColliderEntity2.y >= entity1->transform.position.y) {
		return true;
	}

	return false;
	/*bool collisionX = entity1->transform.position.x + entity1->transform.scale.x >= entity2->transform.position.x &&
		entity2->transform.position.x + entity2->transform.scale.x >= entity1->transform.position.x;

	bool collisionY = entity1->transform.position.y + entity1->transform.scale.y >= entity2->transform.position.y &&
		entity2->transform.position.y + entity2->transform.scale.y >= entity1->transform.position.y;*/

	//return collisionX && collisionY;
}