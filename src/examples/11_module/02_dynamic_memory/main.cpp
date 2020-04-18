#include<iostream>

using std::cout;

int main() 
{
	int* ptr_num = new int(5);

	cout << "Address of ptr_num: " << &ptr_num << "\n";
	cout << "Address ptr_num point to: " << ptr_num << "\n";
	cout << "Value of ptr_num point to: " << *ptr_num << "\n""\n";

	delete ptr_num;  // delete memory
	ptr_num = nullptr; // cleam up after ourselves 

	return 0;
}