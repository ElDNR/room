#pragma once

#include "GL\glew.h"
#include "GL\freeglut.h"

namespace room::client::win::attributes
{

	class OpenGLPosition
	{

	private:

		GLfloat _x;
		GLfloat _y;
		GLfloat _z;

		GLfloat _minX;
		GLfloat _minY;
		GLfloat _minZ;

		GLfloat _maxX;
		GLfloat _maxY;
		GLfloat _maxZ;

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
