#include<iostream>

using std::cout;

int main() 
{
	int* ptr_num = new int(5); // declare and acquire new memory(heap)

	cout << "Address of ptr_num: " << &ptr_num << "\n"; // displays address where ptr_num is stored
	cout << "Address ptr_num point to: " << ptr_num << "\n"; // address where 5 is stored
	cout << "Value of ptr_num point to: " << *ptr_num << "\n""\n";

	delete ptr_num;  // delete memory
	ptr_num = nullptr; // clean up after ourselves 

	return 0;
}
