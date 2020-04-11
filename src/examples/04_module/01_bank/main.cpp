#include "checking_account.h"
#include "savings_account.h"
#include "customer.h"
#include "atm.h"
#include<iostream>
#include<vector>
#include<string>
#include<memory>

using std::cout; using std::cin;
using std::unique_ptr; using std::make_unique;

int main()
{ 
	unique_ptr<BankAccount> s = make_unique<SavingsAccount> (90); // heap variable or a pointer behind the scences
	unique_ptr<BankAccount> c = make_unique<CheckingAccount>(100);
	
	Customer cust;
	cust.add_account(s);
	cust.add_account(c);

	ATM atm(cust);
	cout << atm;


	std::vector<unique_ptr<BankAccount>> accounts;
	accounts.push_back(std::move(s));
	accounts.push_back(std::move(c));
/*
		for (auto &act : accounts)

		{
			cout << act->get_balance() << "\n";
		}*/
		
	/*
	ensure that ths is in the loop for...do you want to play again, y then loop

	Ttt game;

	loop for mark board

	game ends
	call manager save game
	
	
	

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