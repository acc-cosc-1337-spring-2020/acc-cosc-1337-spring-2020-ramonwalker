#include "tic_tac_toe_data.h"
#include<string>

//cpp

void TicTacToeData::save_pegs(const std::vector<TicTacToe>& pgs)
{
	std::ofstream file_out(file_name, std::ios_base::trunc);

	for (auto peg : pgs)
	{
		file_out << peg.get_player();
		file_out << " ";
		file_out << peg.get_winner();
		file_out << "\n";
	}

	file_out.close();
}

std::vector<TicTacToe> TicTacToeData::get_pegs() const
{
	std::vector<TicTacToe> pegs;
	std::ifstream read_file(file_name);

	string player;
	string winner;

	if (read_file.is_open())
	{
		while (read_file >> player >> winner)
		{
			TicTacToe peg(player, winner);
			pegs.push_back(peg);
		}
	}

	read_file.close();

	return pegs;
}
