#include<iostream>
#include "tic_tac_toe.h"
#include<vector>

using std namespace;

int main()
{
	cout << "Welcome to TicTacToe. Please enter an X or O.;

	void start_game();

	cout << "Would you like to continue? 1 to stop." << "\n";
	cin << answer;

	while (answer != 1)
	{
		cout << "Enter a number from 1-9 to place your spot on the board.";
		cin >> position[] >> "\n";

		try
		
			mark_board(postion[]);

		}
		catch (Invalid msg)
		{
			cout << msg.get_error();
		}
			
	}
	return 0;
}