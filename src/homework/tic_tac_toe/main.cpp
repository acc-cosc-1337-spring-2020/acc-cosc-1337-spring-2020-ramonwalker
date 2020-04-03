#include<iostream>
#include "tic_tac_toe.h"
#include<vector>
#include<string>

using namespace std;

int main()
{
	string choice, firstplayer;
	int position;
	TicTacToe game;
	bool winner;
	
do
{
	do
	{
		try
		{
			cout << "Welcome to TicTacToe! \n" <<
				"Enter a X or O for the first player to start game: ";
			cin >> firstplayer;
			game.start_game(firstplayer);
		}
		catch (Invalid msg)
		{
			cout << msg.get_error() << "\n";
		}

		do
		{
			try
			{
				int position;
				cout << "Player, please select a postion: " << "\n";
				cin >> position;
				game.mark_board(position);
				game.display_board();
				game.game_over();
				winner = game.game_over();
			}
			catch (Invalid msg)
			{
				cout << msg.get_error() << "\n";
			}
		} while (winner == false);

		cout << "The winner is: " << game.get_winner() << "\n";

	} while (!(firstplayer == "X" || firstplayer == "O"));

	cout << "Would you like to continue, y or n: ";
	cin >> choice;

} while (choice == "Y" || choice == "y");
	
  return 0;
}
