#include "Core.h"
#include "Managers.h"

using namespace room::client::win::core;
using namespace room::client::win::managers;

IOpenGLManager* _openGLManager = NULL;

void OpenGLLoader_RenderCallback(void);
void OpenGLLoader_KeyboardCallback(unsigned char key, int x, int y);
void OpenGLLoader_MouseCallback(int button, int state, int x, int y);
void OpenGLLoader_IdleCallback(void);


/**
*
*	Application Start
*
*/
int main(int argc, char **argv) {
	int result;

	_openGLManager = new OpenGLManager();

	if (NULL == _openGLManager) {
		result = -1;
	} else {
		OpenGLEvents openGLEvents;
		OpenGLOptions* openGLOptions = new OpenGLOptions(&argc, argv);
		IRenderer* defaultRenderer = new SquareRenderer();
		IRenderer* imageRenderer = new ImageRenderer();
		IRenderer* textRenderer = new SimpleAlphaTextRenderer();

		openGLEvents.setDisplayFuncEventHandler(OpenGLLoader_RenderCallback);
		openGLEvents.setIdleFuncEventHandler(OpenGLLoader_IdleCallback);
		openGLEvents.setMouseFuncEventHandler(OpenGLLoader_MouseCallback);
		openGLEvents.setKeyboardFuncEventHandler(OpenGLLoader_KeyboardCallback);

		openGLOptions->SetOpenGLEvents(openGLEvents);

		openGLOptions->AddDefaultRenderer(textRenderer);
		openGLOptions->AddDefaultRenderer(defaultRenderer);
		openGLOptions->AddDefaultRenderer(imageRenderer);

		result = _openGLManager->Load(openGLOptions);

		delete openGLOptions;
	}

	delete _openGLManager;

	return result;
}

#pragma region OpenGL Event Handlers

void OpenGLLoader_RenderCallback() {
	_openGLManager->DisplayFunc();
}

void OpenGLLoader_KeyboardCallback(unsigned char key, int x, int y) {
	_openGLManager->KeyboardFunc(key, x, y);
}

void OpenGLLoader_MouseCallback(int button, int state, int x, int y) {
	_openGLManager->MouseFunc(button, state, x, y);
}

void OpenGLLoader_IdleCallback() {
	_openGLManager->IdleFunc();
}

#pragma endregion
