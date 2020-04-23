#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include"tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"
#include <memory>

using std::unique_ptr; using std::make_unique;

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify TicTacToe mark board function")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToeThree>();
	REQUIRE_THROWS_AS(game->mark_board(1), Invalid);
}

TEST_CASE("Verify TicTacToe start game function")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToeThree>();
	REQUIRE_THROWS_AS(game->start_game("A"), Invalid);
}

TEST_CASE("Verify TicTacToe set first player function X")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToeThree>();
	game->start_game("X");

	REQUIRE(game->get_player() == "X");
}

TEST_CASE("Verify TicTacToe set first player function O")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToeFour>();
	game->start_game("O");

	REQUIRE(game->get_player() == "O");
}

TEST_CASE("Verify TicTacToe test game flow O")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToeThree>();
	game->start_game("X");
	REQUIRE(game->get_player() == "X");

	game->mark_board(4);
	REQUIRE(game->get_player() == "O");
}

TEST_CASE("Verify TicTacToe test game flow X")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToeFour>();
	game->start_game("O");
	REQUIRE(game->get_player() == "O");

	game->mark_board(4);
	REQUIRE(game->get_player() == "X");
}

TEST_CASE("Game ends when board is full")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToeThree>();
	game->start_game("X");

	for (int i = 1; i < 6; ++i)
	{
		game->mark_board(i);
		REQUIRE(game->game_over() == false);
	}
	game->mark_board(1);
	game->mark_board(2);
	game->mark_board(3);
	game->mark_board(4);
	game->mark_board(5);
	game->mark_board(6);
	game->mark_board(7);
	game->mark_board(8);
	game->mark_board(9);
	REQUIRE(game->game_over() == true);
}

TEST_CASE("Test Mark Position accepts values from 1 to 9 only")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToeThree>();
	game->start_game("X");
	REQUIRE_THROWS_AS(game->mark_board(0), Invalid);
	REQUIRE_THROWS_AS(game->mark_board(10), Invalid);

	game->mark_board(5);
	REQUIRE(game->game_over() == false);
}

TEST_CASE("Test win by first column 3")
{
	unique_ptr<TicTacToe> board = make_unique<TicTacToeThree>();
	board->start_game("X");
	REQUIRE(board->game_over() == false);
	board->mark_board(1);//X        
	REQUIRE(board->game_over() == false);
	board->mark_board(2);//O          
	REQUIRE(board->game_over() == false);
	board->mark_board(4);//X          
	REQUIRE(board->game_over() == false);
	board->mark_board(5);//O          
	REQUIRE(board->game_over() == false);
	board->mark_board(7);//X
	//X wins
	REQUIRE(board->game_over() == true);
	REQUIRE(board->get_winner() == "X");
}

TEST_CASE("Test win by second column", "[X wins second column]")
{
	unique_ptr<TicTacToe> board = make_unique<TicTacToeThree>();
	board->start_game("X");
	REQUIRE(board->game_over() == false);

	board->mark_board(2);  // X
	REQUIRE(board->game_over() == false);

	board->mark_board(3);  // O
	REQUIRE(board->game_over() == false);

	board->mark_board(5);  // X
	REQUIRE(board->game_over() == false);

	board->mark_board(6);  // O
	REQUIRE(board->game_over() == false);

	board->mark_board(8);  // X
	// X wins
	REQUIRE(board->game_over() == true);
}

TEST_CASE("Test win by third column", "[X wins third column]")
{
	unique_ptr<TicTacToe> board = make_unique<TicTacToeThree>();
	board->start_game("X");
	REQUIRE(board->game_over() == false);

	board->mark_board(3);  // X
	REQUIRE(board->game_over() == false);

	board->mark_board(2);  // O
	REQUIRE(board->game_over() == false);

	board->mark_board(6);  // X
	REQUIRE(board->game_over() == false);

	board->mark_board(5);  // O
	REQUIRE(board->game_over() == false);

	board->mark_board(9);  // X
	// X wins
	REQUIRE(board->game_over() == true);
}

