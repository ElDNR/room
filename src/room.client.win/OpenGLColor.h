#pragma once

#include "GL\glew.h"
#include "GL\freeglut.h"

namespace room::client::win::attributes
{

	class OpenGLColor
	{

	private:

		GLfloat _red;
		GLfloat _green;
		GLfloat _blue;
		GLfloat _alpha;

	public:

		OpenGLColor(void);
		~OpenGLColor(void);

		void SetColor(GLfloat red, GLfloat green, GLfloat blue);
		void SetColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
		void UpdateOpacity(GLfloat delta);

		void DisplayColor(void);

	};

}
