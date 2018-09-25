#include "Core.h"

using namespace room::client::win;

GLfloat core::GetRandomGLfloat() {
	return core::GetRandomGLfloat(time(NULL));
}

GLfloat core::GetRandomGLfloat(unsigned int seed) {
	srand(seed);

	GLfloat dividend = rand() + 0.001f;

	return dividend / RAND_MAX;
}

GLfloat core::ModifyGLfloat(GLfloat value, GLfloat modifier, GLfloat min, GLfloat max) {
	GLfloat result;

	GLfloat randModifier = core::GetRandomGLfloat();

	GLfloat increment = value + modifier;
	GLfloat decrement = value - modifier;

	bool decrementIsValid = decrement >= min;

	if (randModifier > 0.49 && decrementIsValid) {
		result = decrement;
	} else if (increment <= max) {
		result = increment;
	} else if (decrement >= min) {
		result = decrement;
	} else {
		result = value;
	}

	return result;
}
