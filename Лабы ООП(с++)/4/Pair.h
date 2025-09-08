#pragma once
#include <fstream>
#include <iostream>
using namespace std;

class Pair 
{
protected:
	int* a, * b;
public:

	Pair(int a = 0, int b = 0);
	~Pair();
	Pair(const Pair& other);
	Pair& operator=(const Pair& other);

	friend ostream& operator<<(ostream& out, const Pair& other);
	friend istream& operator>>(istream& in, const Pair& other);

	
	bool operator==(Pair& other);
	bool operator!=(Pair& other);
	
	
	Pair* operator+(const Pair& other) const;
	Pair* operator-(const Pair& other) const;


	int* getA() const
	{
		return a;
	}
	int* getB() const
	{
		return b;
	}
	void setA(int* a)
	{
		this->a = a;
	}
	void setB(int* b)
	{
		this->b = b;
	}
};
