#include "Money.h"
using namespace std;

int Money::toCop() const
{
	int all_cop = *cop + *rub * 100;
	return all_cop;
}

Money::Money()
{
	rub = new int(0);
	cop = new int(0);
}

Money::Money(int _rub, int _cop)
{
	rub = new int(_rub);
	cop = new int(_cop);
}

Money::Money(int all_cop)
{
	rub = new int(all_cop / 100);
	cop = new int(all_cop % 100);
}

Money::Money(const Money& oth)
{
	rub = new int(*oth.rub);
	cop = new int(*oth.cop);
}

void Money::setRub(int _rub)
{
	*rub = _rub;
}

void Money::setCop(int _cop)
{
	*cop = _cop;
}

int* Money::getRub()
{
	return rub;
}

int* Money::getCop()
{
	return cop;
}



Money Money::operator+(const Money& obj)
{
	return Money(this->toCop() + obj.toCop());
}

Money Money::operator-(const Money& obj)
{
	return Money(this->toCop() - obj.toCop());
}

bool Money::operator<(const Money& obj)
{
	if (toCop() < obj.toCop()) return true;
	return false;
}

bool Money::operator>(const Money& obj)
{
	if (toCop() > obj.toCop()) return true;
	return false;
}

bool Money::operator==(const Money& obj)
{
	if (toCop() == obj.toCop()) return true;
	return false;
}

bool Money::operator!=(const Money& obj)
{
	return !(*this == obj);
}

bool Money::operator<=(const Money& obj)
{
	return !(*this > obj);
}

bool Money::operator>=(const Money& obj)
{
	return !(*this < obj);
}

Money& Money::operator=(const Money& obj)
{
	*rub = *obj.rub;
	*cop = *obj.cop;
	return *this;
}

ostream& operator<<(ostream& out, const Money& obj)
{
	out  << *obj.rub << " руб." << *obj.cop << " коп.";
	return out;
}

istream& operator>>(istream& in, const Money& obj)
{
	in >> *obj.rub >> *obj.cop;
	return in;
}
