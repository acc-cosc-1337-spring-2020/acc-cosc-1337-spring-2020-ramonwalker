//customer.h
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<vector>
#include<memory>
#include "bank_account.h"
#include<iostream>

class Customer
{
public:

	void add_account(std::unique_ptr<BankAccount>& act);
	friend std::ostream& operator<<(std::ostream& out, const Customer& c);
	//void display_accounts()const;  ....use freind function for homework
private:

	std::vector <std::unique_ptr<BankAccount>> accounts;

};

#endif  // !CUSTOMER_H