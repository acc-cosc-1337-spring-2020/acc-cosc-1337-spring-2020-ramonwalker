#include<string>
#include<iostream>
#include "for_ranged.h"

int main() 
{
	// C++ can use auto if variable has been assinged
	auto name = "john";
	auto num = 5;
	auto num1 = 5.5;

	std::string str = "joe";

	loop_string_w_index(str);
	loop_string_w_auto(str);

	return 0;
}