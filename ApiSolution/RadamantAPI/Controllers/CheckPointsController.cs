using System;
using System.Collections.Generic;
using System.Diagnostics;
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
	public class CheckPointsController : ControllerBase
	{
		private readonly RadamantContext _context;

		public CheckPointsController(RadamantContext context)
		{
			_context = context;
		}

		[HttpGet]
		public async Task<ActionResult<IEnumerable<CheckPoint>>> GetCheckPoints()
		{
			Console.WriteLine("CheckPoints GET");
			if (_context.CheckPoints == null)
			{
				return NotFound();
			}
			return await _context.CheckPoints.ToListAsync();
		}

		[HttpGet("{id}")]
		public async Task<ActionResult<CheckPoint>> GetCheckPoint(int id)
		{
			if (_context.CheckPoints == null)
			{
				return NotFound();
			}
			var checkPoint = await _context.CheckPoints.FindAsync(id);

			if (checkPoint == null)
			{
				return NotFound();
			}

			return checkPoint;
		}

		// PUT: api/CheckPoints/5
		// To protect from overposting attacks, see https://go.microsoft.com/fwlink/?linkid=2123754
		[HttpPut("{id}")]
		public async Task<IActionResult> PutCheckPoint(int id, CheckPoint checkPoint)
		{
			if (id != checkPoint.Id)
			{
				return BadRequest();
			}

			_context.Entry(checkPoint).State = EntityState.Modified;

			try
			{
				await _context.SaveChangesAsync();
			}
			catch (DbUpdateConcurrencyException)
			{
				if (!CheckPointExists(id))
				{
					return NotFound();
				}
				else
				{
					throw;
				}
			}

			return NoContent();
		}

		// POST: api/CheckPoints
		// To protect from overposting attacks, see https://go.microsoft.com/fwlink/?linkid=2123754
		[HttpPost]
		public async Task<ActionResult<CheckPoint>> PostCheckPoint(CheckPoint checkPoint)
		{
			if (_context.CheckPoints == null)
			{
				return Problem("Entity set 'RadamantContext.CheckPoints'  is null.");
			}
			_context.CheckPoints.Add(checkPoint);
			await _context.SaveChangesAsync();

			return CreatedAtAction("GetCheckPoint", new { id = checkPoint.Id }, checkPoint);
		}

		// DELETE: api/CheckPoints/5
		[HttpDelete("{id}")]
		public async Task<IActionResult> DeleteCheckPoint(int id)
		{
			if (_context.CheckPoints == null)
			{
				return NotFound();
			}
			var checkPoint = await _context.CheckPoints.FindAsync(id);
			if (checkPoint == null)
			{
				return NotFound();
			}

			_context.CheckPoints.Remove(checkPoint);
			await _context.SaveChangesAsync();

			return NoContent();
		}

		private bool CheckPointExists(int id)
		{
			return (_context.CheckPoints?.Any(e => e.Id == id)).GetValueOrDefault();
		}
	}
}
