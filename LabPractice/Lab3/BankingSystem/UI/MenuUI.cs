using BankingSystem.Services;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BankingSystem.UI
{
    class MenuUI
    {
        private AccountService service;

        public MenuUI()
        {
            service = new AccountService();
        }

        public void Start()
        {
            while (true)
            {
                Console.WriteLine("1 Create Account");
                Console.WriteLine("2 Deposit");
                Console.WriteLine("3 Withdraw");
                Console.WriteLine("4 Show Account");
                Console.WriteLine("5 Show Transactions");
                Console.WriteLine("6 Show All Accounts");
                Console.WriteLine("7 Save Accounts");
                Console.WriteLine("8 Load Accounts");
                Console.WriteLine("9 Exit");

                Console.Write("Choose option: ");
                int choice = int.Parse(Console.ReadLine());

                if (choice == 1)
                {
                    Console.Write("Enter Account ID: ");
                    int id = int.Parse(Console.ReadLine());

                    Console.Write("Enter Name: ");
                    string name = Console.ReadLine();

                    Console.Write("Enter Permissions: ");
                    uint permissions = uint.Parse(Console.ReadLine());

                    Console.WriteLine("1 Savings Account");
                    Console.WriteLine("2 Current Account");

                    Console.Write("Choose type: ");
                    int type = int.Parse(Console.ReadLine());

                    service.CreateAccount(id, name, permissions, type);
                }

                else if (choice == 2)
                {
                    Console.Write("Enter Account ID: ");
                    int id = int.Parse(Console.ReadLine());

                    Console.Write("Enter Amount: ");
                    double amount = double.Parse(Console.ReadLine());

                    service.Deposit(id, amount);
                }

                else if (choice == 3)
                {
                    Console.Write("Enter Account ID: ");
                    int id = int.Parse(Console.ReadLine());

                    Console.Write("Enter Amount: ");
                    double amount = double.Parse(Console.ReadLine());

                    service.Withdraw(id, amount);
                }

                else if (choice == 4)
                {
                    Console.Write("Enter Account ID: ");
                    int id = int.Parse(Console.ReadLine());

                    service.ShowAccount(id);
                }

                else if (choice == 5)
                {
                    Console.Write("Enter Account ID: ");
                    int id = int.Parse(Console.ReadLine());

                    service.ShowTransactions(id);
                }

                else if (choice == 6)
                {
                    service.ShowAllAccounts();
                }

                else if (choice == 7)
                {
                    service.Save();
                }

                else if (choice == 8)
                {
                    service.Load();
                }

                else if (choice == 9)
                {
                    break;
                }

                Console.WriteLine();
            }
        }
    }
}
