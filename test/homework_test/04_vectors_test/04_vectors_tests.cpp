#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "vectors.h"
#include<string>

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test for max prime number by ref")
{

	vector<int> numbers{ 3, 8, 1, 99, 1000 };
	int max = get_max_from_vector(numbers);
	REQUIRE(max == 1000);	

	vector<int> numbers2{ 15, 12, 11, 99, 88 };
	int max2 = get_max_from_vector(numbers2);
	REQUIRE(max2 == 99);

	vector<int> numbers3{ 150, 120, 11, 990, 88888 };
	int max3 = get_max_from_vector(numbers3);
	REQUIRE(max3 == 88888);

}

TEST_CASE("Test for number is prime")
{
	REQUIRE(is_prime(2) == true);
	REQUIRE(is_prime(4) == false);
	REQUIRE(is_prime(43) == true);
	REQUIRE(is_prime(44) == false);
}

TEST_CASE("Test for all prime vectors")
{
	
	vector<int> num { 10 };
	vector<int> num1 { 2, 3, 5, 7 };
	REQUIRE(vector_of_primes(10) == num1);

	vector<int> number { 50 };
	vector<int> number2 = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47 };
	REQUIRE(vector_of_primes(50) == number2);	
}