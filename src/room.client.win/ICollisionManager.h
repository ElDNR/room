#pragma once

#include "Core.h"
#include "Collisions.h"

using namespace room::client::win::core;
using namespace room::client::win::collisions;

namespace room::client::win::managers
{

	class ICollisionManager
	{

	public:

		virtual bool AddCollision(ICollision* collision) = 0;
		virtual bool RemoveCollision(ICollision* collision) = 0;

		virtual std::vector<ICollision*> HasCollisions(void) = 0;
		virtual std::vector<ICollision*> DetectCollisions(GLfloat x, GLfloat y, GLfloat z) = 0;

	};

}
