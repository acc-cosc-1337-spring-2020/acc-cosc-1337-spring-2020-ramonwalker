#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "rectangle.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test width by height fators to area")
{
	Rect rectangle1(4, 5);
	REQUIRE(rectangle1.get_area() == 20);

	Rect rectangle2(10, 10);
	REQUIRE(rectangle2.get_area() == 100);

	Rect rectangle3(100, 10);
	REQUIRE(rectangle3.get_area() == 1000);
}