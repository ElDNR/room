#include "Renderers.h"
#include "Managers.h"

using namespace room::client::win::renderers;
using namespace room::client::win::managers;

SceneManager::SceneManager() {
}

SceneManager::~SceneManager() {
	_renderers.clear();
}

void SceneManager::ProcessDisplay() {
	std::cout << "-- Begin Render Scene" << std::endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 1.0, 0.0, 1.0);

	for (std::vector<IRenderer*>::iterator iterator = _renderers.begin(),
		iteratorEnd = _renderers.end();
		iterator != iteratorEnd; iterator++) {
		(*iterator)->DisplayFunc();
	}

	glutSwapBuffers();

	std::cout << "-- End Render Scene" << std::endl;
}

void SceneManager::ProcessKeyboard(unsigned char key, int x, int y) {
	for (std::vector<IRenderer*>::iterator iterator = _renderers.begin(),
		iteratorEnd = _renderers.end();
		iterator != iteratorEnd; iterator++) {
		(*iterator)->KeyboardFunc(key, x, y);
	}
}

void SceneManager::ProcessMouse(int button, int state, int x, int y) {
	for (std::vector<IRenderer*>::iterator iterator = _renderers.begin(),
		iteratorEnd = _renderers.end();
		iterator != iteratorEnd; iterator++) {
		(*iterator)->MouseFunc(button, state, x, y);
	}
}

void SceneManager::ProcessMotion(int x, int y) {
	for (std::vector<IRenderer*>::iterator iterator = _renderers.begin(),
		iteratorEnd = _renderers.end();
		iterator != iteratorEnd; iterator++) {
		(*iterator)->MotionFunc(x, y);
	}
}

void SceneManager::ProcessIdle() {
	for (std::vector<IRenderer*>::iterator iterator = _renderers.begin(),
		iteratorEnd = _renderers.end();
		iterator != iteratorEnd; iterator++) {
		(*iterator)->IdleFunc();
	}
}

bool SceneManager::AddRenderer(IRenderer* renderer) {
	bool result = true;
	std::vector<IRenderer*>::iterator iterator = _renderers.begin(),
		iteratorEnd = _renderers.end();

	for (; iterator != iteratorEnd; iterator++) {
		if ((*iterator)->GetId() == renderer->GetId()) {
			result = false;

			break;
		}
	}

	if (result) {
		_renderers.push_back(renderer);
	}

	return result;
}

bool SceneManager::RemoveRenderer(IRenderer* renderer) {
	bool result = false;
	std::vector<IRenderer*>::iterator iterator = _renderers.begin(),
		iteratorEnd = _renderers.end();

	for (; iterator != iteratorEnd; iterator++) {
		if ((*iterator)->GetId() == renderer->GetId()) {
			result = true;

			break;
		}
	}

	if (result) {
		_renderers.erase(iterator);
	}

	return result;
}