TEST_CASE("Test win by first row", "[X wins first row]")
{
	unique_ptr<TicTacToe> board = make_unique<TicTacToeThree>();
	board->start_game("X");
	REQUIRE(board->game_over() == false);

	board->mark_board(1);  // X
	REQUIRE(board->game_over() == false);

	board->mark_board(4);  // O
	REQUIRE(board->game_over() == false);

	board->mark_board(2);  // X
	REQUIRE(board->game_over() == false);

	board->mark_board(5);  // O
	REQUIRE(board->game_over() == false);

	board->mark_board(3);  // X
	// X wins
	REQUIRE(board->game_over() == true);
}

TEST_CASE("Test win by second row", "[X wins second row]")
{
	unique_ptr<TicTacToe> board = make_unique<TicTacToeThree>();
	board->start_game("X");
	REQUIRE(board->game_over() == false);

	board->mark_board(4);  // X
	REQUIRE(board->game_over() == false);

	board->mark_board(1);  // O
	REQUIRE(board->game_over() == false);

	board->mark_board(5);  // X
	REQUIRE(board->game_over() == false);

	board->mark_board(2);  // O
	REQUIRE(board->game_over() == false);

	board->mark_board(6);  // X
	// X wins
	REQUIRE(board->game_over() == true);
}

TEST_CASE("Test win by third row", "[X wins third row]")
{
	unique_ptr<TicTacToe> board = make_unique<TicTacToeThree>();
	board->start_game("X");
	REQUIRE(board->game_over() == false);

	board->mark_board(7);  // X
	REQUIRE(board->game_over() == false);

	board->mark_board(1);  // O
	REQUIRE(board->game_over() == false);

	board->mark_board(8);  // X
	REQUIRE(board->game_over() == false);

	board->mark_board(2);  // O
	REQUIRE(board->game_over() == false);

	board->mark_board(9);  // X
	// X wins
	REQUIRE(board->game_over() == true);
}

TEST_CASE("Test win diagonally from top left", "[X wins diagonally form top left]")
{
	unique_ptr<TicTacToe> board = make_unique<TicTacToeThree>();
	board->start_game("X");
	REQUIRE(board->game_over() == false);

	board->mark_board(1);  // X
	REQUIRE(board->game_over() == false);

	board->mark_board(2);  // O
	REQUIRE(board->game_over() == false);

	board->mark_board(5);  // X
	REQUIRE(board->game_over() == false);

	board->mark_board(3);  // O
	REQUIRE(board->game_over() == false);

	board->mark_board(9);  // X
	// X wins
	REQUIRE(board->game_over() == true);
}

TEST_CASE("Test win diagonally from bottom left", "[X wins diagonally form bottom left]")
{
	unique_ptr<TicTacToe> board = make_unique<TicTacToeThree>();
	board->start_game("X");
	REQUIRE(board->game_over() == false);

	board->mark_board(7);  // X
	REQUIRE(board->game_over() == false);

	board->mark_board(4);  // O
	REQUIRE(board->game_over() == false);

	board->mark_board(5);  // X
	REQUIRE(board->game_over() == false);

	board->mark_board(1);  // O
	REQUIRE(board->game_over() == false);

	board->mark_board(3);  // X
	// X wins
	REQUIRE(board->game_over() == true);

	// Validate that "X" is winner
	REQUIRE(board->get_winner() == "X");
}

TEST_CASE("Test for no winner")
{
	unique_ptr<TicTacToe> board = make_unique<TicTacToeThree>();
	board->start_game("X");
	REQUIRE(board->game_over() == false);

	board->mark_board(1);  // X
	REQUIRE(board->game_over() == false);

	board->mark_board(2);  // O
	REQUIRE(board->game_over() == false);

	board->mark_board(5);  // X
	REQUIRE(board->game_over() == false);

	board->mark_board(3);  // O
	REQUIRE(board->game_over() == false);

	board->mark_board(6);  // X
	REQUIRE(board->game_over() == false);

	board->mark_board(4);  // O
	REQUIRE(board->game_over() == false);

	board->mark_board(7);  // X
	REQUIRE(board->game_over() == false);

	board->mark_board(9);  // O
	REQUIRE(board->game_over() == false);

	board->mark_board(8);  // X
	// no winner
	REQUIRE(board->game_over() == true);
	REQUIRE(board->get_winner() == "C");
}

