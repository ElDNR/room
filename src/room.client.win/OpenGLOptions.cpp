#include "Core.h"
#include "Renderers.h"

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
	bool result = true;

	for (int i = 0, size = _defaultRenderers.size(); i < size; i++) {
		if (_defaultRenderers[i]->GetId() == renderer->GetId()) {
			result = false;

			break;
		}
	}

	if (result) {
		_defaultRenderers.push_back(renderer);
	}

	return result;
}

std::vector<IRenderer*> OpenGLOptions::GetDefaultRenderers() {
	return _defaultRenderers;
}
