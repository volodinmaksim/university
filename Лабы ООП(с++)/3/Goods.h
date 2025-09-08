#pragma once
#include <ostream>
#include "Money.h"
using namespace std;


struct Date {
	int day;
	int month;
	int year;
	Date() : day(0), month(0), year(0) {}
	Date(int Day, int Month, int Year) : day(Day), month(Month), year(Year) {}
	int daysBetween(const Date& other) const
	{
		int days1 = year * 365 + month * 30 + day;
		int days2 = other.year * 365 + other.month * 30 + other.day;
		return abs(days1 - days2);
	}
};

class Goods 
{

	Money *price;
	string title;
	Date *dataOfRegister;
	int *quantity;
	int *numberOfDoc;


public:

	Goods();
	Goods(Money price, string title, Date dataOfRegister, int quantity, int numberOfDoc);
	Goods(const Goods& other);
	Goods& operator=(const Goods& other);
	~Goods();
	friend ostream& operator<<(ostream& out, const Goods& other);
	void changeThePrice(int rub, int cop);
	void changeTheQuantity(int a);
	double toCost();
	string toSString();

	void markDown(Date date);
};