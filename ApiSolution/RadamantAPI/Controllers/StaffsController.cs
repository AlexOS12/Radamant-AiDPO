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
		[HttpGet]
		public async Task<int> GetStaff(string login, string pass)
		{
			if (_context.Staff == null)
			{
				return -1;
			}
			var staff = await _context.Staff.FirstOrDefaultAsync(x => x.Login == login && x.PassHash == pass);
			if (staff == null || !staff.Status)
			{
				return -1;
			}
			return staff.Id;
		}
	}
}
