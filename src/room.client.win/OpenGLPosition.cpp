#include "Attributes.h"

using namespace room::client::win::attributes;

OpenGLPosition::OpenGLPosition(void) {}

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

	this->_hasBounds = true;
}

void OpenGLPosition::SetMaxBounds(GLfloat x, GLfloat y, GLfloat z)
{
	this->_maxX = x;
	this->_minY = y;
	this->_minZ = z;

	this->_hasBounds = true;
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

	if (!this->_hasBounds)
	{
		result = true;

		*valuePtr = temp;
	}
	else if (temp >= min && temp <= max)
	{
		result = true;

		*valuePtr = temp;
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
