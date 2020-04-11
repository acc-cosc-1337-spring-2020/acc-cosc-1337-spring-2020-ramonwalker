#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include <iostream>

using std::cin; using std::cout;

int main()
{
	string firstplayer;
	char choice;
	int player;
	bool win = false;
	TicTacToe game;
	TicTacToeManager manager;
	
	do
	{
		do
		{
			player = 1;
			cout << "Welcome to TicTacToe! \n" <<
				"Enter a X or O for the first player to start game: ";
			cin >> firstplayer;
			try
			{
				game.start_game(firstplayer);
			}
			catch (Invalid msg)
			{
				cout << msg.get_error() << "\n";
				player = 0;
			}
		} while (player != 1);

		do
		{
			cout << game;
			cin >> game;
			game.game_over();

		} while (game.game_over() == false);

		manager.save_game(game);
		cout << game;
		cout << "The winner is: " << game.get_winner() << "\n";
		cout << manager;
		cout << "Would you like to continue, y or n: " << "\n";
		cin >> choice;

	} while (choice == 'y' || choice == 'Y');

      cout << manager;

	  return 0;
}
