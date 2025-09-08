#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Pair 
{
	int indexOpen, indexClosed;

public:

	Pair(int indexOpen = -1, int indexClosed = -1) : indexOpen(indexOpen), indexClosed(indexClosed) {};

	Pair& operator= (const Pair& obj)
	{
		this->indexOpen = obj.indexOpen;
		this->indexClosed = obj.indexClosed;
		return *this;
	}

	friend ostream& operator<< (ostream& out, const Pair& obj)
	{
		out << obj.indexOpen << ", " << obj.indexClosed;
		return out;
	}

	bool operator> (const Pair& obj)
	{
		if (this->indexOpen > obj.indexOpen)
			return true;
		return false;
	}

	bool operator< (const Pair& obj)
	{
		return !this->operator>(obj);
	}
};