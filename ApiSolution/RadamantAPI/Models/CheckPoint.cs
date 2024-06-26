﻿// <auto-generated> This file has been auto generated by EF Core Power Tools. </auto-generated>
#nullable disable
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using Microsoft.EntityFrameworkCore;

namespace RadamantAPI.Models
{
    public partial class CheckPoint
    {
        public CheckPoint()
        {
            CheckPointStaffs = new HashSet<CheckPointStaff>();
            SecurityMessages = new HashSet<SecurityMessage>();
            Wickets = new HashSet<Wicket>();
        }

        [Key]
        [Column("ID")]
        public int Id { get; set; }
        [Required]
        [StringLength(30)]
        public string Name { get; set; }
        public bool Status { get; set; }

        [InverseProperty("CheckPoint")]
        public virtual ICollection<CheckPointStaff> CheckPointStaffs { get; set; }
        [InverseProperty("CheckPoint")]
        public virtual ICollection<SecurityMessage> SecurityMessages { get; set; }
        [InverseProperty("CheckPoint")]
        public virtual ICollection<Wicket> Wickets { get; set; }
    }
}