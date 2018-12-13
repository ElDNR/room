#pragma once

#include "Attributes.h"

namespace room::client::win::core {

	class ICamera {

	public:

		virtual void IncrementX(void) = 0;
		virtual void IncrementY(void) = 0;
		virtual void IncrementZ(void) = 0;

		virtual void DecrementX(void) = 0;
		virtual void DecrementY(void) = 0;
		virtual void DecrementZ(void) = 0;

		virtual void UpdatePosition(GLfloat x, GLfloat y, GLfloat z) = 0;

		virtual bool IsInFrame(GLfloat x, GLfloat y, GLfloat z) = 0;

		virtual void DrawVertex3f(GLfloat x, GLfloat y, GLfloat z) = 0;

	};

}
