#include "Renderers.h"

using namespace room::client::win::renderers;

SquareRenderer::SquareRenderer(void) {
	this->_color.SetColor(0.0f, 0.0f, 0.0f);
}

SquareRenderer::~SquareRenderer(void) {}

int SquareRenderer::GetId() const {
	return 4;
}

bool SquareRenderer::Initialize(void) {
	this->_position.SetPosition(250.25f, 250.25f, 0.0f);
	this->_position.SetMaxBounds(700.4f, 700.4f, 0.0f);
	this->_position.SetMinBounds(100.2f, 100.2f, 0.0f);

	this->_initialized = true;
	return true;
}

void SquareRenderer::Display(ICamera* camera)
{
	this->_color.DisplayColor();

	glBegin(GL_POLYGON);
	{
		this->DrawVertex3f(camera, 0.0f, 0.0f, 0.0f);
		this->DrawVertex3f(camera, 400.25f, 0.0f, 0.0f);
		this->DrawVertex3f(camera, 400.25f, 400.25f, 0.0f);
		this->DrawVertex3f(camera, 0.0f, 400.25f, 0.0f);
	}
	glEnd();
}

void SquareRenderer::KeyboardFunc(unsigned char key, int x, int y)
{

}

void SquareRenderer::MouseFunc(int button, int state, int x, int y)
{
	// Testing the movement functionality.
	// this->_position.UpdateX(0.01f);
}

void SquareRenderer::MotionFunc(int x, int y)
{

}

void SquareRenderer::IdleFunc(void)
{

}
