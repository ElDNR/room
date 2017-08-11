#pragma once

#ifndef _RENDERER_H_
#define _RENDERER_H_

namespace room::client::win::renderers
{

	class IRenderer {

	public:

		virtual int GetId(void) const = 0;
		virtual void DisplayFunc(void) = 0;
		virtual void KeyboardFunc(unsigned char key, int x, int y) = 0;
		virtual void MouseFunc(int button, int state, int x, int y) = 0;
		virtual void MotionFunc(int x, int y) = 0;
		virtual void IdleFunc(void) = 0;

	};

	bool operator==(const IRenderer& lhs, const IRenderer& rhs);

}

#endif // !_RENDERER_H_
