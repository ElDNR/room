using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using room.server.data.Models;
using room.server.data.WebModels;

namespace room.server.web.Controllers
{

	/// <summary>
	/// 
	/// </summary>
	/// <remarks>
	/// For more information on enabling MVC for empty projects, visit https://go.microsoft.com/fwlink/?LinkID=397860
	/// </remarks>
	[Route("/api/[controller]")]
	public class ScenesController : DbApplicationController<RoomContext>
	{

		public ScenesController(RoomContext dbContext) : base(dbContext)
		{
		}

		[HttpGet()]
		public IEnumerable<string> Index()
		{
			return new List<string>()
			{
				"Test 1",
				"Test 2",
				"Test 3",
				"Test"
			};
		}

		[HttpGet("[action]/{id}")]
		public ResultScene Scene(string name)
		{
			// Return a single scene.
			return new ResultScene()
			{
				Name = "Test",
				Renderings = new List<ResultRendering>()
				{
					new ResultRendering()
					{
						Name = "Test Square",
						Datasource = null,
						RenderingType = new ResultRenderingType()
						{
							Name = "Square",
							Handler = null
						},
						Children = null,
						Color = new ResultColor()
						{
							Description = "Red",
							Red = 1,
							Green = 0,
							Blue = 0
						},
						Space = new ResultSpace()
						{
							Description = "Test Position",
							X = 0.5f,
							Y = 0.5f,
							Z = 0.0f
						}
					}
				}
			};
		}

	}

}
