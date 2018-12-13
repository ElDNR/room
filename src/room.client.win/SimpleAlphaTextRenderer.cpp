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
	this->_position.SetPosition(300.0f, 300.0f, 0.0f);
	this->_position.SetMaxBounds(0.4f, 0.4f, 0.0f);
	this->_position.SetMinBounds(0.2f, 0.2f, 0.0f);

	this->_initialized = true;
	return true;
}

void SimpleAlphaTextRenderer::Display(ICamera* camera) {
	this->_color.DisplayColor();

	glBegin(GL_POLYGON);
	{
		this->DrawVertex3f(camera, 0.0f, 0.0f, 0.0f);
		this->DrawVertex3f(camera, 50.01f, 0.0f, 0.0f);
		this->DrawVertex3f(camera, 50.01f, 200.04f, 0.0f);
		this->DrawVertex3f(camera, 0.0f, 200.04f, 0.0f);
	}
	glEnd();

	glBegin(GL_POLYGON);
	{
		this->DrawVertex3f(camera, 50.01f, 0.0f, 0.0f);
		this->DrawVertex3f(camera, 100.02f, 0.0f, 0.0f);
		this->DrawVertex3f(camera, 100.02f, 50.01f, 0.0f);
		this->DrawVertex3f(camera, 50.01f, 50.01f, 0.0f);
	}
	glEnd();

	glBegin(GL_POLYGON);
	{
		this->DrawVertex3f(camera, 100.02f, 0.0f, 0.0f);
		this->DrawVertex3f(camera, 150.03f, 0.0f, 0.0f);
		this->DrawVertex3f(camera, 150.03f, 200.04f, 0.0f);
		this->DrawVertex3f(camera, 100.02f, 200.04f, 0.0f);
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
