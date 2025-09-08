#include "Hyperbola.h"

string Hyperbola::toString(double x) const
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

bool Hyperbola::check(double x) const
{
	if (x <= (-1) * (*a) || x >= *a)
		return true;
	else
		return false;
}

Hyperbola::~Hyperbola()
{
}

double Hyperbola::valueY(double x) const
{
	if (check(x))
	{
		double y = sqrt((x * x * *b * *b / *a / *a) - *b * *b);
		return y;
	}
}
