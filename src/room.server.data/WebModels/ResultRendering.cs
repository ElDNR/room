using System;
using System.Collections.Generic;
using System.Text;

namespace room.server.data.WebModels
{

	public class ResultRendering
	{

		public string Name { get; set; }
		public string Datasource { get; set; }

		public ResultRenderingType RenderingType { get; set; }

		public ResultColor Color { get; set; }
		public ResultSpace Space { get; set; }

		public IEnumerable<ResultRendering> Children { get; set; }

	}

}
