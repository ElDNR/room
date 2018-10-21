#include "OpenGLManager.h"

using namespace room::client::win::core;
using namespace room::client::win::managers;

OpenGLManager::OpenGLManager() {}

OpenGLManager::~OpenGLManager() {}

int OpenGLManager::Load(OpenGLOptions* openGLOptions) {
	if (_openGLInitialized) {
		std::cout << "OpenGL is already initialized!" << std::endl;
		return -1;
	}

	if (NULL == openGLOptions || NULL == openGLOptions->GetArgC() ||
		NULL == openGLOptions->GetArgV()) {
		std::cout << "Missing OpenGL Options!" << std::endl;

		return -1;
	}

	_sceneManager = new SceneManager();

	if (NULL == _sceneManager) {
		std::cout << "Unable to create the scene manager!" << std::endl;

		return -1;
	}

	_sceneManager->SetOpenGLOptions(openGLOptions);

	glutInit(openGLOptions->GetArgC(), openGLOptions->GetArgV());

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

		OpenGLEvents openGLEvents = openGLOptions->GetOpenGLEvents();

		glEnable(GL_DEPTH_TEST);

		/*  select clearing (background) color */
		glClearColor(0.0, 0.0, 0.0, 0.0);

		/* initialize viewing values */
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		//register callbacks
		if (NULL != openGLEvents.getDisplayFuncEventHandler()) {
			glutDisplayFunc(openGLEvents.getDisplayFuncEventHandler());
		}

		if (NULL != openGLEvents.getIdleFuncEventHandler()) {
			glutIdleFunc(openGLEvents.getIdleFuncEventHandler());
		}

		if (NULL != openGLEvents.getKeyboardFuncEventHandler()) {
			glutKeyboardFunc(openGLEvents.getKeyboardFuncEventHandler());
		}

		if (NULL != openGLEvents.getMotionFuncEventHandler()) {
			glutMotionFunc(openGLEvents.getMotionFuncEventHandler());
		}

		if (NULL != openGLEvents.getPassiveMotionFuncEventHandler()) {
			glutPassiveMotionFunc(openGLEvents.getPassiveMotionFuncEventHandler());
		}

		if (NULL != openGLEvents.getMouseFuncEventHandler()) {
			glutMouseFunc(openGLEvents.getMouseFuncEventHandler());
		}

		if (this->_sceneManager->Initialize()) {
			this->_openGLInitialized = true;
		}
		else {
			this->_openGLInitialized = false;

			std::cout << "Failed to initialize renderings..." << std::endl;
		}

		// delegate the main loop

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
		_sceneManager->ProcessDisplay();

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
		_sceneManager->ProcessKeyboard(key, x, y);

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
		_sceneManager->ProcessMouse(button, state, x, y);

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
		_sceneManager->ProcessMotion(x, y);

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
		_sceneManager->ProcessIdle();

		result = true;
	}
	else {
		result = false;
	}

	return result;
}
