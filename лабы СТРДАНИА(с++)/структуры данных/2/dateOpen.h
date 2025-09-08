#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct dateOpen
{
	int day;
	int month;
	int year;

	dateOpen();
	dateOpen(int Day, int Month, int Year, bool& flag);
	int WhatDays(int) const;
	bool IsVisokos() const;
	bool check(int, int, int) const;
	bool operator>(const dateOpen& other);
	bool operator<(const dateOpen& other);
	bool operator==(const dateOpen& other);
	bool operator!=(const dateOpen& other);
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
};