#include "bank_account.h"
#include<iostream>
#include<vector>
#include<string>

using std::cout; using std::cin;

int main()

/*auto num{ 0 };
auto num1{ 1.5 };
auto c{ 'c' };
auto flag{ true };    leagacy code*/

{
	

	/*std::vector<BankAccount> accounts{ BankAccount(100), BankAccount(200) };
	
		for (auto act : accounts)

		{
			cout << act.get_balance() << "\n";
		}*/
	

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
	}

	return 0;
}