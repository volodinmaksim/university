#include "Ellipse.h"

string Ellipse::toString(double x) const
{
	if (check(x))
	{
		if (x == (-1) * (*a) || x == *a)
			return  "x: " + to_string(x) + " y: " + to_string(valueY(x));
		else
			return  "x: " + to_string(x) + " y: +-" + to_string(valueY(abs(x)));
	}
	else
		return  "x: " + to_string(x) + " y - не существует";
}


bool Ellipse::check(double x) const
{
	if (x >= (-1) * (*a) && x <= *a)
		return true;
	else
		return false;
}


Ellipse::~Ellipse() 
{
}

double Ellipse::valueY(double x) const
{
	if (check(x))
	{
		double y = sqrt(*b * *b - (x * x * *b * *b / *a / *a));
		return y;
	}
}
