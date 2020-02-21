#include "dna.h"
#include<iostream>

using namespace std;

/*
Write code for function get_gc_content that accepts
a const reference string parameter and returns a double.
Calculate GC content:
Iterate string count Gs and Cs, divide count by string length.
Return quotient.
*/
double get_gc_content(const string& dna)
{
	int i = 0, count = 0;
	for (i = 0; i < dna.size(); i++) {
		if (dna[i] == 'G' || dna[i] == 'C') {
			count++;
		}
	}
	return ((double)count) / dna.size();
}

/*
Write code for function get_reverse_string that
accepts a string parameter and returns a string reversed.
*/
string get_reverse_string(string dna)
{
	string rev = "";

	for (int i = dna.length()-1; i >= 0; i--)
	{
		rev += dna[i];
	}
	return rev;
}

/*
Write prototype for function get_dna_complement that
accepts a string dna and returns a string.
Calculate dna complement:
a. call function get_reverse_string(dna), save results to a local string variable
b. iterate local string variable and
    replace A with T, T with A, C with G and G with C
c. return string
*/
string get_dna_complement(string dna)
{
	string result = get_reverse_string(dna);
	string complement = "";

	for (int i = 0; i < result.length(); i++)
	{
		if (result[i] == 'A')
		{
			complement += 'T';
		}
		else if (result[i] == 'T')
		{
			complement += 'A';
		}
		else if (result[i] == 'G')
		{
			complement += 'C';
		}
		else if (result[i] == 'C')
		{
			complement += 'G';
		}
	}
		return complement;
}