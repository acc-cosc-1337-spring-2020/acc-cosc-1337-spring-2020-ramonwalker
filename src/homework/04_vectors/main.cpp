#include<iostream>
#include<vector>
#include "vectors.h"

/*
use a vector of int with values 8, 4, 20, 88, 66, 99

Prompt user for 1 for Get Max from vector and 2 for Get primes.
Prompt user for a number and return max value or list of primes
and display them to screen.
Program continues until user decides to exit.

*/
int main() 
{
	vector<int> numbers = { 8, 4, 20, 88, 66, 99 };
	vector<int> result;

	int ch = 0, num, i;

	while (ch!= -1)
	{
		cout << "Enter 1 to execute Get Max from vector and 2 for Get primes\n";
		cout << "Enter -1 to exit\n";
		cout << "Enter your choice:";
		cin >> ch;

		switch (ch)
		{
		case 1:

			cout << "Maximum value in the vector is " << get_max_from_vector(numbers) << endl << endl;

			break;
		case 2:

			cout << "Enter number to get primes up to that number: ";
			cin >> num;

			result = vector_of_primes(num);

			cout << " \nThe vector with values are ";

			for (i = 0; i < result.size(); i++)
			{ 
					if (i == result.size() - 1)

						cout << result[i];
					else

						cout << result[i] << ",";
			}

			cout << "\n\n";

			break;
		case -1: exit(0);

		default:cout << "Invalid choice";
	
		}
	}

	return 0;
}