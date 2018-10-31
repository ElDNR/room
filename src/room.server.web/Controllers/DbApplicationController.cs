using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using room.server.data.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace room.server.web.Controllers
{

	public abstract class DbApplicationController<T> : Controller where T : DbContext
	{

		private readonly T _applicationDbContext;

		protected T ApplicationDbContext
		{
			get
			{
				return _applicationDbContext;
			}
		}

		public DbApplicationController(T dbContext)
		{
			this._applicationDbContext = dbContext;

			if(null == dbContext)
			{
				throw new ArgumentNullException("The dbContext parameter must not be NULL!");
			}
		}

	}

}
