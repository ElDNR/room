using Microsoft.AspNetCore.Mvc;
using room.server.data.Models;

namespace room.server.web.Controllers
{

	/// <summary>
	/// 
	/// </summary>
	[Route("/api/[controller]")]
	public class RenderingsController : DbApplicationController<RoomContext>
	{

		public RenderingsController(RoomContext dbContext) : base(dbContext)
		{
		}

	}

}
