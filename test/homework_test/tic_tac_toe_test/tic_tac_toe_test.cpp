#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test can't call mark board before start of game")
{
	TicTacToe vector<int> postion{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	REQUIRE(msg.get_choice() == { 1, 2, 3, 4, 5, 6, 7, 8, 9};

	REQUIRE_THROWS_AS(board.position{ 10 }, Invalid);
	REQUIRE(msg.get_choice() == {10};
}

TEST_CASE("Test for first player to X")
{
	std::string firstplayer == "X";
	REQUIRE(msg.get_choice() == "X";

	REQUIRE_THROWS_AS(choice.player != "X", Invalid);
	REQUIRE(msg.get_error() == "X";

}

TEST_CASE("Test set first player to O")
{
	std::string firstplayer == "O";
	REQUIRE(msg.get_choice() == "O";

	REQUIRE_THROWS_AS(choice.player != "O", Invalid);
	REQUIRE(msg.get_error() == "O";
}

TEST_CASE("Test start game with X game flow")
{
	std::string startgame == "X";
	REQUIRE(msg.get_choice() == "X";

	RREQUIRE_THROWS_AS(choice.player != "X", Invalid);
	REQUIRE(msg.get_error() != "X";
}

TEST_CASE("Test start game with O game flow")
{
	std::string startgame == "O";
	REQUIRE(msg.get_choice() != "O";

	REQREQUIRE_THROWS_AS(choice.player != "O", Invalid);
	REQUIRE(msg.get_error() == != "O";
}