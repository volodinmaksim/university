#pragma once
#include <iostream>
#include <ostream>
#include <string>
using namespace std;

class Function
{
protected:

	double* a, *b;
	
public:

	Function(double a, double b);
	Function(const Function& obj);
	Function& operator= (const Function& other);
	virtual ~Function();

	virtual double valueY(double x) const = 0;
	
	virtual string toString(double x) const = 0;

	void setA(double a) { *this->a = a; }
	void setB(double b) { *this->b = b; }
	double* getA() { return a; }
	double* getB() { return b; }

};

