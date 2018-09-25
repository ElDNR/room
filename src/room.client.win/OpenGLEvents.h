#pragma once

typedef void(*openGLEventsVoidFunc)(void);
typedef void(*openGLEventsKeyboardFunc)(unsigned char key, int x, int y);
typedef void(*openGLEventsMouseFunc)(int button, int state, int x, int y);
typedef void(*openGLEventsMotionFunc)(int x, int y);

namespace room::client::win::core
{

	class OpenGLEvents
	{

	private:

		void(*_displayFunc)(void);
		void(*_keyboardFunc)(unsigned char key, int x, int y);
		void(*_mouseFunc)(int button, int state, int x, int y);
		void(*_motionFunc)(int x, int y);
		void(*_passiveMotionFunc)(int x, int y);
		void(*_idleFunc)(void);

	public:

		OpenGLEvents();
		~OpenGLEvents();

		bool setDisplayFuncEventHandler(openGLEventsVoidFunc displayFunc);
		openGLEventsVoidFunc getDisplayFuncEventHandler(void);

		bool setKeyboardFuncEventHandler(openGLEventsKeyboardFunc keyboardFunc);
		openGLEventsKeyboardFunc getKeyboardFuncEventHandler(void);

		bool setMouseFuncEventHandler(openGLEventsMouseFunc mouseFunc);
		openGLEventsMouseFunc getMouseFuncEventHandler(void);

		bool setMotionFuncEventHandler(openGLEventsMotionFunc motionFunc);
		openGLEventsMotionFunc getMotionFuncEventHandler(void);

		bool setPassiveMotionFuncEventHandler(openGLEventsMotionFunc passiveMotionFunc);
		openGLEventsMotionFunc getPassiveMotionFuncEventHandler(void);

		bool setIdleFuncEventHandler(openGLEventsVoidFunc idleFunc);
		openGLEventsVoidFunc getIdleFuncEventHandler(void);

	};

}
