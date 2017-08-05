#pragma once

#ifndef _SQUARERENDERER_H_
#define _SQUARERENDERER_H_

#include "GL\glew.h"
#include "GL\freeglut.h"

#include "IRenderer.h"

namespace renderers
{

	class SquareRenderer : public IRenderer {
	private:
		int getId(void) const;
	public:
		SquareRenderer(void);
		~SquareRenderer(void);

		void displayFunc(void);
		void keyboardFunc(unsigned char key, int x, int y);
		void mouseFunc(int button, int state, int x, int y);
		void motionFunc(int x, int y);
		void idleFunc(void);
	};

}

#endif // !_SQUARERENDERER_H_
