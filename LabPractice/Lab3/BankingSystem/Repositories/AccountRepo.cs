using BankingSystem.Models;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BankingSystem.Repositories
{
    class AccountRepository
    {
        private Account[] accounts;
        private int count;

        public AccountRepository()
        {
            accounts = new Account[100];
            count = 0;
        }

        public void AddAccount(Account account)
        {
            if (count < accounts.Length)
            {
                accounts[count] = account;
                count++;
            }
        }

        public Account GetAccount(int id)
        {
            for (int i = 0; i < count; i++)
            {
                if (accounts[i].GetAccountId() == id)
                {
                    return accounts[i];
                }
            }
            return null;
        }

        public void ShowAllAccounts()
        {
            for (int i = 0; i < count; i++)
            {
                accounts[i].ShowAccountInfo();
                Console.WriteLine();
            }
        }

        public void SaveAccounts()
        {
            StreamWriter writer = new StreamWriter("accounts.txt");

            for (int i = 0; i < count; i++)
            {
                Account acc = accounts[i];

                string type = acc.GetType().Name;

                writer.WriteLine(
                    type + "," +
                    acc.GetAccountId() + "," +
                    acc.GetName() + "," +
                    acc.GetBalance() + "," +
                    acc.GetPermissions()
                );
            }

            writer.Close();
        }

        public void LoadAccounts()
        {
            if (!File.Exists("accounts.txt"))
            {
                return;
            }

            StreamReader reader = new StreamReader("accounts.txt");

            while (!reader.EndOfStream)
            {
                string line = reader.ReadLine();
                string[] parts = line.Split(',');

                string type = parts[0];
                int id = int.Parse(parts[1]);
                string name = parts[2];
                double balance = double.Parse(parts[3]);
                uint permissions = uint.Parse(parts[4]);

                Account acc;

                if (type == "SavingsAccount")
                {
                    acc = new SavingsAccount(id, name, permissions);
                }
                else
                {
                    acc = new CurrentAccount(id, name, permissions);
                }

                acc.SetBalance(balance);

                AddAccount(acc);
            }

            reader.Close();
        }
    }
}