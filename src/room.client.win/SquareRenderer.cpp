#include "Renderers.h"

using namespace room::client::win::renderers;

int SquareRenderer::GetId() const {
	return 4;
}

SquareRenderer::SquareRenderer(void) {}
SquareRenderer::~SquareRenderer(void) {}

void SquareRenderer::DisplayFunc(void)
{
	/*  clear all pixels  */
	glClear(GL_COLOR_BUFFER_BIT);

	/*  draw white polygon (rectangle) with corners at
	*  (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
	*/
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	{
		glVertex3f(0.25, 0.25, 0.0);
		glVertex3f(0.75, 0.25, 0.0);
		glVertex3f(0.75, 0.75, 0.0);
		glVertex3f(0.25, 0.75, 0.0);
	}
	glEnd();
}

void SquareRenderer::KeyboardFunc(unsigned char key, int x, int y)
{

}

void SquareRenderer::MouseFunc(int button, int state, int x, int y)
{

}

void SquareRenderer::MotionFunc(int x, int y)
{

}

void SquareRenderer::IdleFunc(void)
{

}
