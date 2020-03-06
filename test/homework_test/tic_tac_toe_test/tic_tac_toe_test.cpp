#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test mark board for Tic Tac Toe game")
{
	vector<int> positon{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	REQUIRE(msg.get_choice() == { 1, 2, 3, 4, 5, 6, 7, 8, 9};

	REQUIRE_THROWS_AS(board.position{ 10 }, TicTacToe);
	REQUIRE(msg.get_choice() == {10};
}