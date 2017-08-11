#include "Core.h"
#include "Managers.h"

using namespace room::client::win::core;
using namespace room::client::win::managers;

OpenGLManager _openGLManager;
void OpenGLLoader_RenderCallback(void);

/**
*
*	Application Start
*
*/
int main(int argc, char **argv) {
	OpenGLEvents openGLEvents;
	OpenGLOptions* openGLOptions = new OpenGLOptions(&argc, argv);

	openGLEvents.setDisplayFuncEventHandler(OpenGLLoader_RenderCallback);

	openGLOptions->SetOpenGLEvents(openGLEvents);
	openGLOptions->AddDefaultRenderer(new SquareRenderer());

	return _openGLManager.Load(openGLOptions);
}

void OpenGLLoader_RenderCallback() {
	_openGLManager.DisplayFunc();
}
