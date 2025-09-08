#include "Angle.h"

int Angle::InMinets()
{
	return *this->degrees * 60 + *this->minute;
}

int Angle::InAngles()
{
	return InMinets() / 60;
}

Angle::Angle()
{
	degrees = new int(0);
	minute = new int(0);
}

Angle::Angle(int minutes)
{
	degrees = new int(minutes / 60);
	minute = new int(minutes % 60);
}

Angle::Angle(int degrees, int minute)
{
	this->degrees = new int(degrees);
	this->minute = new int(minute);
}

Angle::Angle(const Angle& other)
{
	degrees = new int(*other.degrees);
	minute = new int(*other.minute);
}
Angle::~Angle()
{
	delete degrees;
	degrees = nullptr;
	delete minute;
	minute = nullptr;
}

Angle Angle::operator+(Angle &other) 
{
	int summ = InMinets() + other.InMinets();
	return Angle(summ);
}

Angle Angle::operator-(Angle &other) 
{
	int ded = InMinets() - other.InMinets();
	return Angle(ded);
}

bool Angle::operator==(Angle& other)
{
	return InMinets() == other.InMinets();
}

bool Angle::operator>(Angle& other)
{
	return InMinets() > other.InMinets();
}

bool Angle::operator<(Angle& other)
{
	return InMinets() < other.InMinets();
}

bool Angle::operator>=(Angle& other)
{
	return !operator<(other);
}

bool Angle::operator<=(Angle& other)
{
	return !operator>(other);
}

Angle& Angle::operator=(const Angle& other)
{
	*this->degrees = *other.degrees;
	*this->minute = *other.minute;
	return *this;
}

ostream& operator<<(ostream& out, const Angle& other) 
{
	out << "degrees: " << *other.degrees << " minutes :" << *other.minute;
	return out;
}

istream& operator>>(istream& in, const Angle& other)
{	
	in >> *other.degrees >> *other.minute;
	return in;
}


int* Angle::getDegrees()
{
	return degrees;
}

int* Angle::getMinute()
{
	return minute;
}

void Angle::setDegrees(int* degrees)
{
	this->degrees = degrees;
}

void Angle::setMinute(int* minute)
{
	this->minute = minute;
}
