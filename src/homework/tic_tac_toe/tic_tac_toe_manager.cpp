#include "tic_tac_toe_manager.h"
#include<iostream>
#include"tic_tac_toe.h"

//cpp
using std::cout;

void TicTacToeManager::save_game(const TicTacToe b)
{
	games.push_back(b);
	update_winner_count(get_winner());
}

std::ostream & operator<<(std::ostream & out, const TicTacToeManager & manager)
{
		int x_win { 0 }, o_win { 0 }, ties { 0 };

		for (auto & game : manager.games)
		{
			out << game;
			if (game.get_winner() == "X")
			{
				x_win = x_win + 1;
			}
			else if (game.get_winner() == "O")
			{
				o_win = o_win + 1;
			}
			else
			{
				ties = ties + 1;
			}
			out << "X won: " << x_win << "\n"
			<< "O won: " << o_win << "\n"
			<< "Number of ties are: " << ties << "\n";
		}

		return out;
}

void TicTacToeManager::update_winner_count(string winner)
{
	if (winner == "X")
	{
		x_win += 1;
	}
	else if (winner == "O")
	{
		o_win += 1;
	}
	else
	{
		ties += 1;
	}
}
