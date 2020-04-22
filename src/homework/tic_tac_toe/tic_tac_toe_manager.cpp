#include "tic_tac_toe_manager.h"
#include<iostream>
#include<string>

//cpp
using std::cout;

void TicTacToeManager::save_game(TicTacToe b)
{
	games.push_back(b);
	update_winner_count(b.get_winner());
}

void TicTacToeManager::get_winner_total(int & x, int & o, int & t)
{
	cout << "X won: " << x_win << "\n"
	<< "O won: " << o_win << "\n"
	<< "Number of ties are: " << ties << "\n";
}

std::ostream & operator<<(std::ostream & out, const TicTacToeManager & manager)
{

		for (auto & game : manager.games)
		{
			out << game <<"\n";
		}

		out << "X won: " << manager.x_win << "\n"
			<< "O won: " << manager.o_win << "\n"
			<< "Number of ties are: " << manager.ties << "\n";

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
