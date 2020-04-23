#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"
#include <iostream>
#include <string>
#include <memory>

using std::unique_ptr; using std::make_unique;
using std::cin; using std::cout;

int main()
{
	string firstplayer, choice;
	int gametype, x, o, t;
	bool winner;
	unique_ptr<TicTacToe> game;

	unique_ptr<TicTacToeManager> manager = make_unique<TicTacToeManager>();

	do
	{
		cout << "Please enter 3 for a 3x3 TicTacToe game or 4 for a 4x4 TicTacToe game: " << "\n";
		cin >> gametype;
		
		if (gametype == 3)
		{
			game = make_unique<TicTacToeThree>();
		}
		else if (gametype == 4)
		{
			game = make_unique<TicTacToeFour>();
		}
		cout << "Welcome to TicTacToe! \n" <<
				"Enter a X or O for the first player to start game: ";
		cin >> firstplayer;
		game->start_game(firstplayer);

		while (game->game_over() == false)
		{
			cin >> *game;
			cout << *game;
		}
		manager->save_game(game);
		cout << "\n" << "The winner is: " << "\n";
		manager->get_winner_total(x, o, t);
		cout << "Would you like to continue, y or n: ";
		cin >> choice;

	} while (choice == "Y" || choice == "y");
	  cout << *manager;

return 0;
}