TEST_CASE("Test win by first column 4")
{
	unique_ptr<TicTacToe> board = make_unique<TicTacToeFour>();
	board->start_game("X");
	REQUIRE(board->game_over() == false);
	board->mark_board(1);//X        
	REQUIRE(board->game_over() == false);
	board->mark_board(2);//O        
	REQUIRE(board->game_over() == false);
	board->mark_board(5);//X        
	REQUIRE(board->game_over() == false);
	board->mark_board(16);//O
	REQUIRE(board->game_over() == false);
	board->mark_board(9);//X  
	REQUIRE(board->game_over() == false);
	board->mark_board(7);//O  
	REQUIRE(board->game_over() == false);
	board->mark_board(13);//X  win 

	REQUIRE(board->game_over() == true);
	REQUIRE(board->get_winner() == "X");
}

TEST_CASE("Test win by second column 4")
{
	unique_ptr<TicTacToe> board = make_unique<TicTacToeFour>();
	board->start_game("X");
	REQUIRE(board->game_over() == false);
	board->mark_board(2);//X        
	REQUIRE(board->game_over() == false);
	board->mark_board(3);//O        
	REQUIRE(board->game_over() == false);
	board->mark_board(6);//X        
	REQUIRE(board->game_over() == false);
	board->mark_board(16);//O
	REQUIRE(board->game_over() == false);
	board->mark_board(10);//X  
	REQUIRE(board->game_over() == false);
	board->mark_board(7);//O  
	REQUIRE(board->game_over() == false);
	board->mark_board(14);//X  win 

	REQUIRE(board->game_over() == true);
	REQUIRE(board->get_winner() == "X");
}

TEST_CASE("Test win by third column 4")
{
	unique_ptr<TicTacToe> board = make_unique<TicTacToeFour>();
	board->start_game("X");
	REQUIRE(board->game_over() == false);
	board->mark_board(3);//X        
	REQUIRE(board->game_over() == false);
	board->mark_board(1);//O        
	REQUIRE(board->game_over() == false);
	board->mark_board(7);//X        
	REQUIRE(board->game_over() == false);
	board->mark_board(16);//O
	REQUIRE(board->game_over() == false);
	board->mark_board(11);//X  
	REQUIRE(board->game_over() == false);
	board->mark_board(9);//O  
	REQUIRE(board->game_over() == false);
	board->mark_board(15);//X  win 

	REQUIRE(board->game_over() == true);
	REQUIRE(board->get_winner() == "X");
}


TEST_CASE("Test win by fourth column 4")
{
	unique_ptr<TicTacToe> board = make_unique<TicTacToeFour>();
	board->start_game("X");
	REQUIRE(board->game_over() == false);
	board->mark_board(4);//X        
	REQUIRE(board->game_over() == false);
	board->mark_board(1);//O        
	REQUIRE(board->game_over() == false);
	board->mark_board(8);//X        
	REQUIRE(board->game_over() == false);
	board->mark_board(10);//O
	REQUIRE(board->game_over() == false);
	board->mark_board(12);//X  
	REQUIRE(board->game_over() == false);
	board->mark_board(9);//O  
	REQUIRE(board->game_over() == false);
	board->mark_board(16);//X  win 

	REQUIRE(board->game_over() == true);
	REQUIRE(board->get_winner() == "X");
}
TEST_CASE("Test win by first row 4")
{
	unique_ptr<TicTacToe> board = make_unique<TicTacToeFour>();
	board->start_game("X");
	REQUIRE(board->game_over() == false);
	board->mark_board(1);//X        
	REQUIRE(board->game_over() == false);
	board->mark_board(5);//O        
	REQUIRE(board->game_over() == false);
	board->mark_board(2);//X        
	REQUIRE(board->game_over() == false);
	board->mark_board(10);//O
	REQUIRE(board->game_over() == false);
	board->mark_board(3);//X  
	REQUIRE(board->game_over() == false);
	board->mark_board(9);//O  
	REQUIRE(board->game_over() == false);
	board->mark_board(4);//X  win 

	REQUIRE(board->game_over() == true);
	REQUIRE(board->get_winner() == "X");
}

