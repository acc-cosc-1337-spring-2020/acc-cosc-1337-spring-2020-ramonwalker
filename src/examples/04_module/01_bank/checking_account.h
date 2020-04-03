//checking_account.h
#included "bank_account.h"

class CheckingAccount : public BankAccount  // Inherit a class...extending
{
public:
	CheckingAccount = default;
	explicit CheckingAccount(int b) : BankAccount(b){}  // putting the balance b into BankAccount so later to put in private for BankAccount
	int get_balance()const { return balance * (1 + get_rate()); }
};