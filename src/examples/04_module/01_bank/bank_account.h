//bank_account.h
#include<string>

class BankAccount
{
public:
	BankAccount(int b) : balance {b} {} // convention practice guidance for C++ 11...., int b, double r supports comment out code at the end

	int get_balance()const // can only read it because it's const
	{
		return balance; 
	}
	void deposit(int amount);
	void withdraw(int amount);

private:
	int balance{ 0 };  // different variable from creating it somewhere else
	//double rate;
	//int area;
	//int h, w;
};


// normally own file
class Invalid
{
public:
	Invalid(std::string msg) : message{ msg } {}
	std::string get_error()const { return message; }
private:
	std::string message;
};