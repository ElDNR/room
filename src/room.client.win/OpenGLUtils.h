#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "time.h"

#include "GL\glew.h"
#include "GL\freeglut.h"

namespace room::client::win::core
{

	/// <summary>
	/// Provides a random number between 0 and 1 using the time as the seed for the random generator.
	/// </summary>
	GLfloat GetRandomGLfloat(void);

	/// <summary>
	/// Provides a random number between 0 and 1 using the specified value as the seed for the random generator.
	/// </summary>
	GLfloat GetRandomGLfloat(unsigned int seed);

	/// <summary>
	/// Adds or subtracts the modifier from the target value depending on whether the calculation can be maintained within the specified bounds.
	/// </summary>
	GLfloat ModifyGLfloat(GLfloat value, GLfloat modifier, GLfloat min, GLfloat max);

}
