//data.h
#include<fstream> // added for Hmwk 11
#include<string>
#include<vector>
#include<tic_tac_toe.h>

#ifndef TIC_TAC_TOE_DATA_H
#define TIC_TAC_TOE_DATA_H

class TicTacToeData
{
public:
	void save_pegs(const std::vector<TicTacToe> & pgs);
	std::vector<TicTacToe> get_pegs()const;

protected:
	const std::string file_name{ "TicTacToe.dat" };
};

#endif // !TIC_TAC_TOE_DATA_H




