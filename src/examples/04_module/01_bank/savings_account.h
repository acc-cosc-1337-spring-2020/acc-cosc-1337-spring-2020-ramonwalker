//savings_account.h
#include "bank_account.h"

class SavingsAccount : public BankAccount  // Inherit a class...extending
{
public:
	SavingsAccount() = default;
	explicit SavingsAccount(int b) : BankAccount(b) {}  // putting the balance b into BankAccount so later to put in private for BankAccount
	int get_balance()const { return 5000; }
};
