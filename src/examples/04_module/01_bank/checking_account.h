//checking_account.h
#include "bank_account.h"
ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

class CheckingAccount : public BankAccount  // Inherit a class...extending
{
public:
	CheckingAccount() = default;
	explicit CheckingAccount(int b) : BankAccount(b){}  // putting the balance b into BankAccount so later to put in private for BankAccount
	int get_balance()const { return balance * (1 + get_rate()); }
};
endif // !CHECKING_ACCOUNT_H