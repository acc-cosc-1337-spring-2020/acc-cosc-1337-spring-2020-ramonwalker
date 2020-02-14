#include<iostream>

using std::cout;

int main() 
{
	int num = 5;
	cout << "Value of num is: " << num << " Address is " << &num;

	int &num_ref = num; // num moves to the address of num for the reference parameter
	num_ref = 10; // changes to 10
	cout << "Value of num is: " << num << " Address is " << &num;

	return 0;
}