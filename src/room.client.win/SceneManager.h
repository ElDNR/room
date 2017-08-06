#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <vector>

#include "GL\glew.h"
#include "GL\freeglut.h"

#include "IRenderer.h"

using namespace room::client::win::renderers;

namespace room::client::win::managers
{

	class SceneManager
	{

	private:

		std::vector<IRenderer*> _renderers;

	public:
		SceneManager();
		~SceneManager();

		void ProcessDisplay(void);
		void ProcessKeyboard(unsigned char key, int x, int y);
		void ProcessMouse(int button, int state, int x, int y);
		void ProcessMotion(int x, int y);
		void ProcessIdle(void);

		bool AddRenderer(IRenderer* renderer);
		bool RemoveRenderer(IRenderer* renderer);

	};

}
