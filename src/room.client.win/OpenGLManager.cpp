#include "OpenGLManager.h"

using namespace room::client::win::managers;

OpenGLManager::OpenGLManager() {}

OpenGLManager::~OpenGLManager() {}

int OpenGLManager::Load(int argc, char **argv, void(*renderCallback)(void)) {
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Room");

	//Window must be created before using opengl functions, or NULL pointer will occur.
	//When the window is created the OpenGL context is as well.
	std::cout << "GL Version " << glGetString(GL_VERSION) << std::endl;

	GLenum glewStatus = glewInit();
	bool isSupported = GLEW_VERSION_1_1 > 0;

	if (glewStatus == GLEW_OK && isSupported) {
		std::cout << " GLEW Version is 1.1\r\n ";

		glEnable(GL_DEPTH_TEST);

		/*  select clearing (background) color */
		glClearColor(0.0, 0.0, 0.0, 0.0);

		/* initialize viewing values */
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		//register callbacks
		glutDisplayFunc(renderCallback);

		_openGLInitialized = true;
		glutMainLoop();
	}
	else {
		std::cout << " GLEW 1.1 not supported? " << isSupported << std::endl;
		std::cout << " GLEW Status " << glewStatus << std::endl;
	}

	int anyKey;
	std::cout << "Press any key to exit...";
	std::cin >> anyKey;
	return 0;
}

bool OpenGLManager::DisplayFunc() {
	bool result;

	if (_openGLInitialized) {
		_sceneManager.ProcessDisplay();

		result = true;
	}
	else {
		result = false;
	}

	return result;
}

bool OpenGLManager::KeyboardFunc(unsigned char key, int x, int y) {
	bool result;

	if (_openGLInitialized) {
		_sceneManager.ProcessKeyboard(key, x, y);

		result = true;
	}
	else {
		result = false;
	}

	return result;
}

bool OpenGLManager::MouseFunc(int button, int state, int x, int y) {
	bool result;

	if (_openGLInitialized) {
		_sceneManager.ProcessMouse(button, state, x, y);

		result = true;
	}
	else {
		result = false;
	}

	return result;
}

bool OpenGLManager::MotionFunc(int x, int y) {
	bool result;

	if (_openGLInitialized) {
		_sceneManager.ProcessMotion(x, y);

		result = true;
	}
	else {
		result = false;
	}

	return result;
}

bool OpenGLManager::IdleFunc(void) {
	bool result;

	if (_openGLInitialized) {
		_sceneManager.ProcessIdle();

		result = true;
	}
	else {
		result = false;
	}

	return result;
}
