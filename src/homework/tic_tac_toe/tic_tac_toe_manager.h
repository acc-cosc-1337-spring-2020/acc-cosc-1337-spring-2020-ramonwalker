#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANGER_H

#include<string>
#include<vector>
#include "tic_tac_toe.h"
#include "tic_tac_toe_data.h"
#include<memory>

using std::unique_ptr;

class TicTacToeManager : public TicTacToe
{
public:
	TicTacToeManager() = default;
	TicTacToeManager(TicTacToeData & data);
	~TicTacToeManager();

	void save_game(unique_ptr<TicTacToe> & b);
	friend std::ostream & operator <<(std::ostream & out, const TicTacToeManager & manager);
	void get_winner_total(int& x, int& o, int& t);

private:
	int x_win{ 0 }; 
	int o_win{ 0 }; 
	int ties{ 0 }; 
	std::vector<unique_ptr<TicTacToe>> games;
	void update_winner_count(string winner);
	TicTacToeData data;
};

#endif // !TICTACTOE_MANAGER_H
