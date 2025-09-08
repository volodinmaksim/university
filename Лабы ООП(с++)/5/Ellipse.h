#pragma once
#include "Function.h"


class Ellipse : public Function
{
	bool check(double x) const;
public:

	Ellipse(double a = 1, double b = 1) : Function(a, b) {};
	Ellipse(const Ellipse& other) : Function(other) {};
	~Ellipse();
	string toString(double x) const;
	double valueY(double x) const;
};