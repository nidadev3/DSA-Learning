using System;
using System.CodeDom;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BankingSystem.Models
{
 public abstract class Account
    {
        protected int accountId { get; set; }
        protected string name { get; set; }
        protected uint permissions { get; set; }
        protected double[] transactions { get; set; }
        protected int transactionCount { get; set; }

    }
}
