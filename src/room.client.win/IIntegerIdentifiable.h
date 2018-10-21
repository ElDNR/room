#pragma once

namespace room::client::win::attributes
{

	class IIntegerIdentifiable
	{

	public:

		/// <summary>
		///  Allow for a specific integer identifier to be specified.
		/// </summary>
		virtual int GetId(void) const = 0;

	};

}
