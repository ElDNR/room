#pragma once

#ifndef _OPENGLLOADER_H_
#define _OPENGLLOADER_H_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <vector>

#include "GL\glew.h"
#include "GL\freeglut.h"

#include "SceneManager.h"

namespace core {

	class OpenGLLoader
	{
	private:

		bool _openGLInitialized;
		SceneManager _sceneManager;

	public:
		OpenGLLoader();
		~OpenGLLoader();

		int Load(int argc, char **argv, void(*renderCallback)(void));

		bool DisplayFunc(void);

	};

}

#endif // !_OPENGLLOADER_H_