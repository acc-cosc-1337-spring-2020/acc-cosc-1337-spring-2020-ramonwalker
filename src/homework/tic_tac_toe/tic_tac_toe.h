#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include<string>
#include<vector>
#include<iostream> 

using std::string;

class TicTacToe
{
public:
	
	bool game_over();
	void start_game(string first_player);
	void mark_board(int positon);
	string get_player() const{ return player; }
	string get_winner() const { return winner; }
	friend std::istream & operator>> (std::istream & in, TicTacToe & p); 
	friend std::ostream & operator<<(std::ostream & out, const TicTacToe & p);

	TicTacToe (int size) : pegs(size*size, " "){}
	TicTacToe() : pegs(9, " ") {};

protected:
	std::vector<std::string> pegs{};
	virtual bool check_column_win();
	virtual bool check_row_win();
	virtual bool check_diagonal_win(); 

private:
	string player;
	string winner;

	void set_next_player();
	void set_winner();
	void clear_board();
	bool check_board_full();
};

#endif

#ifndef INVALID_H
#define INVALID_H

class Invalid
{
public:
	Invalid(std::string msg) : message{ msg } {}
	std::string get_error()const { return message; }

private:
	std::string message;
};

#endif //!TIC_TAC_TOE_H
