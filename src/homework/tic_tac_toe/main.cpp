#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"
#include <iostream>
#include <string>

using std::cin; using std::cout;

int main()
{
	string firstplayer, choice;
	int player, x, o, t;
	bool winner;
	std::vector<std::reference_wrapper<TicTacToe>> games;
	TicTacToeManager manager;
		
	do
	{
		cout << "Please enter 3 for a 3x3 TicTacToe game or 4 for a 4x4 TicTacToe game: " << "\n";
		cin >> player;
		
		if (player == 3)
		{
			TicTacToeThree three;
			games.push_back(three);

			while (!(firstplayer == "X" || firstplayer == "O"))
			{
				try
				{
				cout << "Welcome to TicTacToe! \n" <<
					"Enter a X or O for the first player to start game: ";
				cin >> firstplayer;
				three.start_game(firstplayer);
				}
				catch (Invalid msg)
				{
					cout << msg.get_error() << "\n";
				}
			}
			do
			{
				cout << three;
				cin >> three;
				winner = three.game_over();

			} while (three.game_over() == false);

			manager.save_game(three);
			cout << three;
			cout << "\n" << "The winner is: " << three.get_winner() << "\n";
			manager.get_winner_total(x, o, t);
		}
		else if (player == 4)
		{
			TicTacToeFour four;
			games.push_back(four);
			
			while (!(firstplayer == "X" || firstplayer == "O"))
			{
				try
				{
					cout << "Welcome to TicTacToe! \n" <<
						"Enter a X or O for the first player to start game: ";
					cin >> firstplayer;
					four.start_game(firstplayer);
				}
				catch (Invalid msg)
				{
					cout << msg.get_error() << "\n";
					player = 0;
				}
			}
			do
			{
				cout << four;
				cin >> four;
				winner = four.game_over();

			} while (four.game_over() == false);

			manager.save_game(four);
			cout << four;
			cout << "The winner is: " << four.get_winner() << "\n";
			manager.get_winner_total(x, o, t);
		}
		cout << "Would you like to continue, y or n: ";
		cin >> choice;

	} while (choice == "Y" || choice == "y");

return 0;
}
