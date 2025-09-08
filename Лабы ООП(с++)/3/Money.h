#pragma once
#include <iostream>
using namespace std;

class Money {
	int* rub;
	int* cop;

	int toCop() const;
public:
	Money();
	Money(int _rub, int _cop);
	Money(int all_rub);
	Money(const Money& oth);
	~Money() { delete rub; delete cop; }

	void setRub(int _rub);
	void setCop(int _cop);
	int* getRub();
	int* getCop();

	Money operator+(const Money &obj);
	Money operator-(const Money& obj);
	bool operator<(const Money& obj);
	bool operator>(const Money& obj);
	bool operator==(const Money& obj);
	bool operator!=(const Money& obj);
	bool operator<=(const Money& obj);
	bool operator>=(const Money& obj);
	Money& operator=(const Money& obj);
	friend ostream& operator<<(ostream& out, const Money& obj);
	friend istream& operator>>(istream& in, const Money& obj);
};
