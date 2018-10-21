#include "Core.h"
#include "Renderers.h"
#include "Utilities.h"

using namespace room::client::win;
using namespace room::client::win::core;
using namespace room::client::win::renderers;

OpenGLOptions::OpenGLOptions(int* argc, char** argv)
{
	_argc = argc;
	_argv = argv;
}

OpenGLOptions::~OpenGLOptions()
{
	_defaultRenderers.clear();
}

int* OpenGLOptions::GetArgC() {
	return _argc;
}

char** OpenGLOptions::GetArgV()
{
	return _argv;
}

void OpenGLOptions::SetOpenGLEvents(OpenGLEvents openGLEvents)
{
	_openGLEvents = openGLEvents;
}

OpenGLEvents OpenGLOptions::GetOpenGLEvents() {
	return _openGLEvents;
}

bool OpenGLOptions::AddDefaultRenderer(IRenderer* renderer)
{
	return utilities::AddIntegerIdentifiableToVector(&_defaultRenderers, renderer);
}

std::vector<IIntegerIdentifiable*> OpenGLOptions::GetDefaultRenderers(void) {
	return _defaultRenderers;
}
