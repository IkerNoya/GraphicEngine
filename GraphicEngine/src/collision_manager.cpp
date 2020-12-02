#include "collision_manager.h"

CollisionManager::CollisionManager() {

}

CollisionManager::~CollisionManager() {

}

collisionPosition CollisionManager::partialCollision(Entity* entity, Entity* obstacle) {
	glm::vec2 entityScale(entity->transform.scale.x, entity->transform.scale.y);
	glm::vec2 obstacleScale(obstacle->transform.scale.x, obstacle->transform.scale.y);
	float maxOverlappX = glm::min(entity->transform.position.x + fabs(entityScale.x) / 2.0f, obstacle->transform.position.x + fabs(obstacleScale.x) / 2.0f) - glm::max(entity->transform.position.x - fabs(entityScale.x) / 2.0f, obstacle->transform.position.x - fabs(obstacleScale.x) / 2.0f);
	float xOverlapp = glm::max(0.0f, maxOverlappX);
	float maxOverlappY = glm::min(entity->transform.position.y + fabs(entityScale.y) / 2.0f, obstacle->transform.position.y + fabs(obstacleScale.y) / 2.0f) - glm::max(entity->transform.position.y - fabs(entityScale.y) / 2.0f, obstacle->transform.position.y - fabs(obstacleScale.y) / 2.0f);
	float yOverlapp = glm::max(0.0f, maxOverlappY);
	if (xOverlapp != 0 && yOverlapp != 0) {
		if (xOverlapp > yOverlapp) {
			if (entity->transform.position.y - (entityScale.y/2) >= obstacle->transform.position.y + (obstacleScale.y/2)) cout << "top" << endl; return topCollision;
			if (entity->transform.position.y <= obstacle->transform.position.y - obstacleScale.y)  cout << "bottom" << endl; return bottomCollision;
		}
		else {
			if (entity->transform.position.x >= obstacle->transform.position.x + obstacleScale.x) cout << "right" << endl; return rightCollision;
			if (entity->transform.position.x + entityScale.x <= obstacle->transform.position.x) cout << "left" << endl; return leftCollision;
		}
	}
	//cout << xOverlapp << " " << yOverlapp << endl;
	return none;
}

bool CollisionManager::CheckTrigger2D(Entity* entity1, Entity* entity2) {
	bool collisionX = entity1->transform.position.x + (entity1->transform.scale.x/2) >= entity2->transform.position.x - (entity2->transform.scale.x) &&
		entity2->transform.position.x + (entity2->transform.scale.x/2) >= entity1->transform.position.x - (entity1->transform.scale.x);

	bool collisionY = entity1->transform.position.y + (entity1->transform.scale.y) >= entity2->transform.position.y - (entity2->transform.scale.y) &&
		entity2->transform.position.y + (entity2->transform.scale.y/2) >= entity1->transform.position.y - (entity1->transform.scale.y);

	return collisionX && collisionY;
}

bool CollisionManager::CheckCollision2D(Entity* entity1, Entity* entity2) {
	collisionPosition cPosition = partialCollision(entity1, entity2);
	switch (cPosition)
	{
	case none:
		break;
	case topCollision:
		break;
	case rightCollision:
		break;
	case bottomCollision:
		break;
	case leftCollision:
		break;
	default:
		break;
	}
	return false;
}