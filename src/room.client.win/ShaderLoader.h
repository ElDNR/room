#pragma once

#include "GL\glew.h"
#include "GL\freeglut.h"
#include <iostream>

namespace room::client::win::shaders
{

	class ShaderLoader
	{

	private:
		/**/
		std::string ReadShader(char *filename);

		/**/
		GLuint CreateShader(GLenum shareType, std::string source, char* shaderName);

	public:

		ShaderLoader(void);

		~ShaderLoader(void);

		GLuint CreateProgram(char* vertexShaderFilename, char* fragmentShaderFilename);

	};

}
