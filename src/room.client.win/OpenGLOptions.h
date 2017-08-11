#pragma once

#include "IRenderer.h"
#include "OpenGLEvents.h"

using namespace room::client::win::renderers;

namespace room::client::win::core
{

	class OpenGLOptions
	{

	private:

		int* _argc;
		char** _argv;
		OpenGLEvents _openGLEvents;

		std::vector<IRenderer*> _defaultRenderers;

	public:

		OpenGLOptions(int* argc, char **argv);
		~OpenGLOptions();

		int* GetArgC();
		char** GetArgV();

		void SetOpenGLEvents(OpenGLEvents openGLEvents);
		OpenGLEvents GetOpenGLEvents();

		bool AddDefaultRenderer(IRenderer* renderer);
		std::vector<IRenderer*> GetDefaultRenderers();

	};

}
