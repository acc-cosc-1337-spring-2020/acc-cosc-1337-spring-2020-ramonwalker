//bank_account.h
#include<string>
#include<iostream>

#ifndef BANK_ACCOUNT_H   // header guards
#define BANK_ACCOUNT_H

class BankAccount
{
public:
	//BankAccount(int b) : balance {b} {} // convention practice guidance for C++ 11...., int b, double r supports comment out code at the end

	/*int get_balance()const // can only read it because it's const
	{
		return balance; 
	}
	void deposit(int amount);
	void withdraw(int amount);*/

	BankAccount() = default;
	explicit BankAccount(int b) : balance{ b } {}
	int get_balance()const { return balance; }
	void deposit(int amount);
	void withdraw(int amount);
	void open(int amount);
	double get_rate() const{ return rate; }
	friend void display_balance(const BankAccount& b); // this display_balance is not part of the class; friend makes it a free function
	friend std::ostream& operator<<(std::ostream& out, const BankAccount& b);
	friend std::istream& operator>>(std::istream& in, BankAccount& b);

protected:
	int balance{ 0 }; // moved from private, no longer needed in private
			
private:
	//int balance{ 0 };  // different variable from creating it somewhere else
	const int min_balance_to_open{ 25 };
	static double rate;
	static double init_rate() { return .025; }
};

#endif

#ifndef INVALID_H  // header guards
#define INVALID_H

// normally own file
class Invalid
{
public:
	Invalid(std::string msg) : message{ msg } {}
	std::string get_error()const { return message; }
private:
	std::string message;
};

#endif