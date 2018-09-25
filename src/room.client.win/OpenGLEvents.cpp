#include "Core.h"

using namespace room::client::win::core;

OpenGLEvents::OpenGLEvents() {
}

OpenGLEvents::~OpenGLEvents() {
}

bool OpenGLEvents::setDisplayFuncEventHandler(openGLEventsVoidFunc displayFunc) {
	bool result;

	if (NULL == this->_displayFunc) {
		this->_displayFunc = displayFunc;
		result = true;
	}
	else
	{
		result = false;
	}

	return result;
}

openGLEventsVoidFunc OpenGLEvents::getDisplayFuncEventHandler(void) {
	return this->_displayFunc;
}

bool OpenGLEvents::setKeyboardFuncEventHandler(openGLEventsKeyboardFunc keyboardFunc) {
	bool result;

	if (NULL == this->_keyboardFunc) {
		this->_keyboardFunc = keyboardFunc;
		result = true;
	}
	else
	{
		result = false;
	}

	return result;
}

openGLEventsKeyboardFunc OpenGLEvents::getKeyboardFuncEventHandler(void) {
	return this->_keyboardFunc;
}

bool OpenGLEvents::setMouseFuncEventHandler(openGLEventsMouseFunc mouseFunc) {
	bool result;

	if (NULL == this->_mouseFunc) {
		this->_mouseFunc = mouseFunc;
		result = true;
	}
	else
	{
		result = false;
	}

	return result;
}

openGLEventsMouseFunc OpenGLEvents::getMouseFuncEventHandler(void) {
	return this->_mouseFunc;
}

bool OpenGLEvents::setMotionFuncEventHandler(openGLEventsMotionFunc motionFunc) {
	bool result;

	if (NULL == this->_motionFunc) {
		this->_motionFunc = motionFunc;
		result = true;
	}
	else
	{
		result = false;
	}

	return result;
}

openGLEventsMotionFunc OpenGLEvents::getMotionFuncEventHandler(void) {
	return this->_motionFunc;
}

bool OpenGLEvents::setPassiveMotionFuncEventHandler(openGLEventsMotionFunc passiveMotionFunc) {
	bool result;

	if (NULL == this->_passiveMotionFunc) {
		this->_passiveMotionFunc = passiveMotionFunc;
		result = true;
	}
	else
	{
		result = false;
	}

	return result;
}

openGLEventsMotionFunc OpenGLEvents::getPassiveMotionFuncEventHandler(void) {
	return this->_passiveMotionFunc;
}

bool OpenGLEvents::setIdleFuncEventHandler(openGLEventsVoidFunc idleFunc) {
	bool result;

	if (NULL == this->_idleFunc) {
		this->_idleFunc = idleFunc;
		result = true;
	}
	else
	{
		result = false;
	}

	return result;
}

openGLEventsVoidFunc OpenGLEvents::getIdleFuncEventHandler(void) {
	return this->_idleFunc;
}
