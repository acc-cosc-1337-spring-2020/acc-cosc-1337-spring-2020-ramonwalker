#include "tic_tac_toe.h"
#ifndef TicTacToe_4_H
#define TicTacToe_4_H

class TicTacToeFour : public TicTacToe
{
public:
	TicTacToeFour() : TicTacToe(4) {}

private:
	bool check_column_win();
	bool check_row_win();
	bool check_diagonal_win();

};

#endif // !TicTacToe_4_H
