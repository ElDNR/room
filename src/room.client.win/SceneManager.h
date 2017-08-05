#pragma once

#ifndef _SCENEMANAGER_H_
#define _SCENEMANAGER_H_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <vector>

#include "GL\glew.h"
#include "GL\freeglut.h"

#include "IRenderer.h"

using namespace renderers;

namespace core
{

	class SceneManager
	{
	private:

		std::vector<IRenderer*> _renderers;

	public:
		SceneManager();
		~SceneManager();

		void RenderScene(void);

		bool AddRenderer(IRenderer* renderer);
		bool RemoveRenderer(IRenderer* renderer);
	};

}

#endif // !_SCENEMANAGER_H_
