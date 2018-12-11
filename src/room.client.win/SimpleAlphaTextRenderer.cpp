#include "SimpleAlphaTextRenderer.h"

using namespace room::client::win::renderers;

SimpleAlphaTextRenderer::SimpleAlphaTextRenderer() {
	this->_color.SetColor(1.0f, 1.0f, 1.0f);
}

SimpleAlphaTextRenderer::~SimpleAlphaTextRenderer() {
}

int SimpleAlphaTextRenderer::GetId() const {
	return 26;
}

bool SimpleAlphaTextRenderer::Initialize() {
	this->_position.SetPosition(0.25f, 0.25f, 0.0f);
	this->_position.SetMaxBounds(0.4f, 0.4f, 0.0f);
	this->_position.SetMinBounds(0.2f, 0.2f, 0.0f);

	this->_initialized = true;
	return true;
}

void SimpleAlphaTextRenderer::Display() {
	this->_color.DisplayColor();

	glBegin(GL_POLYGON);
	{
		this->DrawVertex3f(0.0f, 0.0f, 0.0f);
		this->DrawVertex3f(0.01f, 0.0f, 0.0f);
		this->DrawVertex3f(0.01f, 0.04f, 0.0f);
		this->DrawVertex3f(0.0f, 0.04f, 0.0f);
	}
	glEnd();

	glBegin(GL_POLYGON);
	{
		this->DrawVertex3f(0.01f, 0.0f, 0.0f);
		this->DrawVertex3f(0.02f, 0.0f, 0.0f);
		this->DrawVertex3f(0.02f, 0.01f, 0.0f);
		this->DrawVertex3f(0.01f, 0.01f, 0.0f);
	}
	glEnd();

	glBegin(GL_POLYGON);
	{
		this->DrawVertex3f(0.02f, 0.0f, 0.0f);
		this->DrawVertex3f(0.03f, 0.0f, 0.0f);
		this->DrawVertex3f(0.03f, 0.04f, 0.0f);
		this->DrawVertex3f(0.02f, 0.04f, 0.0f);
	}
	glEnd();
}

void SimpleAlphaTextRenderer::KeyboardFunc(unsigned char key, int x, int y) {
}

void SimpleAlphaTextRenderer::MouseFunc(int button, int state, int x, int y) {
}

void SimpleAlphaTextRenderer::MotionFunc(int x, int y) {
}

void SimpleAlphaTextRenderer::IdleFunc() {
}
