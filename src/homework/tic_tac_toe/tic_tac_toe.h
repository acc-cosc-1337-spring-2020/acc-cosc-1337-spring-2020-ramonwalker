#include<string>

class TicTacToe
{
public:
	TicTacToe(string msg) : message { msg } {}

	string get_message()const
	{
		return message;
	}
	void start_game(string first_player);
	void mark_board(int positon);

};

class Invalid
{
public:
	Invalid(std::string msg) : message{ msg } {}
	std::string get_error()const { return message; }
private:
	std::string message;
};