#pragma once

#include "Attributes.h"
#include "ICollision.h"

using namespace room::client::win::attributes;

namespace room::client::win::collisions {

	class BoxCollision : public ICollision {

	private:

		bool _hasCollision;

	public:

		BoxCollision(OpenGLPosition position, GLfloat width, GLfloat height, GLfloat depth);
		~BoxCollision();

	};

}
