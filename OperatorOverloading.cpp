#include <iostream>

class Complex
{

	// Mark the variables as private following the encapsulation
private:
	int real;
	int img;

public:
	// Default constructor to help in creating object without the variables
	Complex() : real(0), img(0) {}

	// Use inline assignment following morder practice
	Complex(int x, int y) : real{x}, img{y} {}

	// Create a different object not modifying the existing object keeping the existing object intact
	// Use the const keyword for the obj argument to ensure its not modified
	// const for parameter ensure that the passed object is not changed
	// const after the function ensures that it do not modify the current object values
	Complex operator+(const Complex &obj) const
	{
		return Complex(real + obj.real, img + obj.img);
	}

	/*
	No this Pointer in Friend Functions:

    The const qualifier in member functions applies to the implicit this pointer.
    Friend functions are not part of the class, so they don’t have a this pointer to which the const qualifier could be applied.
	*/

	friend void operator<<(std::ostream &os, const Complex &obj)
	{
		os << obj.real << " +  " << obj.img;
	}

	// Create getters to access the private variables
	int getReal()
	{
		return real;
	}

	int getImg()
	{
		return img;
	}
};

int main()
{

	Complex obj1(2, 4);
	Complex obj2(5, 6);

	Complex obj3 = obj1 + obj2;

	std::cout << obj3;

	return 0;
}