//Write include statement
#include "rectangle.h"
#include<iostream>

/*
Write the class function code for the Rectangle class with one constructor that accepts two int parameters (width, height),
has one public function area that returns the area of the rectangle, and one private function calculate_area
that calculates area of the rectangle.  The class has 3 int private variables area, width, and height.
*/


void Rect::calculate_area()
{
	a = w * h;
}

std::ostream & operator<<(std::ostream & out, const Rect & a)
{
	out << "The area is: " << a.a << "\n";

	return out;
}