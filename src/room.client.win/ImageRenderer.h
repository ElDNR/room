#pragma once

#include <iostream>

#include "GL\glew.h"
#include "GL\freeglut.h"

#include "BaseRenderer.h"
#include "soil.h"

namespace room::client::win::renderers
{

	/// <summary>
	///  Provides functionality for drawing an image to the screen from a file.
	/// </summary>
	class ImageRenderer : public BaseRenderer {

	private:

		GLuint _imageTextureID;

	public:

		ImageRenderer();
		~ImageRenderer();

		int GetId(void) const;
		bool Initialize(void);
		void Display(void);
		void KeyboardFunc(unsigned char key, int x, int y);
		void MouseFunc(int button, int state, int x, int y);
		void MotionFunc(int x, int y);
		void IdleFunc(void);

	};

}
