#include "vector.h"
#include<iostream>
#include<vector>

int main() 
{
	/* lvalue - can be a reference or has an address that is accessible
	int num;
	int & num_ref = num; // righ here accessible 
	// rvalue
	int num = 5; // 5 is an rvalue
	int& num_5 = 5;
	int a = 1, b = 5, c;
	c = a * b; // a*b is an rvalue
	(a * b) = c;*/

	/*
	std::vector<int> v;
	v.capacity();
	v.reserve(6);
	v.resize(6); // works in conjunction with reserve to grow the vector
	v.push_back(3); // finally implement the pushback function
	*/

	Vector v1(3);
	
	v1.Reserve(6);
	
	//Vector v1 = get_vector();

	return 0;
}
