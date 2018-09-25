#pragma once

#include "Core.h"

using namespace room::client::win::core;

namespace room::client::win::managers
{

	class ISceneManager
	{

	public:

		virtual void SetOpenGLOptions(OpenGLOptions* openGLOptions) = 0;

		virtual void ProcessDisplay(void) = 0;
		virtual void ProcessKeyboard(unsigned char key, int x, int y) = 0;
		virtual void ProcessMouse(int button, int state, int x, int y) = 0;
		virtual void ProcessMotion(int x, int y) = 0;
		virtual void ProcessIdle(void) = 0;

	};

}
