#include "bank_account.h"
#include<iostream>
#include<vector>

using std::cout; using std::cin;

int main()

/*auto num{ 0 };
auto num1{ 1.5 };
auto c{ 'c' };
auto flag{ true };    leagacy code*/

{
	std::vector<BankAccount> accounts{ BankAccount(100), BankAccount(200) };
	
		for (auto act : accounts)

		{
			cout << act.get_balance() << "\n";
		}
	
	BankAccount account(500); 

	auto balance = account.get_balance();
	cout << "Balance is: " << balance;

	auto amount{ 0 };
	cout << " Enter deposti amount: ";
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
	}

	return 0;
}