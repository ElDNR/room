#pragma once

#ifndef _RENDERER_H_
#define _RENDERER_H_

namespace renderers
{

	class IRenderer {
	public:
		virtual int getId(void) const = 0;
		virtual void displayFunc(void) = 0;
		virtual void keyboardFunc(unsigned char key, int x, int y) = 0;
		virtual void mouseFunc(int button, int state, int x, int y) = 0;
		virtual void motionFunc(int x, int y) = 0;
		virtual void idleFunc(void) = 0;
	};

	bool operator==(const IRenderer& lhs, const IRenderer& rhs);
}

#endif // !_RENDERER_H_
