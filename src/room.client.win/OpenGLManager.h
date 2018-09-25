#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <vector>

#include "GL\glew.h"
#include "GL\freeglut.h"

#include "Core.h"
#include "IOpenGLManager.h"
#include "ISceneManager.h"
#include "SceneManager.h"

using namespace room::client::win::core;

namespace room::client::win::managers
{

	class OpenGLManager : public IOpenGLManager
	{

	private:

		bool _openGLInitialized;
		ISceneManager* _sceneManager;

	public:

		OpenGLManager();
		~OpenGLManager();

		int Load(OpenGLOptions* openGLOptions);

		bool DisplayFunc(void);
		bool KeyboardFunc(unsigned char key, int x, int y);
		bool MouseFunc(int button, int state, int x, int y);
		bool MotionFunc(int x, int y);
		bool IdleFunc(void);

	};

}
