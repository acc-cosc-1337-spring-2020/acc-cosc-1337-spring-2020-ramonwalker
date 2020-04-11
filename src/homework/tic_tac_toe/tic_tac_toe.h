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
	string get_player() const{ return player;}
	//void display_board() const;
	string get_winner() const { return winner; } // added const
	friend std::istream & operator>> (std::istream & in, TicTacToe & p); 
	friend std::ostream & operator>> (std::ostream & out, const TicTacToe & p);

private:
	string player;
	string winner;
	void set_next_player();
	bool check_board_full();
	bool check_column_win();
	bool check_row_win();
	bool check_diagonal_win();
	void set_winner();
	void clear_board();
	std::vector < std::string> pegs{ 9, " "};

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
