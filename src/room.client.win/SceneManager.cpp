#include "Renderers.h"
#include "Managers.h"

using namespace room::client::win::renderers;
using namespace room::client::win::managers;

// Constructors

SceneManager::SceneManager() {
}

SceneManager::~SceneManager() {
	_renderers.clear();
}

// Private

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
	std::vector<IRenderer*>::iterator iterator = _renderers.begin();

	for (int i = 0, size = _renderers.size(); i < size; i++, iterator++) {
		if (_renderers[i]->GetId() == renderer->GetId()) {
			result = true;

			break;
		}
	}

	if (result) {
		_renderers.erase(iterator);
	}

	return result;
}

// Public

void SceneManager::SetOpenGLOptions(OpenGLOptions* openGLOptions) {
	_openGLOptions = openGLOptions;
}

void SceneManager::ProcessDisplay() {
	std::cout << "-- Begin Render Scene" << std::endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 1.0, 0.0, 1.0);

	std::vector<IRenderer*> defaultRenderers = _openGLOptions->GetDefaultRenderers();

	for (int i = 0, size = _openGLOptions->GetDefaultRenderers().size(); i < size; i++)
	{
		defaultRenderers[i]->DisplayFunc();
	}

	for (int i = 0, size = _renderers.size(); i < size; i++)
	{
		_renderers[i]->DisplayFunc();
	}

	glutSwapBuffers();

	std::cout << "-- End Render Scene" << std::endl;
}

void SceneManager::ProcessKeyboard(unsigned char key, int x, int y) {
	std::vector<IRenderer*> defaultRenderers = _openGLOptions->GetDefaultRenderers();

	for (int i = 0, size = _openGLOptions->GetDefaultRenderers().size(); i < size; i++) {
		defaultRenderers[i]->KeyboardFunc(key, x, y);
	}

	for (int i = 0, size = _renderers.size(); i < size; i++)
	{
		_renderers[i]->KeyboardFunc(key, x, y);
	}
}

void SceneManager::ProcessMouse(int button, int state, int x, int y) {
	std::vector<IRenderer*> defaultRenderers = _openGLOptions->GetDefaultRenderers();

	for (int i = 0, size = defaultRenderers.size(); i < size; i++) {
		defaultRenderers[i]->MouseFunc(button, state, x, y);
	}

	for (int i = 0, size = _renderers.size(); i < size; i++) {
		_renderers[i]->MouseFunc(button, state, x, y);
	}
}

void SceneManager::ProcessMotion(int x, int y) {
	std::vector<IRenderer*> defaultRenderers = _openGLOptions->GetDefaultRenderers();

	for (int i = 0, size = defaultRenderers.size(); i < size; i++)
	{
		defaultRenderers[i]->MotionFunc(x, y);
	}

	for (int i = 0, size = _renderers.size(); i < size; i++)
	{
		_renderers[i]->MotionFunc(x, y);
	}
}

void SceneManager::ProcessIdle() {
	std::vector<IRenderer*> defaultRenderers = _openGLOptions->GetDefaultRenderers();

	for (int i = 0, size = defaultRenderers.size(); i < size; i++)
	{
		defaultRenderers[i]->IdleFunc();
	}

	for (int i = 0, size = _renderers.size(); i < size; i++)
	{
		_renderers[i]->IdleFunc();
	}
}
