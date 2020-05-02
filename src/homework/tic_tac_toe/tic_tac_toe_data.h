//data.h
#include<fstream>
#include<string>
#include<tic_tac_toe.h>

#ifndef TIC_TAC_TOE_DATA_H
#define TIC_TAC_TOE_DATA_H

class TicTacToeData : public TicTacToe
{
public:
	void save_pegs(const std::vector<std::unique_ptr<TicTacToe>> & pgs);
	std::vector<std::unique_ptr<TicTacToe>> get_games();

private:
	const std::string file_name{ "TicTacToe.dat" };
};
#endif // !TIC_TAC_TOE_DATA_H
