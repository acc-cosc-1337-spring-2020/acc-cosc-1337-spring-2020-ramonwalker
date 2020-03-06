#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "bank_account.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify Test Configuration", "verification")
{
	BankAccount account(500);

	REQUIRE(account.get_balance() == 500);
}

TEST_CASE("Test Bank account deposit")
{
	BankAccount account(500);
	REQUIRE(account.get_balance() == 500);

	
	REQUIRE_THROWS_AS(account.deposit(-50), Invalid);
	REQUIRE(account.get_balance() == 550);
}

TEST_CASE("Test Bank account withdrawal")
{
	BankAccount account(500);

	account.withdraw(50);
	REQUIRE(account.get_balance() == 450);

	REQUIRE_THROWS_AS(account.withdraw(-1), Invalid);
	REQUIRE(account.get_balance() == 450);

	REQUIRE_THROWS_AS(account.withdraw(451), Invalid);
	REQUIRE(account.get_balance() == 450);
}

TEST_CASE("")
{

	REQUIRE_THROWS_AS() ==
}

TEST_CASE("Test BankAcount static rate initialization")
{
	BankAccount account;
	REQUIRE(account.get_rate() == 0.025);
}