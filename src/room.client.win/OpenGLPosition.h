#pragma once

#include "GL\glew.h"
#include "GL\freeglut.h"

namespace room::client::win::attributes
{

	class OpenGLPosition
	{

	private:

		bool _hasBounds = false;

		GLfloat _x = 0.0f;
		GLfloat _y = 0.0f;
		GLfloat _z = 0.0f;

		GLfloat _minX = 0.0f;
		GLfloat _minY = 0.0f;
		GLfloat _minZ = 0.0f;

		GLfloat _maxX = 0.0f;
		GLfloat _maxY = 0.0f;
		GLfloat _maxZ = 0.0f;

		GLfloat _pitch = 0.0f;
		GLfloat _yaw = 0.0f;
		GLfloat _roll = 0.0f;

		bool UpdateValue(GLfloat* valuePtr, GLfloat delta, GLfloat min, GLfloat max);

	public:

		OpenGLPosition(void);
		~OpenGLPosition(void);

		void SetPosition(GLfloat x, GLfloat y, GLfloat z);
		void SetMinBounds(GLfloat x, GLfloat y, GLfloat z);
		void SetMaxBounds(GLfloat x, GLfloat y, GLfloat z);

		GLfloat GetX(void);
		GLfloat GetY(void);
		GLfloat GetZ(void);

		bool UpdateX(GLfloat delta);
		bool UpdateY(GLfloat delta);
		bool UpdateZ(GLfloat delta);

	};

}
