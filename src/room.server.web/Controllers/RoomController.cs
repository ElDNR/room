using Microsoft.AspNetCore.Mvc;
using room.server.data.Models;
using room.server.data.WebModels;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace room.server.web.Controllers
{

	[Route("/api/[controller]")]
	public class RoomController : DbApplicationController<RoomContext>
	{

		public RoomController(RoomContext dbContext) : base(dbContext)
		{
		}

		[HttpPost("[action]")]
		public bool Login([FromBody] User user)
		{
			bool result;
			if(null != user && null != user.UserName && user.UserName.Length > 0)
			{
				this.HttpContext.Session.Set("RoomUserName", Encoding.Default.GetBytes(user.UserName));

				result = true;
			}
			else
			{
				result = false;
			}

			return result;
		}

		[HttpGet("[action]")]
		public bool LoggedIn()
		{
			byte[] userName = null;

			return this.HttpContext.Session.IsAvailable &&
				this.HttpContext.Session.TryGetValue("RoomUserName", out userName) &&
				null != userName && userName.Length > 0;
		}

	}

}
