#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
//include "decisions.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

/*TEST_CASE("Verify letter_grade function")
{
	REQUIRE(get_grade_point("A") == 4);
	REQUIRE(get_grade_point("B") == 3)
	REQUIRE(get_grade_point("C") == 2)
	REQUIRE(get_grade_point("D") == 1)
	REQUIRE(get_grade_point("F") == 0)
}

TEST_CASE("Verify credit_hours and credit_points parameter function")
{
	REQUIRE(calculate_gpa(credit_points, credit_hours) == 3.75);
	REQUIRE(calculate_gpa(credit_points, credit_hours) == 3.25);
	REQUIRE(calculate_gpa(credit_points, credit_hours) == 2.0);
}*/
