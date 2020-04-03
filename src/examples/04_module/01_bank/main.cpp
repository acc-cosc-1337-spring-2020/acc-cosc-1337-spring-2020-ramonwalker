#include "checking_account.h"
#include "savings_account.h"
#include<iostream>
#include<vector>
#include<string>
#include<memory>

using std::cout; using std::cin;
using std::unique_ptr; using std::make_unique;

int main()
{   /* c++ 98
	SavingsAccount* s = new SavingsAccount(500);
	// some more code would go here
	delete s;
	s = nullptr;*/

	// c++ 11
	unique_ptr<BandkAcccount> s = make_unique<SavingsAccount> (90);
	unique_ptr<BankAccount> c = make_unique<CheckingAccouunt> (100);


	CheckingAccount checking;   
	CheckingAccount checking1(90);
	

	std::vector<unique_ptr<BankAccount>> accounts;
	accounts.push_back(std::move(s));
	accounts.push_back(std::move(c));

		for (auto &act : accounts)

		{
			cout << act.get_balance() << "\n";
		}
		
	/*
	BankAccount account(500);
	cin >> account;
	cout << account;
	display_balance(account);

	auto balance = account.get_balance();
	cout << "Balance is: \n" << balance;

	auto amount{ 0 };
	cout << " Enter deposti amount: \n";
	cin >> amount;

	try
	{
		account.deposit(amount);
		cout << "Balance is: " << account.get_balance();
	}

	//account.deposit(amount);
	//cout << "Balance is: " << balance;

	catch (Invalid e)
	{
		cout << e.get_error() << "\n";
	}*/

	return 0;
}