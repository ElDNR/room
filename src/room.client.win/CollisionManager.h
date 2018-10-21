#pragma once

#include "ICollisionManager.h"
#include "IdentifierUtils.h"

using namespace room::client::win;

namespace room::client::win::managers
{

	class CollisionManager : public ICollisionManager
	{

	private:

		std::vector<IIntegerIdentifiable*> _collisions;

	public:

		CollisionManager();
		~CollisionManager();

		bool AddCollision(ICollision* collision);
		bool RemoveCollision(ICollision* collision);

		std::vector<ICollision*> HasCollisions(void);
		std::vector<ICollision*> DetectCollisions(GLfloat x, GLfloat y, GLfloat z);

	};

}
