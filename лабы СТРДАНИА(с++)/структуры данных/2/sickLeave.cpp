#include "sickLeave.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;


sickLeave::sickLeave(const sickLeave& other) : fio(other.fio), place_of_work(other.place_of_work),
diagnosis(other.diagnosis), date_open(other.date_open),
day_of_ail(other.day_of_ail)
{   }

void sickLeave::printStruct()
{
    cout << "ФИО: " << fio << endl;
    cout << "Место работы: " << place_of_work << endl;
    cout << "Диагноз: " << diagnosis << endl;
    cout << "Дата открытия: " << date_open.day << "/" << date_open.month << "/" << date_open.year << endl;
    cout << "Дней болезни: " << day_of_ail << endl;
    cout << endl;
}


bool sickLeave::operator==(const sickLeave& other)
{
    if (this->date_open == other.date_open && this->day_of_ail == other.day_of_ail &&
        this->diagnosis == other.diagnosis && this->fio == other.fio && this->place_of_work == other.place_of_work)
        return true;
    else
        return false;
}

bool sickLeave::operator!=(const sickLeave& other)
{
    if (this->date_open != other.date_open && this->day_of_ail != other.day_of_ail &&
        this->diagnosis != other.diagnosis && this->fio != other.fio && this->place_of_work != other.place_of_work)
        return true;
    else
        return false;
}

sickLeave::sickLeave() : day_of_ail(0)
{
    fio = " ";
    place_of_work = " ";
    diagnosis = " ";
    date_open;
}

sickLeave::sickLeave(string Fio, string PlaceOfWork, string Diagnosis, dateOpen Date_open, int dayOfAil) : day_of_ail(dayOfAil)
{
    fio = Fio;
    place_of_work = PlaceOfWork;
    diagnosis = Diagnosis;
    date_open.day = Date_open.day;
    date_open.month = Date_open.month;
    date_open.year = Date_open.year;
}