#include"tic_tac_toe.h"

#ifndef TicTacToe_3_H
#define TicTacToe_3_H

class TicTacToeThree : public TicTacToe
{
public:
	TicTacToeThree() : TicTacToe(3) {}

private:
	bool check_column_win();
	bool check_row_win();
	bool check_diagonal_win();
};

#endif // !TicTacToe_3_H
