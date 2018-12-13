#include "GLfloatSquareArrayWrapper.h"

using namespace room::client::win::core;

GLfloatSquareArrayWrapper::GLfloatSquareArrayWrapper(GLfloat** wrapArray, int length, int width) {
	this->_wrapArray = wrapArray;

	this->_length = length;
	this->_width = width;
}

GLfloatSquareArrayWrapper::~GLfloatSquareArrayWrapper() {
	for (int i = 0; i < this->_length; i++) {
		delete[] this->_wrapArray[i];
	}

	delete[] this->_wrapArray;
}

GLfloat GLfloatSquareArrayWrapper::Get(int i, int j) {
	GLfloat result;

	if (i >= 0 && j >= 0 && i < this->_length && j < this->_width) {
		result = this->_wrapArray[i][j];
	}
	else {
		result = 0;
	}

	return result;
}

int GLfloatSquareArrayWrapper::Length(void) {
	return this->_length;
}

int GLfloatSquareArrayWrapper::Width(void) {
	return this->_width;
}
