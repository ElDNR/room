#pragma once

#ifndef _SQUARERENDERER_H_
#define _SQUARERENDERER_H_

#include "GL\glew.h"
#include "GL\freeglut.h"

#include "IRenderer.h"

namespace room::client::win::renderers
{

	class SquareRenderer : public IRenderer
	{

	private:

		GLfloat _red;
		GLfloat _gree;
		GLfloat _blue;

		int GetId(void) const;
	public:

		SquareRenderer(void);
		~SquareRenderer(void);

		void DisplayFunc(void);
		void KeyboardFunc(unsigned char key, int x, int y);
		void MouseFunc(int button, int state, int x, int y);
		void MotionFunc(int x, int y);
		void IdleFunc(void);

	};

}

#endif // !_SQUARERENDERER_H_
