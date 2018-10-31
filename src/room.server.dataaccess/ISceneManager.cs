using room.server.data.Models;
using System;
using System.Collections.Generic;
using System.Text;

namespace room.server.dataaccess
{

	public interface ISceneManager
	{

		bool AddScene(Scene scene);
		bool AddSceneRenderingLink(SceneRenderingLink sceneRenderingLink);
		
		bool RemoveScene(Scene scene);
		bool RemoveSceneRenderingLink(SceneRenderingLink sceneRenderingLink);

	}

}
