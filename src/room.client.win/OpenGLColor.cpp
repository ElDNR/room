#include "Attributes.h"

using namespace room::client::win::attributes;

OpenGLColor::OpenGLColor(void)
{
	this->SetColor(0, 0, 0, 0);
}

OpenGLColor::~OpenGLColor(void)
{
}

void OpenGLColor::SetColor(GLfloat red, GLfloat green, GLfloat blue)
{
	this->SetColor(red, green, blue, 1.0);
}

void OpenGLColor::SetColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
	this->_red = red;
	this->_green = green;
	this->_blue = blue;
	this->_alpha = alpha;
}

void OpenGLColor::UpdateOpacity(GLfloat delta)
{
	this->_alpha += delta;
}

void OpenGLColor::DisplayColor(void)
{
	glColor4f(this->_red, this->_green, this->_blue, this->_alpha);
}
