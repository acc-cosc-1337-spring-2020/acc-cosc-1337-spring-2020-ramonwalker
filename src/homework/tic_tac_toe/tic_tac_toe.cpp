#include "tic_tac_toe.h"

void TicTacToe::start_game(string first_player)
{

	if (first_player == "X" || first_player == "O")
	{
		player = first_player;
	}
	else 
	{
		throw Invalid("Player must be X or O.");
	}
	

	

}

void TicTacToe::mark_board(int position)
{
	if (position < 1 || position > 9)
	{
		throw Invalid("Position must be between 1 and 9.");
	}

	if (player == "")
	{
		throw Invalid(" Must start game first.");
	}
	set_next_player();
}

void TicTacToe::set_next_player()
{
	if (player == "X")
	{
		player = "O";
	}
	else
	{
		player = "X";
	}
	
}