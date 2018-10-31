using room.server.data.Models;
using System;
using System.Collections.Generic;
using System.Text;

namespace room.server.dataaccess
{

	/// <summary>
	/// 
	/// </summary>
	public interface IRenderingManager
	{

		bool AddRendering(Rendering rendering);
		bool AddRenderingLink(RenderingLink renderingLink);
		bool AddRenderingType(RenderingType renderingType);
		bool AddSpace(Space space);

		bool RemoveRendering(Rendering rendering);
		bool RemoveRenderingLink(RenderingLink renderingLink);
		bool RemoveRenderingType(RenderingType renderingType);
		bool RemoveSpace(Space space);

	}

}
