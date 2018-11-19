using System;
using System.Collections.Generic;
using System.Text;

namespace room.server.data.WebModels
{

	public class ResultScene
	{

		public string Name { get; set; }

		public IEnumerable<ResultRendering> Renderings { get; set; }

	}

}
