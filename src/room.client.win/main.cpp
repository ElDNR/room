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
	return _openGLManager.Load(argc, argv, OpenGLLoader_RenderCallback);
}

void OpenGLLoader_RenderCallback() {
	_openGLManager.DisplayFunc();
}
