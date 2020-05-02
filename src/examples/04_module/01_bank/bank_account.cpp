#include "bank_account.h"

//bank_account.cpp
int BankAccount::get_balance() const
{
	return balance;
}

void BankAccount::deposit(int amount) // connects to the header file; 
{
	// then provide implementation for it
	if (amount > 0)
	{
		balance += amount;
	}
	else
	{
		throw Invalid("\nAmount must be greater than 0.\n");
	}
}

void BankAccount::withdraw(int amount)
{
	if (amount < 0)
	{
		throw Invalid("\nAmount must be greater than 0. \n");
	}
	else if (amount > balance)
	{
		throw Invalid("\nInsufficient Funds \n");
	}
	else
	{
		balance -= amount;
	}
}

void BankAccount::open(int amount)
{
	if (balance > 0)
	{
		throw InvalidAmount("Account already open, use deposit..");
	}

	if (amount >= min_balance_to_open)
	{
		balance += amount;
	}
	else
	{
		throw InvalidAmount("A deposit of at least 25....");
	}
}

double BankAccount::rate = init_rate(); // allow to access private functions or private class members

void display_balance(const BankAccount & b)
{
	std::cout << "\nBalance is: " << b.balance << "\n";
}

std::ostream & operator<<(std::ostream & out, const BankAccount & b)
{
	out << "\nBalance is: " << b.balance << "\n";

	return out;
}

std::istream & operator>>(std::istream & in, BankAccount & b)
{
	int amount;
	std::cout << "Enter amount to depost: ";
	in >> amount;
	b.deposit(amount);

	return in;
}
