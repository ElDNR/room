#include "SceneManager.h"

using namespace core;
using namespace renderers;

SceneManager::SceneManager() {
}

SceneManager::~SceneManager() {
	_renderers.clear();
}

void SceneManager::RenderScene() {
	std::cout << "-- Begin Render Scene" << std::endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 1.0, 0.0, 1.0);

	for (std::vector<IRenderer*>::iterator iterator = _renderers.begin(),
		iteratorEnd = _renderers.end();
		iterator != iteratorEnd; iterator++) {
		(*iterator)->displayFunc();
	}

	glutSwapBuffers();

	std::cout << "-- End Render Scene" << std::endl;
}

bool SceneManager::AddRenderer(IRenderer* renderer) {
	bool result = true;
	std::vector<IRenderer*>::iterator iterator = _renderers.begin(),
		iteratorEnd = _renderers.end();

	for (; iterator != iteratorEnd; iterator++) {
		if ((*iterator)->getId() == renderer->getId()) {
			result = false;

			break;
		}
	}

	if (result) {
		_renderers.push_back(renderer);
	}

	return true;
}

bool SceneManager::RemoveRenderer(IRenderer* renderer) {
	bool result = false;
	std::vector<IRenderer*>::iterator iterator = _renderers.begin(),
		iteratorEnd = _renderers.end();

	for (; iterator != iteratorEnd; iterator++) {
		if ((*iterator)->getId() == renderer->getId()) {
			result = true;

			break;
		}
	}

	if (result) {
		_renderers.erase(iterator);
	}

	return result;
}
