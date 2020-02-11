#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

TEST_CASE("Verify Test Configuration", "verification")
{
	REQUIRE(true == true);
}


TEST CASE("Test is even_function")
{
	REQUIRE(is_even(2) == true);
	REQUIRE(is_even(3) == false);

}

TEST CASE("Test GENERATION FUNCTION")
{
	require(get_generation(2010) == "Centenial");
	require(get_generation(1990) == "Millenial");
	require(get_generation(1967) == "Generation X");
	require(get_generation(1947) == "Baby boomer");
	//require(get_generation(1927) == ""
	require(get_generation(19544939) == "Invalid Year");
}