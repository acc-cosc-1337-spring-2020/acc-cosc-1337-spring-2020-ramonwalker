//write include statements
#include<string>
#include<iostream>
#include "dna.h"

//write using statements
using namespace std;


/*
Write code that prompts user to enter 1 for Get GC Content, 
or 2 for Get DNA Complement.  The program will prompt user for a 
DNA string and call either get gc content or get dna complement
function and display the result. Program runs as long as 
user enters a y or Y.
*/
int main()
{
	char option;
	string dna;
	do {
		cout << "Please enter 1 for Get GC Content,\nor 2 for Get DNA Complement:\n";
		//cout << ";
		cout << "\nEnter option: ";
		cin >> option;

		if (option != 'n' && option != 'N')
		{
			cout << "\nEnter DNA string: ";
			cin >> dna;
		}
		switch (option)
		{
		case '1':
			cout << "GC content result is: " << get_gc_content(dna) << "\n" << "and the GC content reversed is: "
			<< get_reverse_string(dna) << endl << "\n";
			break;
		case '2':
			cout << "DNA Complement result is: " << get_dna_complement(dna) << endl << "\n";
			break;
		case 'n':
			break;
		default:
			cout << "Please enter valid option" << endl;
			break;
		}

	} while (option != 'n' && option != 'N');

	return 0;
}