#ifndef MY_VECTOR_H
#define MY_VECTOR_H
#include<cstddef>
#include<stddef.h>

class Vector
{
public:
	Vector(size_t sz);
	Vector(const Vector& v);//copy constructor - Rule of 3
	Vector & operator = (const Vector & v); // created a copy assigment - Rule of 3
	size_t Size()const { return size; }
	int& operator[](int i) { return nums[i]; }
	int& operator[](int i)const { return nums[i]; }
private:
	size_t size;
	int* nums;
};

#endif // !1
	