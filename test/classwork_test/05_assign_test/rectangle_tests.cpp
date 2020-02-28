#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "rectangle.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test width by height fators to area")
{
	Rect rectangles(20);
	REQUIRE(rectangles.get_area() == 20);

	Rect rectangles(100);
	REQUIRE(rectangles.get_area() == 100);

	Rect rectangels(1000);
	REQUIRE(rectangles.get_area() == 1000);
}