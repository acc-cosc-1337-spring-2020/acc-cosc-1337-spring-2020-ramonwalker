#include "tic_tac_toe.h"
#include<iostream>

using std::cin; using std::cout;

bool TicTacToe::game_over()
{
	if (check_column_win() == true || check_row_win() == true || check_diagonal_win() == true)
	{
		set_winner();
		return true;
	}
	else if (check_board_full() == true)
	{
		winner = 'C';
		return true;
	}
	return false;
}

void TicTacToe::start_game(string first_player)
{

	if (first_player == "X" || first_player == "O")
	{
		player = first_player;
		clear_board();
	}
	else 
	{
		throw Invalid("Player must be X or O.");
	}
}

void TicTacToe::mark_board(int position)
{
	if (position < 1 || position > pegs.size())
	{
		throw Invalid("Please enter a number from 1 to 9 only.");
	}
	if (player == "") 
	{
		throw Invalid("Must start game first.");
	}
	pegs[position - 1] = player;
	
	if (game_over() == false) 
	{
		set_next_player();
	}
}

std::istream & operator>>(std::istream & in, TicTacToe & p)
{
	int position{ 0 };
	cout << "Player " << p.get_player() << ", please select a postion: " << "\n";
	in >> position;

	try
	{
		p.mark_board(position);
	}
	catch (Invalid msg)
	{
		cout << msg.get_error() << "\n";
	}
	return in;
}

std::ostream & operator<<(std::ostream & out, const TicTacToe & p)
{
	if (p.pegs.size() == 9)
	{
		for (int i = 0; i < 9; i += 3)
		{
			out << p.pegs[i] << "|" << p.pegs[i + 1] << "|" << p.pegs[i + 2] << "\n";
		}
	}
	else if (p.pegs.size() == 16)
	{
		for (int i = 0; i < 16; i += 4)
		{
			out << p.pegs[i] << "|" << p.pegs[i + 1] << "|" << p.pegs[i + 2] << "|" << p.pegs[i + 3] << "\n";
		}
	}
	return out;
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

void TicTacToe::set_winner()
{
	if (player == "X")
	{
		winner = "X";
	}
	else
	{
		winner = "O";
	}
}

bool TicTacToe::check_board_full()
{
	for (std::size_t i = 0; i < pegs.size(); ++i)
	{
		if (pegs[i] == " ")
		{
			return false;
		}
	}
	return true;
}

bool TicTacToe::check_column_win()
{
	return false;
}

bool TicTacToe::check_row_win()
{
		return false;
}

bool TicTacToe::check_diagonal_win()
{
		return false;
}

void TicTacToe::clear_board()
{
	for (auto &peg : pegs)
	{
		peg = " ";
	}
}
