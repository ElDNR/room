#pragma once

#include "ICamera.h"
#include "Attributes.h"

using namespace room::client::win::attributes;

namespace room::client::win::core {

	class SimpleCamera : public ICamera {

	private:

		const GLfloat PAN_FORWARD_DELTA = 10.01f;
		const GLfloat PAN_BACKWARDS_DELTA = -10.01f;
		const GLfloat ZOOM_FORWARD_DELTA = .01f;
		const GLfloat ZOOM_BACKWARDS_DELTA = -.01f;

		GLfloat _width = 0.0f;
		GLfloat _height = 0.0f;

		GLfloat _zoomModifyer = 1.0f;

		OpenGLPosition _position;

	public:

		SimpleCamera(void);
		SimpleCamera(GLfloat width, GLfloat height);
		~SimpleCamera(void);

		void IncrementX(void);
		void IncrementY(void);
		void IncrementZ(void);

		void DecrementX(void);
		void DecrementY(void);
		void DecrementZ(void);

		void UpdatePosition(GLfloat x, GLfloat y, GLfloat z);

		bool IsInFrame(GLfloat x, GLfloat y, GLfloat z);

		void DrawVertex3f(GLfloat x, GLfloat y, GLfloat z);

	};

}
