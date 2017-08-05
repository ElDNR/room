#pragma once

#ifndef _SHADERLOADER_H_
#define _SHADERLOADER_H_

#include "GL\glew.h"
#include "GL\freeglut.h"
#include <iostream>

namespace core
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

#endif // !_SHADERLOADER_H_
