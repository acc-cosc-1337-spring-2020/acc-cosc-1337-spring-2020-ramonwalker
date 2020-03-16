#include<string>
#include<vector>

using std::string;

class TicTacToe
{
public:
	
	bool game_over();
	void start_game(string first_player);
	void mark_board(int positon);
	string get_player()const{ return player;}
	void display_board() const;

private:
	string player;
	void set_next_player();
	bool check_board_full();
	void clear_board();
	std::vector < std::string> pegs{ 9, " "};

};

class Invalid
{
public:
	Invalid(std::string msg) : message{ msg } {}
	std::string get_error()const { return message; }
private:
	std::string message;
};