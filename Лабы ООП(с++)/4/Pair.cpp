#include "Pair.h"

Pair::Pair(int a, int b)
{
	this->a = new int(a);
	this->b = new int(b);
}

Pair::~Pair()
{
	delete a;
	a = nullptr;
	delete a;
	a = nullptr;
}

Pair::Pair(const Pair& other)
{
	this->a = new int(*other.a);
	this->b = new int(*other.b);
}

Pair& Pair::operator=(const Pair& other)
{
	if (&other != this)
	{
		*this->a = *other.a;
		*this->b = *other.b;
	}
	return *this;
}

bool Pair::operator==(Pair& other)
{
	return *other.a == *this->a && *other.b == *this->b;
}

bool Pair::operator!=(Pair& other)
{
	return !operator==(other);
}

Pair* Pair::operator+(const Pair& other) const
{
	Pair* temp = new Pair(*this->a + *other.a, *this->b + *other.b);
	return temp;
}

Pair* Pair::operator-(const Pair& other) const
{
	Pair* temp = new Pair(*this->a - *other.a, *this->b - *other.b);
	return temp;
}

ostream& operator<<(ostream& out, const Pair& other)
{
	out << "(" << *other.a << ", " << *other.b << ")";
	return out;
}

istream& operator>>(istream& in, const Pair& other)
{
	in >> *other.a >> *other.b;
	return in;
}
