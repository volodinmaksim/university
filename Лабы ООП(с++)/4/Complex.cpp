#include "Complex.h"

Complex::Complex(const Complex& other)
{
	this->a = new int(*other.a);
	this->b = new int(*other.b);
}


Complex* Complex::operator+(const Complex& other) const
{
	Pair* temp = Pair::operator+(other);
	Complex* res = static_cast<Complex*>(temp); 
	return res;
}

Complex Complex::operator*(const Complex& other) const
{
	return Complex(*this->a * *other.a - *this->b * *other.b, *this->a * *other.b + *this->b * *other.a);
}

Complex* Complex::operator-(const Complex& other) const
{
	Pair* temp = Pair::operator-(other);
	Complex* res = static_cast<Complex*>(temp); 
	return res;
}

ostream& operator<<(ostream& out, const Complex& other)
{
	if (*other.b < 0)
		out << *other.a << " - " << abs(*other.b) << "i";
	else if (*other.b > 0)
		out << *other.a << " + " << abs(*other.b) << "i";
	else
		out << *other.a;
	return out;
}

istream& operator>>(istream& in, const Complex& other)
{
	in >> *other.a >> *other.b;
	return in;
}
