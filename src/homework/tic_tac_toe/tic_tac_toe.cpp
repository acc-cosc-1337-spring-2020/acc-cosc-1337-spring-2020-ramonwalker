#include "tic_tac_toe.h"

void TicTacToe::start_game(string first_player)
{
	int choice;

	if (choice == "X" || choice == "O")
	{
		return choice;

		else if (choice == "" || choice == '')
		{
			throw Invalid("Must start game first.");
		}
		else
		{
			throw Invalid("Value not in range.");
		}

	}

}

void TicTacToe::mark_board(int positon)
{
	int position[10] = { '1', '2','3','4','5','6','7','8','9' };
	int player = choice, i;
	char mark = (player == 1) ? 'X' : 'O';

	{
		if (choice == 1 && position[1] == '1')

			position[1] = mark;

		else if (choice == 2 && position[2] == '2')

			position[2] = mark;

		else if (choice == 2 && position[2] == '2')

			position[2] = mark;

		else if (choice == 3 && position[3] == '3')

			position[3] = mark;

		else if (choice == 4 && position[4] == '4')

			position[4] = mark;

		else if (choice == 5 && position[5] == '5')

			position[5] = mark;

		else if (choice == 6 && position[6] == '6')

			position[6] = mark;

		else if (choice == 7 && position[7] == '7')

			position[7] = mark;

		else if (choice == 8 && position[8] == '8')

			position[8] = mark;

		else if (choice == 9 && position[9] == '9')

			position[9] = mark;

		else if (choice == "" || choice == '')
		{
			throw Invalid("Position must be 1 to 9.");
		}
		else
		{
			position != mark;
		}
	}
}

void TicTacToe::set_next_player()
{
	if (player == "X")
	{
		next_player = "O";

		else
		{
			next_player = "X";
		}
	}
}