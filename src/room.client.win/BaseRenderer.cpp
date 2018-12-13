#include "Renderers.h"

using namespace room::client::win::core;
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
	SimpleCamera simpleCamera;

	this->DisplayFunc(&simpleCamera);
}

void BaseRenderer::DisplayFunc(ICamera* camera) {
	if (_initialized && NULL != camera &&
		camera->IsInFrame(this->_position.GetX(), this->_position.GetY(), this->_position.GetZ())) {
		this->Display(camera);
	}
}

void BaseRenderer::DrawVertex3f(ICamera* camera, GLfloat x, GLfloat y, GLfloat z)
{
	if (NULL != camera) {
		camera->DrawVertex3f(this->_position.GetX() + x, this->_position.GetY() + y, this->_position.GetZ() + z);
	}
}
