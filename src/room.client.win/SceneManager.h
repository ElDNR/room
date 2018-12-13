#pragma once

#include <iostream>
#include <stdio.h>
#include <time.h>
#include <fstream>

#include <thread>
#include <chrono>

#include "GL\glew.h"
#include "GL\freeglut.h"

#include "Core.h"
#include "Attributes.h"
#include "ISceneManager.h"
#include "Renderers.h"
#include "Utilities.h"

using namespace room::client::win::core;
using namespace room::client::win::renderers;

namespace room::client::win::managers
{

	class SceneManager : public ISceneManager
	{

	private:

		bool _initialized;

		ICamera* _camera;

		OpenGLOptions* _openGLOptions;
		GLfloat _backgroundRed, _backgroundGreen, _backgroundBlue, _backgroundAlpha;

		time_t _lastIdleTime;
		std::vector<IIntegerIdentifiable*> _renderers;

		bool AddRenderer(IRenderer* renderer);
		bool RemoveRenderer(IRenderer* renderer);

	public:
		SceneManager();
		~SceneManager();

		bool Initialize(void);
		void SetOpenGLOptions(OpenGLOptions* openGLOptions);

		void ProcessDisplay(void);
		void ProcessKeyboard(unsigned char key, int x, int y);
		void ProcessMouse(int button, int state, int x, int y);
		void ProcessMotion(int x, int y);
		void ProcessIdle(void);

	};

}
