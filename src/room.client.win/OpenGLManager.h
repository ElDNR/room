#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <vector>

#include "GL\glew.h"
#include "GL\freeglut.h"

#include "SceneManager.h"

namespace room::client::win::managers
{

	class OpenGLManager
	{

	private:

		bool _openGLInitialized;
		SceneManager _sceneManager;

	public:

		OpenGLManager();
		~OpenGLManager();

		int Load(int argc, char **argv, void(*renderCallback)(void));

		bool DisplayFunc(void);
		bool KeyboardFunc(unsigned char key, int x, int y);
		bool MouseFunc(int button, int state, int x, int y);
		bool MotionFunc(int x, int y);
		bool IdleFunc(void);

	};

}
