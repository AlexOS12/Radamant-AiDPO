using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using RadamantAPI.Models;

namespace RadamantAPI.Controllers
{
	[Route("api/[controller]")]
	[ApiController]
	public class StaffsController : ControllerBase
	{
		private readonly RadamantContext _context;

		public StaffsController(RadamantContext context)
		{
			_context = context;
		}

		// GET: api/Staffs
		[HttpGet]
		public async Task<ActionResult<IEnumerable<Staff>>> GetStaff()
		{
			if (_context.Staff == null)
			{
				return NotFound();
			}
			return await _context.Staff.ToListAsync();
		}

		// GET: api/Staffs/5
		[HttpGet("{id}")]
		public async Task<ActionResult<Staff>> GetStaff(string login, string pass)
		{
			if (_context.Staff == null)
			{
				return NotFound();
			}
			var staff = await _context.Staff.FirstOrDefaultAsync(x => x.Login == login && x.PassHash == pass);

			if (staff == null || !staff.Status)
			{
				return NotFound();
			}

			return staff;
		}

		private bool StaffExists(int id)
		{
			return (_context.Staff?.Any(e => e.Id == id)).GetValueOrDefault();
		}
	}
}