TEST_CASE("Test win by second row 4")
{
	unique_ptr<TicTacToe> board = make_unique<TicTacToeFour>();
	board->start_game("X");
	REQUIRE(board->game_over() == false);
	board->mark_board(5);//X        
	REQUIRE(board->game_over() == false);
	board->mark_board(1);//O        
	REQUIRE(board->game_over() == false);
	board->mark_board(6);//X        
	REQUIRE(board->game_over() == false);
	board->mark_board(2);//O
	REQUIRE(board->game_over() == false);
	board->mark_board(7);//X  
	REQUIRE(board->game_over() == false);
	board->mark_board(3);//O  
	REQUIRE(board->game_over() == false);
	board->mark_board(8);//X  win 

	REQUIRE(board->game_over() == true);
	REQUIRE(board->get_winner() == "X");
}

TEST_CASE("Test win by third row 4")
{
	unique_ptr<TicTacToe> board = make_unique<TicTacToeFour>();
	board->start_game("X");
	REQUIRE(board->game_over() == false);
	board->mark_board(9);//X        
	REQUIRE(board->game_over() == false);
	board->mark_board(1);//O        
	REQUIRE(board->game_over() == false);
	board->mark_board(10);//X        
	REQUIRE(board->game_over() == false);
	board->mark_board(2);//O
	REQUIRE(board->game_over() == false);
	board->mark_board(11);//X  
	REQUIRE(board->game_over() == false);
	board->mark_board(3);//O  
	REQUIRE(board->game_over() == false);
	board->mark_board(12);//X  win 

	REQUIRE(board->game_over() == true);
	REQUIRE(board->get_winner() == "X");
}

TEST_CASE("Test win by fourth row 4")
{
	unique_ptr<TicTacToe> board = make_unique<TicTacToeFour>();
	board->start_game("X");
	REQUIRE(board->game_over() == false);
	board->mark_board(13);//X        
	REQUIRE(board->game_over() == false);
	board->mark_board(1);//O        
	REQUIRE(board->game_over() == false);
	board->mark_board(14);//X        
	REQUIRE(board->game_over() == false);
	board->mark_board(2);//O
	REQUIRE(board->game_over() == false);
	board->mark_board(15);//X  
	REQUIRE(board->game_over() == false);
	board->mark_board(3);//O  
	REQUIRE(board->game_over() == false);
	board->mark_board(16);//X  win 

	REQUIRE(board->game_over() == true);
	REQUIRE(board->get_winner() == "X");
}
TEST_CASE("Test win by diagonal one 4")
{
	unique_ptr<TicTacToe> board = make_unique<TicTacToeFour>();
	board->start_game("X");
	REQUIRE(board->game_over() == false);
	board->mark_board(13);//X        
	REQUIRE(board->game_over() == false);
	board->mark_board(1);//O        
	REQUIRE(board->game_over() == false);
	board->mark_board(10);//X        
	REQUIRE(board->game_over() == false);
	board->mark_board(2);//O
	REQUIRE(board->game_over() == false);
	board->mark_board(7);//X  
	REQUIRE(board->game_over() == false);
	board->mark_board(3);//O  
	REQUIRE(board->game_over() == false);
	board->mark_board(4);//X  win 

	REQUIRE(board->game_over() == true);
	REQUIRE(board->get_winner() == "X");
}

TEST_CASE("Test win by diagonal two 4")
{
	unique_ptr<TicTacToe> board = make_unique<TicTacToeFour>();
	board->start_game("X");
	REQUIRE(board->game_over() == false);
	board->mark_board(1);//X        
	REQUIRE(board->game_over() == false);
	board->mark_board(2);//O        
	REQUIRE(board->game_over() == false);
	board->mark_board(6);//X        
	REQUIRE(board->game_over() == false);
	board->mark_board(4);//O
	REQUIRE(board->game_over() == false);
	board->mark_board(11);//X  
	REQUIRE(board->game_over() == false);
	board->mark_board(3);//O  
	REQUIRE(board->game_over() == false);
	board->mark_board(16);//X  win 

	REQUIRE(board->game_over() == true);
	REQUIRE(board->get_winner() == "X");
}
TEST_CASE("Test for no winner in board 4")
{
	unique_ptr<TicTacToe> board = make_unique<TicTacToeFour>();
	board->start_game("X");
	REQUIRE(board->game_over() == false);
	board->mark_board(1);//X        
	REQUIRE(board->game_over() == false);
	board->mark_board(3);//O        
	REQUIRE(board->game_over() == false);
	board->mark_board(2);//X        
	REQUIRE(board->game_over() == false);
	board->mark_board(6);//O
	REQUIRE(board->game_over() == false);
	board->mark_board(4);//X  
	REQUIRE(board->game_over() == false);
	board->mark_board(8);//O  
	REQUIRE(board->game_over() == false);
	board->mark_board(7);//X
	REQUIRE(board->game_over() == false);
	board->mark_board(10);//O
	REQUIRE(board->game_over() == false);
	board->mark_board(11);//X
	REQUIRE(board->game_over() == false);
	board->mark_board(12);//O
	REQUIRE(board->game_over() == false);
	board->mark_board(5);//X
	REQUIRE(board->game_over() == false);
	board->mark_board(9);//O
	REQUIRE(board->game_over() == false);
	board->mark_board(13);//X
	REQUIRE(board->game_over() == false);
	board->mark_board(14);//O
	REQUIRE(board->game_over() == false);
	board->mark_board(15);//X
	REQUIRE(board->game_over() == false);
	board->mark_board(16);//O
	// no one wins

	REQUIRE(board->game_over() == true);
	REQUIRE(board->get_winner() == "C");
}

