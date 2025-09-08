#pragma once
#include <iostream>
using namespace std;


class Angle
{
	int* degrees;
	int* minute;


	int InMinets();
	int InAngles();
public:
	Angle();
	Angle(int);
	Angle(int, int);
	Angle(const Angle& other);
	

	~Angle();
	

	Angle operator+(Angle& other);
	Angle operator-(Angle& other);
	
	bool operator==(Angle& other);
	bool operator>(Angle& other);
	bool operator<(Angle& other);
	bool operator>=(Angle& other);
	bool operator<=(Angle& other);

	Angle& operator=(const Angle& other);
	
	friend ostream& operator<< (ostream& out, const Angle& other);
	friend istream& operator>> (istream& out, const Angle& other);


	int* getDegrees();
	int* getMinute();
	void setDegrees(int *degrees);
	void setMinute(int *minute);

};

