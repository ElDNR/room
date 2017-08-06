#pragma once

namespace room::client::win::core
{

	class OpenGLOptions
	{

	private:

		int _argc;
		char **_argv;

	public:

		OpenGLOptions(int argc, char **argv);
		~OpenGLOptions();

	};

}
