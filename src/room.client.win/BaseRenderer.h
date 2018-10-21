#pragma once

#ifndef _BASERENDERER_H_
#define _BASERENDERER_H_

#include <stdlib.h>
#include <vector>

#include "GL\glew.h"
#include "GL\freeglut.h"

#include "Attributes.h"
#include "IRenderer.h"

using namespace room::client::win::attributes;

namespace room::client::win::renderers
{

	class BaseRenderer : public IRenderer
	{

	protected:

		bool _initialized;
		OpenGLColor _color;
		OpenGLPosition _position;

		std::vector<IRenderer*> _children;

		virtual void Display(void) = 0;

		void DrawVertex3f(GLfloat x, GLfloat y, GLfloat z);

	public:

		BaseRenderer(void);
		~BaseRenderer(void);

		void DisplayFunc(void);

		virtual int GetId(void) const = 0;
		virtual bool Initialize(void) = 0;

		virtual void KeyboardFunc(unsigned char key, int x, int y) = 0;
		virtual void MouseFunc(int button, int state, int x, int y) = 0;
		virtual void MotionFunc(int x, int y) = 0;
		virtual void IdleFunc(void) = 0;

	};

}

#endif // !_BASERENDERER_H_
