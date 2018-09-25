#include "Renderers.h"

using namespace room::client::win::renderers;

SquareRenderer::SquareRenderer(void)
{
	this->_color.SetColor(1.0, 1.0, 1.0);
	this->_position.SetPosition(0.25, 0.25, 0.0);
	this->_position.SetMaxBounds(.4, .4, 0);
	this->_position.SetMinBounds(.2, .2, 0);
}

SquareRenderer::~SquareRenderer(void) {}

int SquareRenderer::GetId() const {
	return 4;
}

void SquareRenderer::Display(void)
{
	/*  draw white polygon (rectangle) with corners at
	*  (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
	*/
	glBegin(GL_POLYGON);
	{
		this->DrawVertex3f(0.0, 0.0, 0.0);
		this->DrawVertex3f(0.5, 0.0, 0.0);
		this->DrawVertex3f(0.5, 0.5, 0.0);
		this->DrawVertex3f(0.0, 0.5, 0.0);
	}
	glEnd();

	// Testing the movement functionality.
	this->_position.UpdateX(0.01);
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
