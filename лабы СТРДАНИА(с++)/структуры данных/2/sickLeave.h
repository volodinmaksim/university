#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "dateOpen.h"
using namespace std;

struct sickLeave
{
	string fio;
	string place_of_work;
	string diagnosis;
	dateOpen date_open;
	int day_of_ail;

	sickLeave();
	sickLeave(string fio, string placeOfWork, string diagnosis, dateOpen, int dayOfAil);
	sickLeave(const sickLeave& other);
	void printStruct();
	bool operator==(const sickLeave& other);
	bool operator!=(const sickLeave& other);
};