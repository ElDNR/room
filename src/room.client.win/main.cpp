#include "GL\glew.h"
#include "GL\freeglut.h"
#include <iostream>

void renderSchene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.3, 0.3, 0.0);

	glutSwapBuffers();
}

/**
*
*	Application Start
*
*/
int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(500, 500);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Room");

	glewInit();
	if (glewIsSupported("GL_VERSION_4_5")) {
		std::cout << " GLEW Version is 4.5\r\n ";
	}
	else {
		std::cout << " GLEW 4.5 not supported\r\n ";
	}

	glEnable(GL_DEPTH_TEST);

	//register callbacks
	glutDisplayFunc(renderSchene);

	glutMainLoop();

	return 0;
}
