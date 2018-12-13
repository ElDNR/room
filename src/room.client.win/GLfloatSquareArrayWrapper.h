#pragma once

#include "GL\glew.h"
#include "GL\freeglut.h"

namespace room::client::win::core {

	class GLfloatSquareArrayWrapper {

	private:

		GLfloat** _wrapArray = NULL;
		int _length = 0;
		int _width = 0;

	public:

		GLfloatSquareArrayWrapper(GLfloat** wrapArray, int length, int width);
		~GLfloatSquareArrayWrapper();

		GLfloat Get(int i, int j);

		int Length(void);
		int Width(void);

	};

}
