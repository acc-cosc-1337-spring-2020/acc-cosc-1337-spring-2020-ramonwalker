#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "decisions.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

int credit_hours;
double credit_points;

TEST_CASE("Verify letter_grade function")
{
	REQUIRE(get_grade_points("A") == 4);
	REQUIRE(get_grade_points("B") == 3);
	REQUIRE(get_grade_points("C") == 2);
	REQUIRE(get_grade_points("D") == 1);
	REQUIRE(get_grade_points("F") == 0);
}

TEST_CASE("Verify credit_hours and credit_points parameter function")
{
	REQUIRE(calculate_gpa(credit_hours, credit_points) == 3.75);
	REQUIRE(calculate_gpa(credit_hours, credit_points) == 3.25);
	REQUIRE(calculate_gpa(credit_hours, credit_points) == 2.0);
}