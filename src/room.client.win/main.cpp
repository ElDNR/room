#include "Core.h"
#include "Managers.h"

using namespace room::client::win::core;
using namespace room::client::win::managers;

IOpenGLManager* _openGLManager = NULL;

void OpenGLLoader_RenderCallback(void);
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

		openGLEvents.setDisplayFuncEventHandler(OpenGLLoader_RenderCallback);
		openGLEvents.setIdleFuncEventHandler(OpenGLLoader_IdleCallback);

		openGLOptions->SetOpenGLEvents(openGLEvents);
		openGLOptions->AddDefaultRenderer(defaultRenderer);

		result = _openGLManager->Load(openGLOptions);
	}

	return result;
}

#pragma region OpenGL Event Handlers

void OpenGLLoader_RenderCallback() {
	_openGLManager->DisplayFunc();
}

void OpenGLLoader_IdleCallback() {
	_openGLManager->IdleFunc();
}

#pragma endregion
