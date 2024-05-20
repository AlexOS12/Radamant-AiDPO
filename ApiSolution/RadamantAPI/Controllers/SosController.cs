using Microsoft.AspNetCore.Mvc;
using RadamantAPI.Models;

namespace RadamantAPI.Controllers
{
	[Route("api/[controller]")]
	[ApiController]
	public class SosController : ControllerBase
	{
		private readonly RadamantContext _context;

		public SosController(RadamantContext context)
		{
			_context = context;
		}
		[HttpGet]
		public async Task<int> GetSecurityMessages(int checkPointId)
		{
			if (_context.SecurityMessages == null) return 0;
			var checkPoint = await _context.CheckPoints.FindAsync(checkPointId);
			if (checkPoint == null) return 0;
			SecurityMessage message = new SecurityMessage();
			message.CheckPoint = checkPoint;
			message.Date = DateTime.Now;
			_context.SecurityMessages.Add(message);
			await _context.SaveChangesAsync();
			return 1;
		}
	}
}
