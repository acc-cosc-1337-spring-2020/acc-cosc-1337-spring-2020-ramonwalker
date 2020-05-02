//customer.h
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<vector>
#include<memory>
#include "bank_account.h"
#include<iostream>
#include "checking_account.h"
#include "savings_account.h"

class Customer
{
public:

	Customer(std::vector<std::unique_ptr<BankAccount>>& acts) : accounts{ std::move(acts) }
	{

	}
	friend std::ostream& operator<<(std::ostream& out, const Customer& c);
private:

	std::vector <std::unique_ptr<BankAccount>> accounts;
};

#endif  // !CUSTOMER_H