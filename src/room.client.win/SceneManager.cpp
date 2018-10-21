#include "SceneManager.h"

using namespace room::client::win;
using namespace room::client::win::renderers;
using namespace room::client::win::managers;
using namespace room::client::win::attributes;

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
	return utilities::AddIntegerIdentifiableToVector(&(this->_renderers), renderer);
}

bool SceneManager::RemoveRenderer(IRenderer* renderer) {
	return utilities::RemoveIntegerIdentifiableToVector(&(this->_renderers), renderer);
}

// Public

bool SceneManager::Initialize(void) {
	std::vector<IIntegerIdentifiable*> defaultRenderers = _openGLOptions->GetDefaultRenderers();

	for (int i = 0, size = defaultRenderers.size(); i < size; i++)
	{
		if (((IRenderer*)defaultRenderers[i])->Initialize())
		{
			continue;
		}
		else
		{
			return false;
		}
	}

	for (int i = 0, size = _renderers.size(); i < size; i++)
	{
		if (((IRenderer*)this->_renderers[i])->Initialize())
		{
			continue;
		}
		else
		{
			return false;
		}
	}

	return true;
}

void SceneManager::SetOpenGLOptions(OpenGLOptions* openGLOptions) {
	_openGLOptions = openGLOptions;
}

void SceneManager::ProcessDisplay(void) {
	std::cout << "-- Begin Render Scene" << std::endl;

	//Set the background to be green.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(this->_backgroundRed, this->_backgroundGreen,
		this->_backgroundBlue, this->_backgroundAlpha);

	std::vector<IIntegerIdentifiable*> defaultRenderers = _openGLOptions->GetDefaultRenderers();

	for (int i = 0, size = _openGLOptions->GetDefaultRenderers().size(); i < size; i++) {
		((IRenderer*)defaultRenderers[i])->DisplayFunc();
	}

	for (int i = 0, size = this->_renderers.size(); i < size; i++) {
		((IRenderer*)this->_renderers[i])->DisplayFunc();
	}

	glutSwapBuffers();

	std::cout << "-- End Render Scene" << std::endl;
}

void SceneManager::ProcessKeyboard(unsigned char key, int x, int y) {
	std::vector<IIntegerIdentifiable*> defaultRenderers = _openGLOptions->GetDefaultRenderers();

	for (int i = 0, size = _openGLOptions->GetDefaultRenderers().size(); i < size; i++) {
		((IRenderer*)defaultRenderers[i])->KeyboardFunc(key, x, y);
	}

	for (int i = 0, size = this->_renderers.size(); i < size; i++)
	{
		((IRenderer*)this->_renderers[i])->KeyboardFunc(key, x, y);
	}
}

void SceneManager::ProcessMouse(int button, int state, int x, int y) {
	std::vector<IIntegerIdentifiable*> defaultRenderers = _openGLOptions->GetDefaultRenderers();

	for (int i = 0, size = defaultRenderers.size(); i < size; i++) {
		((IRenderer*)defaultRenderers[i])->MouseFunc(button, state, x, y);
	}

	for (int i = 0, size = _renderers.size(); i < size; i++) {
		((IRenderer*)this->_renderers[i])->MouseFunc(button, state, x, y);
	}
}

void SceneManager::ProcessMotion(int x, int y) {
	std::vector<IIntegerIdentifiable*> defaultRenderers = _openGLOptions->GetDefaultRenderers();

	for (int i = 0, size = defaultRenderers.size(); i < size; i++)
	{
		((IRenderer*)defaultRenderers[i])->MotionFunc(x, y);
	}

	for (int i = 0, size = _renderers.size(); i < size; i++)
	{
		((IRenderer*)this->_renderers[i])->MotionFunc(x, y);
	}
}

void SceneManager::ProcessIdle() {
	// TODO: Launch a worker thread, and make the main thread go to sleep.
	std::this_thread::sleep_for(std::chrono::milliseconds(500));

	time_t currentTime = time(NULL);
	std::vector<IIntegerIdentifiable*> defaultRenderers = _openGLOptions->GetDefaultRenderers();

	if (difftime(currentTime, this->_lastIdleTime) > 30) {
		// TODO: Move this test code somewhere else.

		GLfloat redModifier = utilities::GetRandomGLfloat();
		GLfloat greenModifier = utilities::GetRandomGLfloat((unsigned int)(redModifier * 1000000));
		GLfloat blueModifier = utilities::GetRandomGLfloat((unsigned int)(greenModifier * 1000000));
		GLfloat alphaModifier = utilities::GetRandomGLfloat((unsigned int)(blueModifier * 10000));

		this->_backgroundRed = utilities::ModifyGLfloat(this->_backgroundRed, redModifier, 0.0, 1.0);
		this->_backgroundGreen = utilities::ModifyGLfloat(this->_backgroundGreen, greenModifier, 0.0, 1.0);
		this->_backgroundBlue = utilities::ModifyGLfloat(this->_backgroundBlue, blueModifier, 0.0, 1.0);
		this->_backgroundAlpha = utilities::ModifyGLfloat(this->_backgroundAlpha, alphaModifier, 0.0, 1.0);

		this->_lastIdleTime = currentTime;

		std::cout << "--- Idle Activation : " << std::endl;
		std::cout << "\t" << redModifier << std::endl;
		std::cout << "\t" << greenModifier << std::endl;
		std::cout << "\t" << blueModifier << std::endl;
		std::cout << "\t" << alphaModifier << std::endl;

		// Tells the main loop that there are changes to be displayed.
		// This would ultimately control the frame rate.
		glutPostRedisplay();
	}

	for (int i = 0, size = defaultRenderers.size(); i < size; i++) {
		((IRenderer*)defaultRenderers[i])->IdleFunc();
	}

	for (int i = 0, size = _renderers.size(); i < size; i++) {
		((IRenderer*)this->_renderers[i])->IdleFunc();
	}
}
