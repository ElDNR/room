#pragma once

namespace room::client::win::core
{

	class OpenGLEvents
	{

	public:

		void(*_displayFunc)(void);
		void(*_keyboardFunc)(void);
		void(*_mouseFunc)(void);
		void(*_motionFunc)(void);
		void(*_idleFunc)(void);

		OpenGLEvents();
		~OpenGLEvents();

		void setDisplayFuncEventHandler(void(*displayFunc)(void)) {
			_displayFunc = displayFunc;
		}

		void setKeyboardFuncEventHandler(void(*keyboardFunc)(void)) {
			_keyboardFunc = keyboardFunc;
		}

		void setMouseFuncEventHandler(void(*mouseFunc)(void)) {
			_mouseFunc = mouseFunc;
		}

		void setMotionFuncEventHandler(void(*motionFunc)(void)) {
			_motionFunc = motionFunc;
		}

		void setIdleFuncEventHandler(void(*idleFunc)(void)) {
			_idleFunc = idleFunc;
		}

	};

}
