#include<string>
using std::string;
class TicTacToe
{
public:
	

	void start_game(string first_player);
	void mark_board(int positon);
	string get_player()const{ return player;}

private:
	string player;
	void set_next_player();

};

class Invalid
{
public:
	Invalid(std::string msg) : message{ msg } {}
	std::string get_error()const { return message; }
private:
	std::string message;
};