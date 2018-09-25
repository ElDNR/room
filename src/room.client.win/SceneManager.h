#pragma once

#include <iostream>
#include <stdio.h>
#include <time.h>
#include <fstream>

#include "GL\glew.h"
#include "GL\freeglut.h"

#include "Core.h"
#include "ISceneManager.h"
#include "Renderers.h"

using namespace room::client::win::core;
using namespace room::client::win::renderers;

namespace room::client::win::managers
{

	class SceneManager : public ISceneManager
	{

	private:

		OpenGLOptions* _openGLOptions;
		GLfloat _backgroundRed, _backgroundGreen, _backgroundBlue, _backgroundAlpha;

		time_t _lastIdleTime;
		std::vector<IRenderer*> _renderers;

		bool AddRenderer(IRenderer* renderer);
		bool RemoveRenderer(IRenderer* renderer);

	public:
		SceneManager();
		~SceneManager();

		void SetOpenGLOptions(OpenGLOptions* openGLOptions);

		void ProcessDisplay(void);
		void ProcessKeyboard(unsigned char key, int x, int y);
		void ProcessMouse(int button, int state, int x, int y);
		void ProcessMotion(int x, int y);
		void ProcessIdle(void);

	};

}
