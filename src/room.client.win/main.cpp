#include "OpenGLLoader.h"

using namespace core;

OpenGLLoader _loader;
void OpenGLLoader_RenderCallback(void);

/**
*
*	Application Start
*
*/
int main(int argc, char **argv) {
	return _loader.Load(argc, argv, OpenGLLoader_RenderCallback);
}

void OpenGLLoader_RenderCallback() {
	_loader.DisplayFunc();
}
