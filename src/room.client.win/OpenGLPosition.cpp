#include "Attributes.h"

using namespace room::client::win::attributes;

OpenGLPosition::OpenGLPosition(void)
{
	this->SetPosition(0, 0, 0);

	this->SetMinBounds(0, 0, 0);

	this->SetMaxBounds(0, 0, 0);
}

OpenGLPosition::~OpenGLPosition(void) {}

void OpenGLPosition::SetPosition(GLfloat x, GLfloat y, GLfloat z)
{
	this->_x = x;
	this->_y = y;
	this->_z = z;
}

void OpenGLPosition::SetMinBounds(GLfloat x, GLfloat y, GLfloat z)
{
	this->_minX = x;
	this->_minY = y;
	this->_minZ = z;
}

void OpenGLPosition::SetMaxBounds(GLfloat x, GLfloat y, GLfloat z)
{
	this->_maxX = x;
	this->_minY = y;
	this->_minZ = z;
}

GLfloat OpenGLPosition::GetX(void)
{
	return this->_x;
}

GLfloat OpenGLPosition::GetY(void)
{
	return this->_y;
}

GLfloat OpenGLPosition::GetZ(void)
{
	return this->_z;
}

bool OpenGLPosition::UpdateValue(GLfloat* valuePtr, GLfloat delta, GLfloat min, GLfloat max)
{
	bool result;
	GLfloat temp = *valuePtr + delta;

	if (temp >= min && temp <= max)
	{
		*valuePtr = temp;
		result = true;
	}
	else
	{
		result = false;
	}

	return result;
}

bool OpenGLPosition::UpdateX(GLfloat delta)
{
	return this->UpdateValue(&this->_x, delta, this->_minX, this->_maxX);
}

bool OpenGLPosition::UpdateY(GLfloat delta)
{
	return this->UpdateValue(&this->_y, delta, this->_minY, this->_maxY);
}

bool OpenGLPosition::UpdateZ(GLfloat delta)
{
	return this->UpdateValue(&this->_z, delta, this->_minZ, this->_maxZ);
}
