using BankingSystem.Models;
using BankingSystem.Repositories;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BankingSystem.Services
{
    class AccountService
    {
        private AccountRepository repository;

        public AccountService()
        {
            repository = new AccountRepository();
        }

        public void CreateAccount(int id, string name, uint permissions, int type)
        {
            Account account;

            if (type == 1)
            {
                account = new SavingsAccount(id, name, permissions);
            }
            else
            {
                account = new CurrentAccount(id, name, permissions);
            }

            repository.AddAccount(account);

            Console.WriteLine("Account created successfully.");
        }

        public void Deposit(int id, double amount)
        {
            Account acc = repository.GetAccount(id);

            if (acc == null)
            {
                Console.WriteLine("Account not found.");
                return;
            }

            acc.Deposit(amount);
        }

        public void Withdraw(int id, double amount)
        {
            Account acc = repository.GetAccount(id);

            if (acc == null)
            {
                Console.WriteLine("Account not found.");
                return;
            }

            acc.Withdraw(amount);
        }

        public void ShowAccount(int id)
        {
            Account acc = repository.GetAccount(id);

            if (acc == null)
            {
                Console.WriteLine("Account not found.");
                return;
            }

            acc.ShowAccountInfo();
        }

        public void ShowTransactions(int id)
        {
            Account acc = repository.GetAccount(id);

            if (acc == null)
            {
                Console.WriteLine("Account not found.");
                return;
            }

            acc.ShowTransactions();
        }

        public void ShowAllAccounts()
        {
            repository.ShowAllAccounts();
        }

        public void Save()
        {
            repository.SaveAccounts();
            Console.WriteLine("Accounts saved to file.");
        }

        public void Load()
        {
            repository.LoadAccounts();
            Console.WriteLine("Accounts loaded from file.");
        }
    }
}