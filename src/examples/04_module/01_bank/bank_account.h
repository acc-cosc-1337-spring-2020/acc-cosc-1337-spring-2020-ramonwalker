//bank_account.h
#include<string>
#include<iostream>

#ifndef BANK_ACCOUNT_H   // header guards
#define BANK_ACCOUNT_H

class BankAccount
{
public:
	
	BankAccount() = default; // we want the bank account constructor to do nothing
	explicit BankAccount(int b) : balance{ b } {}
	// pure virtual function makes the class an abstract class ... = 0;
	virtual int get_balance()const = 0;  //{ return balance;   allows to get balance from checking and savings etc. DO NOT USE FOR TICTACTOE
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