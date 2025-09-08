#include <iostream>
#include <string>
#include "Money.h"
using namespace std;

Money::Money()
{
	bill100 = 0;
	bill500 = 0;
	bill2000 = 0;
	bill5000 = 0;
}

Money::Money(int Bill100, int Bill500, int Bill2000, int Bill5000)
{
	bill100 = Bill100;
	bill500 = Bill500;
	bill2000 = Bill2000;
	bill5000 = Bill5000;
}

string Money::toString() const
{

	string str = "Число купюр с номиналом 100: " + to_string(bill100) + "\n" +
		"Число купюр с номиналом 500: " + to_string(bill500) + "\n" + 
		"Число купюр с номиналом 2000: " + to_string(bill2000) + "\n" + 
		"Число купюр с номиналом 5000: " + to_string(bill5000);
	return str;
}

Money Money::sum(Money other) const
{
	Money temp;
	temp.bill100 = this->bill100 + other.bill100;
	temp.bill500 = this->bill500 + other.bill500;
	temp.bill2000 = this->bill2000 + other.bill2000;
	temp.bill5000 = this->bill5000 + other.bill5000;
	return temp;
}
Money Money::subtraction(Money other, void (*ptrError)(bool)) const
{
	if (Money::check(other))
	{
		Money temp;
		temp.bill100 = this->bill100 - other.bill100;
		temp.bill500 = this->bill500 - other.bill500;
		temp.bill2000 = this->bill2000 - other.bill2000;
		temp.bill5000 = this->bill5000 - other.bill5000;
		return temp;
	}
	else
	{
		Money temp;
		ptrError(false);
		return temp;
	}
}

bool Money::check(Money other) const
{
	if (this->bill100 >= other.bill100 &&
		this->bill500 >= other.bill500 &&
		this->bill2000 >= other.bill2000 &&
		this->bill5000 >= other.bill5000)
		return true;
	else
		return false;
}

void Money::check_unsigned(bool &flag) const
{
	if ( bill100 < 0 ||
		 bill500 < 0 ||
		 bill2000 < 0 ||
		 bill5000 < 0 )
	{
		flag = false;
	}
}
