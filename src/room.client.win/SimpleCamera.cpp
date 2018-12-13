#include "SimpleCamera.h"

using namespace room::client::win::core;

SimpleCamera::SimpleCamera(void) {
	this->_width = 800;
	this->_height = 600;

	this->_position.SetPosition(0.0f, 0.0f, 0.0f);
}

SimpleCamera::SimpleCamera(GLfloat width, GLfloat height) {
	this->_width = width;
	this->_height = height;

	this->_position.SetPosition(0.0f, 0.0f, 0.0f);
}

SimpleCamera::~SimpleCamera(void) {
}

void SimpleCamera::IncrementX(void) {
	this->_position.UpdateX(this->PAN_FORWARD_DELTA);
}

void SimpleCamera::IncrementY(void) {
	this->_position.UpdateY(this->PAN_FORWARD_DELTA);
}

void SimpleCamera::IncrementZ(void) {
	this->_position.UpdateZ(this->ZOOM_FORWARD_DELTA);

	GLfloat zoomModifyer = this->_zoomModifyer + this->ZOOM_FORWARD_DELTA;
	if (zoomModifyer > 0 && zoomModifyer <= 1) {
		this->_zoomModifyer = zoomModifyer;
	}
}

void SimpleCamera::DecrementX(void) {
	this->_position.UpdateX(this->PAN_BACKWARDS_DELTA);
}

void SimpleCamera::DecrementY(void) {
	this->_position.UpdateY(this->PAN_BACKWARDS_DELTA);
}

void SimpleCamera::DecrementZ(void) {
	this->_position.UpdateZ(this->ZOOM_BACKWARDS_DELTA);

	GLfloat zoomModifyer = this->_zoomModifyer + this->ZOOM_BACKWARDS_DELTA;
	if (zoomModifyer > 0 && zoomModifyer <= 1) {
		this->_zoomModifyer = zoomModifyer;
	}
}

void SimpleCamera::UpdatePosition(GLfloat x, GLfloat y, GLfloat z) {
	this->_position.UpdateX(this->_position.GetX() - x);
	this->_position.UpdateY(this->_position.GetY() - y);
	this->_position.UpdateZ(this->_position.GetZ() - z);
}

bool SimpleCamera::IsInFrame(GLfloat x, GLfloat y, GLfloat z) {
	GLfloat relativeX = ((x - this->_position.GetX()) / this->_width);
	GLfloat relativeY = ((y - this->_position.GetY()) / this->_height);
	GLfloat relativeZ = z - this->_position.GetZ();

	return (relativeX > -0.5f && relativeX < 1.5f) &&
		(relativeY > -0.5f && relativeY < 1.5f) &&
		(relativeZ > -0.5f && relativeZ < 1.5f);
}

void SimpleCamera::DrawVertex3f(GLfloat x, GLfloat y, GLfloat z) {
	GLfloat relativeX = ((x - this->_position.GetX()) / this->_width) * this->_zoomModifyer;
	GLfloat relativeY = ((y - this->_position.GetY()) / this->_height) * this->_zoomModifyer;
	GLfloat relativeZ = z - this->_position.GetZ();

	glVertex3f(relativeX, relativeY, relativeZ);
}