/*
TEST_CASE("Verify Test Configuration", "verification") 
{
	REQUIRE(true == true);
}

TEST_CASE("Verify TicTacToe mark board function")
{
	TicTacToe game;
	REQUIRE_THROWS_AS(game.mark_board(1), Invalid);
}

TEST_CASE("Verify TicTacToe start game function")
{
	TicTacToe game;
	REQUIRE_THROWS_AS(game.start_game("A"), Invalid);
}

TEST_CASE("Verify TicTacToe set first player function X")
{
	TicTacToe game;
	game.start_game("X");

	REQUIRE(game.get_player() == "X");
}

TEST_CASE("Verify TicTacToe set first player function O")
{
	TicTacToe game;
	game.start_game("O");

	REQUIRE(game.get_player() == "O");
}

TEST_CASE("Verify TicTacToe test game flow O")
{
	TicTacToe game;
	game.start_game("X");
	REQUIRE(game.get_player() == "X");

	game.mark_board(4);
	REQUIRE(game.get_player() == "O");

}

TEST_CASE("Verify TicTacToe test game flow X")
{
	TicTacToe game;
	game.start_game("O");
	REQUIRE(game.get_player() == "O");

	game.mark_board(4);
	REQUIRE(game.get_player() == "X");

}
TEST_CASE("Game ends when board is full")
{
	TicTacToe game;
	game.start_game("X");

	for (int i = 1; i < 6; ++i)
	{
		game.mark_board(i);
		REQUIRE(game.game_over() == false);
	}
	game.mark_board(1);
	game.mark_board(2);
	game.mark_board(3);
	game.mark_board(4);
	game.mark_board(5);
	game.mark_board(6);
	game.mark_board(7);
	game.mark_board(8);
	game.mark_board(9);
	REQUIRE(game.game_over() == true);
}

TEST_CASE("Test Mark Position accepts values from 1 to 9 only")
{
	TicTacToe game;
	game.start_game("X");
	REQUIRE_THROWS_AS(game.mark_board(0), Invalid);
	REQUIRE_THROWS_AS(game.mark_board(10), Invalid);

	game.mark_board(5);
	REQUIRE(game.game_over() == false);
}

TEST_CASE("Test win by first column 3")
{
	TicTacToeThree board;
	board.start_game("X");
	REQUIRE(board.game_over() == false);
	board.mark_board(1);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(2);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(4);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(5);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(7);//X
	//X wins
	REQUIRE(board.game_over() == true);
	REQUIRE(board.get_winner() == "X");
}

TEST_CASE("Test win by second column", "[X wins second column]")
{
	TicTacToeThree board;
	board.start_game("X");
	REQUIRE(board.game_over() == false);

	board.mark_board(2);  // X
	REQUIRE(board.game_over() == false);

	board.mark_board(3);  // O
	REQUIRE(board.game_over() == false);

	board.mark_board(5);  // X
	REQUIRE(board.game_over() == false);

	board.mark_board(6);  // O
	REQUIRE(board.game_over() == false);

	board.mark_board(8);  // X
	// X wins
	REQUIRE(board.game_over() == true);
}

TEST_CASE("Test win by third column", "[X wins third column]")
{
	TicTacToeThree board;
	board.start_game("X");
	REQUIRE(board.game_over() == false);

	board.mark_board(3);  // X
	REQUIRE(board.game_over() == false);

	board.mark_board(2);  // O
	REQUIRE(board.game_over() == false);

	board.mark_board(6);  // X
	REQUIRE(board.game_over() == false);

	board.mark_board(5);  // O
	REQUIRE(board.game_over() == false);

	board.mark_board(9);  // X
	// X wins
	REQUIRE(board.game_over() == true);
}

TEST_CASE("Test win by first row", "[X wins first row]")
{
	TicTacToeThree board;
	board.start_game("X");
	REQUIRE(board.game_over() == false);

	board.mark_board(1);  // X
	REQUIRE(board.game_over() == false);

	board.mark_board(4);  // O
	REQUIRE(board.game_over() == false);

	board.mark_board(2);  // X
	REQUIRE(board.game_over() == false);

	board.mark_board(5);  // O
	REQUIRE(board.game_over() == false);

	board.mark_board(3);  // X
	// X wins
	REQUIRE(board.game_over() == true);
}

TEST_CASE("Test win by second row", "[X wins second row]")
{
	TicTacToeThree board;
	board.start_game("X");
	REQUIRE(board.game_over() == false);

	board.mark_board(4);  // X
	REQUIRE(board.game_over() == false);

	board.mark_board(1);  // O
	REQUIRE(board.game_over() == false);

	board.mark_board(5);  // X
	REQUIRE(board.game_over() == false);

	board.mark_board(2);  // O
	REQUIRE(board.game_over() == false);

	board.mark_board(6);  // X
	// X wins
	REQUIRE(board.game_over() == true);
}

TEST_CASE("Test win by third row", "[X wins third row]")
{
	TicTacToeThree board;
	board.start_game("X");
	REQUIRE(board.game_over() == false);

	board.mark_board(7);  // X
	REQUIRE(board.game_over() == false);

	board.mark_board(1);  // O
	REQUIRE(board.game_over() == false);

	board.mark_board(8);  // X
	REQUIRE(board.game_over() == false);

	board.mark_board(2);  // O
	REQUIRE(board.game_over() == false);

	board.mark_board(9);  // X
	// X wins
	REQUIRE(board.game_over() == true);
}

TEST_CASE("Test win diagonally from top left", "[X wins diagonally form top left]")
{
	TicTacToeThree board;
	board.start_game("X");
	REQUIRE(board.game_over() == false);

	board.mark_board(1);  // X
	REQUIRE(board.game_over() == false);

	board.mark_board(2);  // O
	REQUIRE(board.game_over() == false);

	board.mark_board(5);  // X
	REQUIRE(board.game_over() == false);

	board.mark_board(3);  // O
	REQUIRE(board.game_over() == false);

	board.mark_board(9);  // X
	// X wins
	REQUIRE(board.game_over() == true);
}

TEST_CASE("Test win diagonally from bottom left", "[X wins diagonally form bottom left]")
{
	TicTacToeThree board;
	board.start_game("X");
	REQUIRE(board.game_over() == false);

	board.mark_board(7);  // X
	REQUIRE(board.game_over() == false);

	board.mark_board(4);  // O
	REQUIRE(board.game_over() == false);

	board.mark_board(5);  // X
	REQUIRE(board.game_over() == false);

	board.mark_board(1);  // O
	REQUIRE(board.game_over() == false);

	board.mark_board(3);  // X
	// X wins
	REQUIRE(board.game_over() == true);

	// Validate that "X" is winner
	REQUIRE(board.get_winner() == "X");
}

TEST_CASE("Test for no winner")
{
	TicTacToeThree board;
	board.start_game("X");
	REQUIRE(board.game_over() == false);

	board.mark_board(1);  // X
	REQUIRE(board.game_over() == false);

	board.mark_board(2);  // O
	REQUIRE(board.game_over() == false);

	board.mark_board(5);  // X
	REQUIRE(board.game_over() == false);

	board.mark_board(3);  // O
	REQUIRE(board.game_over() == false);

	board.mark_board(6);  // X
	REQUIRE(board.game_over() == false);

	board.mark_board(4);  // O
	REQUIRE(board.game_over() == false);

	board.mark_board(7);  // X
	REQUIRE(board.game_over() == false);

	board.mark_board(9);  // O
	REQUIRE(board.game_over() == false);

	board.mark_board(8);  // X
	// no winner
	REQUIRE(board.game_over() == true);
	REQUIRE(board.get_winner() == "C");
}

TEST_CASE("Test win by first column 4")
{
	TicTacToeFour board;
	board.start_game("X");
	REQUIRE(board.game_over() == false);
	board.mark_board(1);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(2);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(5);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(16);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(9);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(7);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(13);//X  win

	REQUIRE(board.game_over() == true);
	REQUIRE(board.get_winner() == "X");
}

TEST_CASE("Test win by second column 4")
{
	TicTacToeFour board;
	board.start_game("X");
	REQUIRE(board.game_over() == false);
	board.mark_board(2);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(3);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(6);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(16);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(10);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(7);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(14);//X  win

	REQUIRE(board.game_over() == true);
	REQUIRE(board.get_winner() == "X");
}

TEST_CASE("Test win by third column 4")
{
	TicTacToeFour board;
	board.start_game("X");
	REQUIRE(board.game_over() == false);
	board.mark_board(3);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(1);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(7);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(16);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(11);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(9);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(15);//X  win

	REQUIRE(board.game_over() == true);
	REQUIRE(board.get_winner() == "X");
}


TEST_CASE("Test win by fourth column 4")
{
	TicTacToeFour board;
	board.start_game("X");
	REQUIRE(board.game_over() == false);
	board.mark_board(4);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(1);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(8);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(10);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(12);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(9);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(16);//X  win

	REQUIRE(board.game_over() == true);
	REQUIRE(board.get_winner() == "X");
}
TEST_CASE("Test win by first row 4")
{
	TicTacToeFour board;
	board.start_game("X");
	REQUIRE(board.game_over() == false);
	board.mark_board(1);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(5);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(2);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(10);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(3);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(9);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(4);//X  win

	REQUIRE(board.game_over() == true);
	REQUIRE(board.get_winner() == "X");
}

TEST_CASE("Test win by second row 4")
{
	TicTacToeFour board;
	board.start_game("X");
	REQUIRE(board.game_over() == false);
	board.mark_board(5);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(1);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(6);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(2);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(7);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(3);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(8);//X  win

	REQUIRE(board.game_over() == true);
	REQUIRE(board.get_winner() == "X");
}

TEST_CASE("Test win by third row 4")
{
	TicTacToeFour board;
	board.start_game("X");
	REQUIRE(board.game_over() == false);
	board.mark_board(9);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(1);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(10);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(2);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(11);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(3);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(12);//X  win

	REQUIRE(board.game_over() == true);
	REQUIRE(board.get_winner() == "X");
}

TEST_CASE("Test win by fourth row 4")
{
	TicTacToeFour board;
	board.start_game("X");
	REQUIRE(board.game_over() == false);
	board.mark_board(13);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(1);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(14);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(2);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(15);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(3);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(16);//X  win

	REQUIRE(board.game_over() == true);
	REQUIRE(board.get_winner() == "X");
}
TEST_CASE("Test win by diagonal one 4")
{
	TicTacToeFour board;
	board.start_game("X");
	REQUIRE(board.game_over() == false);
	board.mark_board(13);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(1);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(10);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(2);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(7);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(3);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(4);//X  win

	REQUIRE(board.game_over() == true);
	REQUIRE(board.get_winner() == "X");
}

TEST_CASE("Test win by diagonal two 4")
{
	TicTacToeFour board;
	board.start_game("X");
	REQUIRE(board.game_over() == false);
	board.mark_board(1);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(2);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(6);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(4);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(11);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(3);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(16);//X  win

	REQUIRE(board.game_over() == true);
	REQUIRE(board.get_winner() == "X");
}
TEST_CASE("Test for no winner in board 4")
{
	TicTacToeFour board;
	board.start_game("X");
	REQUIRE(board.game_over() == false);
	board.mark_board(1);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(3);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(2);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(6);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(4);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(8);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(7);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(10);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(11);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(12);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(5);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(9);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(13);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(14);//O
	REQUIRE(board.game_over() == false);
	board.mark_board(15);//X
	REQUIRE(board.game_over() == false);
	board.mark_board(16);//O
	// no one wins

	REQUIRE(board.game_over() == true);
	REQUIRE(board.get_winner() == "C");
}

*/


