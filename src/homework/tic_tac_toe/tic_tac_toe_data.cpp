#include "tic_tac_toe_data.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"

//cpp

void TicTacToeData::save_pegs(const std::vector<std::unique_ptr<TicTacToe>>& pgs)
{
	std::ofstream file_out(file_name, std::ios_base::trunc);
	for (auto peg : pegs)
	{
		//file_out << get_pegs;
		file_out << " ";
		file_out << get_winner();
		file_out << "\n";
	}
	file_out.close();
}

std::vector<std::unique_ptr<TicTacToe>> TicTacToeData::get_games()
{
	std::ifstream read_file(file_name);
	std::vector<std::unique_ptr<TicTacToe>> boards;

	while (read_file.is_open())
	{
		std::vector<std::string> pegs;
		string line;

		while (getline(read_file, line))
		{
			for (int ch = 0; ch < line.size() - 1; ch++)
			{
				string chString(1, line[ch]);
				pegs.push_back(chString);
			}
			string winner = pegs[-1];
			std::unique_ptr<TicTacToe> board;

			if (pegs.size() <= 9)
			{
				board = std::make_unique<TicTacToeThree>(pegs, winner);
			}
			else if (pegs.size() <= 16)
			{
				board = std::make_unique<TicTacToeFour>(pegs, winner);
			}
			boards.push_back(std::move(board));
		}
		read_file.close();
	}
	return boards;
}
