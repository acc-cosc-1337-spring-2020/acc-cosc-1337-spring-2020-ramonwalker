#include "for_ranged.h"
#include<iostream>
#include<vector>

using std::vector;

/*
Write code for loop_string_w_index that accepts a string parameter.
The function uses an indexed for loop to iterate and display the characters in the
string as follows:
for string test displays

t
e
s
t
*/
void loop_string_w_index(const std::string & str)
{
	for (int i = 0; i < str.length(); ++i) // if str equals something then we change the original value
	{
		std::cout << str[i] << "\n";
	}
}


/*
Write code for loop_string_w_index that accepts a string parameter.
The function uses a for ranged loop using auto to iterate and display the characters in the
string as follows:
for string test displays

t
e
s
t
*/
void loop_string_w_auto(const std::string & str) // Note; for notes below this actually wont change because it has const
{
	for (auto ch : str) 
	{
		std::cout << ch << "\n";
	}
}

void loop_string_w_auto_value(std::string & str) // Note; for notes below this actually wont change because it has const
{
	for (auto ch : str)
	{
		ch = 'z';
	}
}

void loop_string_w_auto_ref(std::string &str) // we will be changing the items in the vector
{
	for (auto &ch : str)
	{
		ch = 'z';
	}
}

/* if we have for example void some function(string &str){
}
int main()
{
	string name = "Joe";
	some(name);
} J O E takes three addresses on the Heap;  ch right now is J; were using a auto loop so were looping the string by value
if I say in the loop ch equal z, the out would still be J O E (see Test Case)*/