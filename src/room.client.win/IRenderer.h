#pragma once

#ifndef _RENDERER_H_
#define _RENDERER_H_

#include "Attributes.h"
#include "ICamera.h"

using namespace room::client::win::attributes;
using namespace room::client::win::core;

namespace room::client::win::renderers
{

	/// <summary>Responsible for drawing individual graphical elements to the GLUT window.</summary>
	/// <remarks></remarks>
	class IRenderer : public IIntegerIdentifiable {

	public:

		virtual int GetId(void) const = 0;
		virtual bool Initialize(void) = 0;

		virtual void DisplayFunc(void) = 0;
		virtual void DisplayFunc(ICamera* camera) = 0;

		virtual void KeyboardFunc(unsigned char key, int x, int y) = 0;
		virtual void MouseFunc(int button, int state, int x, int y) = 0;
		virtual void MotionFunc(int x, int y) = 0;
		virtual void IdleFunc(void) = 0;

	};

	bool operator==(const IRenderer& lhs, const IRenderer& rhs);

}

#endif // !_RENDERER_H_
