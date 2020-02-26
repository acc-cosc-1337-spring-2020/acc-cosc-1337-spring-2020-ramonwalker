#include "bank_account.h"
#include<iostream>

using std::cout; using std::cin;

int main()

/*auto num{ 0 };
auto num1{ 1.5 };
auto c{ 'c' };
auto flag{ true };    leagacy code*/

{
	BankAccount account(500); 

	auto balance = account.get_balance();
	cout << "Balance is: " << balance;

	auto amount{ 0 };
	cout << "Enter deposti amount: ";
	cin >> amount;

	account.deposit(amount);
	cout << "Balance is: " << balance;

	return 0;
}