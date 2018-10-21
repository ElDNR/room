#pragma once

#include "Attributes.h"

using namespace room::client::win::attributes;

namespace room::client::win::collisions
{

	class ICollision : public IIntegerIdentifiable
	{

	public:

		virtual int GetId(void) const = 0;

		/// <summary>
		///  Check if there is already an active collision or not.
		/// </summary>
		virtual bool HasCollision() = 0;

		/// <summary>
		///  Detect wether the spacial cordinate correspond to contact between two areas.
		/// </summary>
		virtual bool DetectCollision(int x, int y, int z) = 0;

	};

}
