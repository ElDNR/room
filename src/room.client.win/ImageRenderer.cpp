#include "ImageRenderer.h"

using namespace room::client::win::renderers;

ImageRenderer::ImageRenderer() {
	this->_color.SetColor(1.0f, 1.0f, 1.0f);
}

ImageRenderer::~ImageRenderer() {

}

int ImageRenderer::GetId(void) const {
	return 5;
}

bool ImageRenderer::Initialize(void) {
	this->_imageTextureID = SOIL_load_OGL_texture("bricks.PNG",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);

	this->_position.SetPosition(0.0f, 0.0f, 0.0f);
	this->_position.SetMaxBounds(0.2f, 0.2f, 0.0f);
	this->_position.SetMinBounds(0.0f, 0.0f, 0.0f);

	if (this->_imageTextureID > 0)
	{
		this->_initialized = true;
	}
	else
	{
		std::cout << "SOIL loading error:\r\n\t" << SOIL_last_result << std::endl;
	}

	return true;
}

void ImageRenderer::Display(void) {
	this->_color.DisplayColor();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, this->_imageTextureID);

	// Draw a textured quad
	glBegin(GL_QUADS);
	{
		// Specify the coordinates of our image given that the container will serve as the frame.
		// The container is a Square with sides 0.25% the window size, and the image will be drawn to
		// fit 100% of the original image dimensions.
		glTexCoord2f(0.0f, 0.0f);
		this->DrawVertex3f(0.0f, 0.0f, 0.0f);

		glTexCoord2f(0.0f, 1.0f);
		this->DrawVertex3f(0.0f, 0.25f, 0.0f);

		glTexCoord2f(1.0f, 1.0f);
		this->DrawVertex3f(0.25f, 0.25f, 0.0f);

		glTexCoord2f(1.0f, 0.0f);
		this->DrawVertex3f(0.25f, 0.0f, 0.0f);
	}
	glEnd();

	glDisable(GL_TEXTURE_2D);
}

void ImageRenderer::KeyboardFunc(unsigned char key, int x, int y) {

}

void ImageRenderer::MouseFunc(int button, int state, int x, int y) {
	// Testing the movement functionality.
	this->_position.UpdateX(0.01f);
}

void ImageRenderer::MotionFunc(int x, int y) {
}

void ImageRenderer::IdleFunc(void) {

}
