#include "atm.h"

//atm.cpp

std::ostream & operator<<(std::ostream & out, const ATM & a)
{
	out << a.customer << "\n";

	return out;
}
