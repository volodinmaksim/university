#include "Function.h"

Function::Function(double a, double b)
{
	this->a = new double(a);
	this->b = new double(b);
}

Function::Function(const Function& obj)
{
	this->a = new double(*obj.a);
	this->b = new double(*obj.b);
}

Function& Function::operator=(const Function& other)
{
	if (this != &other)
	{
		*this->a = *other.a;
		*this->b = *other.b;
	}
	return *this;
}

Function::~Function()
{
	delete a;
	a = nullptr;
	delete b;
	b = nullptr;
}


