#include "CollisionManager.h"

using namespace room::client::win::attributes;
using namespace room::client::win::managers;

CollisionManager::CollisionManager() {
}

CollisionManager::~CollisionManager() {
}

bool CollisionManager::AddCollision(ICollision* collision) {
	return utilities::AddIntegerIdentifiableToVector(&(this->_collisions), collision);
}

bool CollisionManager::RemoveCollision(ICollision* collision) {
	return utilities::RemoveIntegerIdentifiableToVector(&(this->_collisions), collision);
}

std::vector<ICollision*> CollisionManager::HasCollisions(void) {
	std::vector<ICollision*> result;

	return result;
}

std::vector<ICollision*> CollisionManager::DetectCollisions(GLfloat x, GLfloat y, GLfloat z) {
	std::vector<ICollision*> result;

	return result;
}
