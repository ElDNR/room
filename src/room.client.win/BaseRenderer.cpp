#include "Renderers.h"

using namespace room::client::win::renderers;

BaseRenderer::BaseRenderer()
{
	this->_initialized = false;
	this->_color.SetColor(0, 0, 0, 0);
}

BaseRenderer::~BaseRenderer()
{
	this->_children.clear();
}

void BaseRenderer::DisplayFunc(void)
{
	if (_initialized) {
		this->Display();
	}
}

void BaseRenderer::DrawVertex3f(GLfloat x, GLfloat y, GLfloat z)
{
	glVertex3f(this->_position.GetX() + x, this->_position.GetY() + y, this->_position.GetZ() + z);
}
