#include "bank_account.h"
#include<iostream>

//bank_account.cpp

void BankAccount::deposit(int amount) // connects to the header file; 
{
	// then provide implementation for it
	if (amount > 0)
	{
		balance += amount;
	}
	else
	{
		throw Invalid("Amount must be greater than 0.");
	}
}

void BankAccount::withdraw(int amount)
{
}

void BankAccount::open(int amount)
{
	if (amount < min_balance_to_open)
	{	
		throw Invalid("Amount must be at least 25....");
	}
	
	balance += amount;
}

double BankAccount::rate = init_rate(); // allow to access private functions or private class members

void display_balance(const BankAccount & b)
{
	std::cout << "Balance is: " << b.balance << "\n";
}

std::ostream & operator<<(std::ostream & out, const BankAccount & b)
{
	out << "Balance is: " << b.balance << "\n";

	return out;
}

std::istream & operator>>(std::istream & in, BankAccount & b)
{
	int amount;
	std::cout << "Enter amount: ";
	in >> amount;
	b.deposit(amount);

	return in;
}