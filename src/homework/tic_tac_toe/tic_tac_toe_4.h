#include "tic_tac_toe.h"
#ifndef TicTacToe_4_H
#define TicTacToe_4_H

class TicTacToeFour : public TicTacToe
{
public:
	TicTacToeFour() : TicTacToe(4) {}
	TicTacToeFour(std::vector<string> p, string winner) : TicTacToe(p, winner) {}

private:
	bool check_column_win() override;
	bool check_row_win() override;
	bool check_diagonal_win() override;

};
#endif // !TicTacToe_4_H
