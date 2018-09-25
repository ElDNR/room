#pragma once

#include "Core.h"

using namespace room::client::win::core;

namespace room::client::win::managers
{

	class IOpenGLManager
	{

	public:

		virtual int Load(OpenGLOptions* openGLOptions) = 0;

		virtual bool DisplayFunc(void) = 0;
		virtual bool KeyboardFunc(unsigned char key, int x, int y) = 0;
		virtual bool MouseFunc(int button, int state, int x, int y) = 0;
		virtual bool MotionFunc(int x, int y) = 0;
		virtual bool IdleFunc(void) = 0;

	};

}
