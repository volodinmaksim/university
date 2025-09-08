#include "dateOpen.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;


bool dateOpen::IsVisokos() const
{
    if (((year % 4 == 0) and (year % 100 != 0)) or (year % 400 == 0)) return true;
    else  return false;
}

int dateOpen::WhatDays(int month) const
{
    if (month == 1 or month == 3 or month == 5 or month == 7 or month == 8 or month == 10 or month == 12) return 31;
    else if (month == 4 or month == 6 or month == 9 or month == 11) return 30;
    else if (month == 2 and IsVisokos() == true) return 29;
    else if (month == 2 and IsVisokos() == false) return 28;
    else return 0;
}
bool dateOpen::check(int Year, int Month, int Day) const
{
    if (Year > 0 && Day <= WhatDays(Month) && Day >= 1 && Month <= 12 && Month >= 1)
        return true;
    else
        return false;
}
bool dateOpen::operator>(const dateOpen& other)
{
    if (this->year > other.year)
        return true;
    else if (this->year < other.year)
        return false;
    else
    {
        if (this->month > other.month)
            return true;
        else if (this->month < other.month)
            return false;
        else
        {
            if (this->day > other.day)
                return true;
            else if (this->day < other.day)
                return false;
            else
                return false;
        }
    }
}
bool dateOpen::operator<(const dateOpen& other)
{
    if (this->year < other.year)
        return true;
    else if (this->year > other.year)
        return false;
    else
    {
        if (this->month < other.month)
            return true;
        else if (this->month > other.month)
            return false;
        else
        {
            if (this->day < other.day)
                return true;
            else if (this->day > other.day)
                return false;
            else
                return false;
        }
    }
}
bool dateOpen::operator==(const dateOpen& other)
{
    if (this->year == other.year and this->month == other.month and this->day == other.day)
        return true;
    else
        return false;
}
bool dateOpen::operator!=(const dateOpen& other)
{
    if (this->year != other.year and this->month != other.month and this->day != other.day)
        return true;
    else
        return false;
}
void dateOpen::setDay(int day)
{
    this->day = day;
}
void dateOpen::setMonth(int month)
{
    this->month = month;
}
void dateOpen::setYear(int year)
{
    this->year = year;
}
dateOpen::dateOpen()
{
    day = 1;
    month = 1;
    year = 2024;
}

dateOpen::dateOpen(int Day, int Month, int Year, bool& flag)
{
    if (check(Year, Month, Day))
    {
        day = Day;
        month = Month;
        year = Year;
    }
    else
        flag = false;
}