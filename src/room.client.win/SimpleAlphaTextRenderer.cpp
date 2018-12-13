#include "SimpleAlphaTextRenderer.h"
#include <iostream>

using namespace room::client::win::renderers;

SimpleAlphaTextRenderer::SimpleAlphaTextRenderer() {
	this->_color.SetColor(1.0f, 1.0f, 1.0f);

	this->_displayText = "room";
	this->_fontSizeModifyer = 200.0f;
}

SimpleAlphaTextRenderer::~SimpleAlphaTextRenderer() {
	for (int i = 0; i < 26; i++) {
		delete this->ALPHABET_MAP[i];
	}
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

	GLfloat charSizeIndex = 0;
	//*
	for (int i = 0, iSize = this->_displayText.size(); i < iSize; i++, charSizeIndex += this->_fontSizeModifyer) {
		int letterIndex;
		if (this->_displayText[i] >= 'a' && this->_displayText[i] <= 'z')
		{
			letterIndex = _displayText[i] - 'a';
		}
		else if (this->_displayText[i] >= 'A' && this->_displayText[i] <= 'Z') 
		{
			letterIndex = _displayText[i] - 'A';
		}
		else
		{
			continue;
		}

		GLfloatSquareArrayWrapper* letterArray = this->ALPHABET_MAP[20];

		//TODO: Remove
		///cout << endl << "U:" << endl;

		for (int j = 0, jSize = letterArray->Length(); j < jSize; j++) {
			glBegin(GL_POLYGON);
			{
				for (int k = 0; k < 12; k += 3) {
					GLfloat x = letterArray->Get(j, k) * this->_fontSizeModifyer + charSizeIndex;
					GLfloat y = letterArray->Get(j, k + 1) * this->_fontSizeModifyer;
					GLfloat z = letterArray->Get(j, k + 2);

					this->DrawVertex3f(camera, x, y, z);

					//cout << x << ", " << y << ", " << z << endl;
				}
			}
			glEnd();

			//cout << endl;
		}
	}
	//*/
}

void SimpleAlphaTextRenderer::KeyboardFunc(unsigned char key, int x, int y) {
}

void SimpleAlphaTextRenderer::MouseFunc(int button, int state, int x, int y) {
}

void SimpleAlphaTextRenderer::MotionFunc(int x, int y) {
}

void SimpleAlphaTextRenderer::IdleFunc() {
}

void SimpleAlphaTextRenderer::SetFontSize(GLfloat size) {
	this->_fontSizeModifyer = size;
}
