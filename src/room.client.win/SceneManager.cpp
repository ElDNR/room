#include "Renderers.h"
#include "Managers.h"

using namespace room::client::win::renderers;
using namespace room::client::win::managers;

// Constructors

SceneManager::SceneManager() {
	this->_backgroundRed = 0.0;
	this->_backgroundGreen = 1.0;
	this->_backgroundBlue = 0.0;
	this->_backgroundAlpha = 1.0;

	time(&this->_lastIdleTime);
}

SceneManager::~SceneManager() {
	this->_renderers.clear();
}

// Private

bool SceneManager::AddRenderer(IRenderer* renderer) {
	bool result = true;
	std::vector<IRenderer*>::iterator iterator = this->_renderers.begin(),
		iteratorEnd = this->_renderers.end();

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

	//Set the background to be green.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(this->_backgroundRed, this->_backgroundGreen,
		this->_backgroundBlue, this->_backgroundAlpha);

	std::vector<IRenderer*> defaultRenderers = _openGLOptions->GetDefaultRenderers();

	for (int i = 0, size = _openGLOptions->GetDefaultRenderers().size(); i < size; i++) {
		defaultRenderers[i]->DisplayFunc();
	}

	for (int i = 0, size = _renderers.size(); i < size; i++) {
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
	time_t currentTime = time(NULL);
	std::vector<IRenderer*> defaultRenderers = _openGLOptions->GetDefaultRenderers();

	if (difftime(currentTime, this->_lastIdleTime) > 60) {
		GLfloat redModifier = core::GetRandomGLfloat();
		GLfloat greenModifier = core::GetRandomGLfloat(redModifier * 1000);
		GLfloat blueModifier = core::GetRandomGLfloat(greenModifier * 1000);
		GLfloat alphaModifier = core::GetRandomGLfloat(blueModifier * 1000);

		this->_backgroundRed = core::ModifyGLfloat(this->_backgroundRed, redModifier, 0.0, 1.0);
		this->_backgroundGreen = core::ModifyGLfloat(this->_backgroundGreen, greenModifier, 0.0, 1.0);
		this->_backgroundBlue = core::ModifyGLfloat(this->_backgroundBlue, blueModifier, 0.0, 1.0);
		this->_backgroundAlpha = core::ModifyGLfloat(this->_backgroundAlpha, alphaModifier, 0.0, 1.0);

		this->_lastIdleTime = currentTime;

		std::cout << "--- Idle Activation : " << std::endl;
		std::cout << "\t" << redModifier << std::endl;
		std::cout << "\t" << greenModifier << std::endl;
		std::cout << "\t" << blueModifier << std::endl;
		std::cout << "\t" << alphaModifier << std::endl;
	}

	for (int i = 0, size = defaultRenderers.size(); i < size; i++) {
		defaultRenderers[i]->IdleFunc();
	}

	for (int i = 0, size = _renderers.size(); i < size; i++) {
		_renderers[i]->IdleFunc();
	}
}
