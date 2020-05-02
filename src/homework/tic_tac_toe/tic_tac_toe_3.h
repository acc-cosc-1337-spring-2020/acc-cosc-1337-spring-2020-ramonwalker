#include"tic_tac_toe.h"

#ifndef TicTacToe_3_H
#define TicTacToe_3_H

class TicTacToeThree : public TicTacToe
{
public:
	TicTacToeThree() : TicTacToe(3) {}
	TicTacToeThree(std::vector<string> p, string winner) : TicTacToe(p, winner) {}

private:
	bool check_column_win() override;
	bool check_row_win() override;
	bool check_diagonal_win() override;
};

#endif // !TicTacToe_3_H
