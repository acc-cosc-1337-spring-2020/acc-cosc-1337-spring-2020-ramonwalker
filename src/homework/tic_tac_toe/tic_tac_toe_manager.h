#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANGER_H

#include<string>
#include<vector>
#include "tic_tac_toe.h"
#include<iostream>

using std::string;

class TicTacToeManager
{
public:

	void save_game(TicTacToe b);
	friend std::ostream & operator <<(std::ostream & out, const TicTacToeManager & manager);
	void get_winner_total(int& x, int& o, int& t);

private:
	std::vector<std::reference_wrapper<TicTacToe>> games;
	int x_win{ 0 }; 
	int o_win{ 0 }; 
	int ties{ 0 }; 
	void update_winner_count(string winner);
};

#endif // !TICTACTOE_MANAGER_H
