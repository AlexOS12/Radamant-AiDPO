using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using RadamantAPI.Models;
namespace RadamantAPI.Controllers
{
	[Route("api/[controller]")]
	[ApiController]
	public class WicketLogsController : ControllerBase
	{
		private readonly RadamantContext _context;

		public WicketLogsController(RadamantContext context)
		{
			_context = context;
		}
		[HttpGet("{id}")]
		public async Task<ActionResult<WicketLog>> GetWicketLog(int id)
		{
			if (_context.WicketLogs == null)
			{
				return NotFound();
			}
			var log = await _context.WicketLogs.FindAsync(id);

			if (log == null)
			{
				return NotFound();
			}

			return log;
		}
		[HttpGet]
		public async Task<int> ManualPostWicketLog(int wicketId, string message, string lastName, string passport)
		{
			if (_context.WicketLogs == null)
			{
				return 0;
			}
			var person = await _context.Persons.FirstOrDefaultAsync(x => x.LastName == lastName && x.Passport == passport);
			if (person == null)
			{
				return 0;
			}
			WicketLog log = new WicketLog();
			log.Person = person;
			log.WicketId = wicketId;
			log.StatusId = 1;
			log.Message = message;
			_context.WicketLogs.Add(log);
			await _context.SaveChangesAsync();
			return 1;
		}
		private bool WicketLogExists(int id)
		{
			return (_context.WicketLogs?.Any(e => e.Id == id)).GetValueOrDefault();
		}
	}
}
