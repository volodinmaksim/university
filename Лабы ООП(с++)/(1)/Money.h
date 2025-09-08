#pragma once
#include <iostream>
#include <string>
using namespace std;

class Money
{
	int bill100;
	int bill500;
	int bill2000;
	int bill5000;

	bool check(Money other) const;
public:

	Money();
	Money(int, int, int, int);
	Money sum(Money other) const;
	Money subtraction(Money other, void (*ptrError)(bool)) const;
	string toString() const;
	void check_unsigned(bool &flag) const;


	void set_bill_100(int value)
	{
		bill100 = value;
	}
	void set_bill_500(int value)
	{
		bill500 = value;
	}
	void set_bill_2000(int value)
	{
		bill2000 = value;
	}
	void set_bill_5000(int value)
	{
		bill5000 = value;
	}
	int get_bill_100() const
	{
		return bill100;
	}
	int get_bill_500() const
	{
		return bill500;
	}
	int get_bill_2000() const
	{
		return bill2000;
	}
	int get_bill_5000() const
	{
		return bill5000;
	}

};