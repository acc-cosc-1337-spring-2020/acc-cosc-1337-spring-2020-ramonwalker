#include<iostream>
#include "tic_tac_toe.h"
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	string choice, firstplayer;
	TicTacToe game;

	void start_game();

	cout << "Welcome to TicTacToe! \n" <<
	"Enter a X or O for first player to start game: ";
	cin >> choice;

	while (choice == "X" || choice == "O")
	{
		try
		{
			game.start_game(firstplayer);
		}
		catch (Invalid msg)
		{
			cout << msg.get_error() << "\n";
		}
	}
		do
		{
			try
			{
				int position;
				cout << "Please select a postion: " << "\n";
				cin >> position;
				game.mark_board(position);
			}
			catch (Invalid msg)
			{
				cout << msg.get_error() << "\n";
			}
			cout << "Do you want to continue: ";
			cin >> choice;
		} while (choice == "Y" || choice == "y");

		return 0;
}