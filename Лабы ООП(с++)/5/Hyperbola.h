#pragma once
#include "Function.h"


class Hyperbola : public Function
{
	bool check(double x) const;
public:

	Hyperbola(double _a = 1, double _b = 1) : Function(_a, _b) {};
	Hyperbola(const Hyperbola& other) : Function(other) {};
	~Hyperbola();
	double valueY(double x) const;
	string toString(double x) const;
};


