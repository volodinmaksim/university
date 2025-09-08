#pragma once
#include "Pair.h"

class Complex : private Pair
{
public:
	Complex(int a = 0, int b = 0) : Pair(a, b) {};
	Complex(const Complex& other);
	//Complex& operator=(const Complex& other);

	friend ostream& operator<<(ostream& out, const Complex& other);
	friend istream& operator>>(istream& in, const Complex& other);
	
	Complex* operator+(const Complex& other) const;
	Complex operator*(const Complex& other) const;
	Complex* operator-(const Complex& other) const;
};