#include <iostream>
#include <sstream>
#include <windows.h>
#include <string>

using namespace std;

class DateTime {

private:
    int second;
    unsigned short hour : 5;
    unsigned short day : 5;
    unsigned short month : 4;
    int year;

    bool IsVisokos(int year)//Проверка на високосный год
    {
        if (((year % 4 == 0) and (year % 100 != 0)) or (year % 400 == 0)) return true;
        else  return false;
    }

    int WhatDays(int month)//Функция вовращает кол-во дней в текущем месяце
    {
        if (month == 1 or month == 3 or month == 5 or month == 7 or month == 8 or month == 10 or month == 12) return 31;
        if (month == 4 or month == 6 or month == 9 or month == 11) return 30;
        if (month == 2 and IsVisokos(year) == true) return 29;
        if (month == 2 and IsVisokos(year) == false) return 28;

    }

    bool Validate(int second, int hour, int day, int month, int year)//Проверяет на корректность введенную дату
    {
        static int count = 0;
        count++;
        bool flag = false;
        if (year > 0)
        {
            if (month <= 12 and month > 0)
            {
                if (day <= WhatDays(month) and day > 0)
                {
                    if (hour >= 0 and hour < 24)
                    {
                        if (second >= 0 and second < 3600)
                        {
                            if (count > 1) {
                                cout << "Данные введены корректно" << endl;
                                return true;
                            }
                        }
                        else
                        {
                            cout << "Секунды введены не корректно" << endl;
                            return flag;
                        }
                    }
                    else
                    {
                        cout << "часы введены некорректно" << endl;
                        return flag;
                    }
                }
                else {
                    cout << "день введён не корректно" << endl;
                    return flag;
                }
            }
            else {
                cout << "месяц введён некорректно" << endl;
                return flag;
            }
        }
        else {
            cout << "год введён некорректно" << endl;
            return flag;
        }
    }

public:
    int checking_for_equality(const DateTime& other)//Сравнивает текущую и введенную даты
    {
        if (this->year > other.year) return 1;
        if (this->year < other.year) return -1;
        else
        {
            if (this->month > other.month) return 1;
            if (this->month < other.month) return -1;
            else
            {
                if (this->day > other.day) return 1;
                if (this->day < other.day) return -1;
                else
                {
                    if (this->hour > other.hour) return 1;
                    if (this->hour < other.hour) return -1;
                    else
                    {
                        if (this->second > other.second) return 1;
                        if (this->second < other.second) return -1;
                        else return 0;
                    }
                }
            }
        }
    }

    void AddMonth(int M = 1)//Изменяет текущую дату на M месяцев
    {
        if (M > 0)
        {
            while (M > 11)
            {
                this->AddYears();
                M -= 12;
            }

            if (month + M > 12)
            {
                this->AddYears();
                month = M - (12 - month);

            }

            else month += M;

            if (day > WhatDays(month)) day = WhatDays(month);
        }
        else
        {
            while (M < -11)
            {
                this->AddYears(-1);
                M += 12;
            }

            if (month + M <= 0)
            {
                this->AddYears(-1);
                month = 12 - abs(abs(M) - month);
            }

            else month += M;

            if (day > WhatDays(month)) day = WhatDays(month);
        }

    }

    void AddYears(int Y = 1)//Изменяет текущую дату на Y лет
    {
        year += Y;
        if (day > WhatDays(month)) day = WhatDays(month);
    }

    void AddDays(int N = 1)//Изменяет текущую дату на N дней
    {
        int new_day = day;
        if (N > 0)
        {
            if (day + N <= this->WhatDays(month))
            {
                day += N;
            }
            else
            {
                this->AddMonth();
                day = 1;
                if (month != 1) this->AddDays(N - (this->WhatDays(month - 1) - new_day) - 1);
                else this->AddDays(N - (31 - new_day) - 1);
            }
        }

        else
        {
            if (day + N > 0)
            {
                day += N;
            }
            else
            {
                this->AddMonth(-1);
                day = this->WhatDays(month);
                this->AddDays(N + new_day);
            }
        }
    }

    string DayofWeek()//Определяет день недели текущей даты
    {

        int newYear = year, newMonth;
        if (month == 1 or month == 2)
        {
            newYear = year - 1;
            newMonth = month + 10;
        }
        else newMonth = month - 2;
        int A = (day + ((31 * newMonth) / 12) + newYear + (newYear / 4) - (newYear / 100) + (newYear / 400)) % 7;

        string dayOfWeek;
        switch (A)
        {
        case 0:
            dayOfWeek = "Воскресенье";
            break;
        case 1:
            dayOfWeek = "Понедельник";
            break;
        case 2:
            dayOfWeek = "Вторник";
            break;
        case 3:
            dayOfWeek = "Среда";
            break;
        case 4:
            dayOfWeek = "Четверг";
            break;
        case 5:
            dayOfWeek = "Пятница";
            break;
        case 6:
            dayOfWeek = "Суббота";
            break;
        }
        return dayOfWeek;
    }

    string ToString()//Вывод текущей даты в строке
    {
        string str;
        stringstream ss;
        ss << "Дата:";
        if (day < 10)
            ss << "0" << day << ".";
        else ss << day << ".";
        if (month < 10)
            ss << "0" << month << "." << year << " ";
        else ss << month << "." << year << " ";

        int min = 0;
        int sec = second;
        if (sec < 60)
            ss << "Часы:" << hour << " " << "Минуты:" << min << " " << "Секунды:" << sec;
        else
        {
            while (sec > 60)
            {
                min++;
                sec -= 60;
            }
            ss << "Часы:" << hour << " " << "Минуты:" << min << " " << "Секунды:" << sec;
        }
        str = ss.str();
        return str;
    };


    DateTime()
    {
        second = 0;
        hour = 0;
        day = 1;
        month = 1;
        year = 2024;
    }

    DateTime(int second, int hour, int day, int month, int year)
    {
        cout << endl;
        if (this->Validate(second, hour, day, month, year)) {
            this->second = second;
            this->hour = hour;
            this->day = day;
            this->month = month;
            this->year = year;
        }
    }

    DateTime(int second, int hour, int day, string month, int year)
    {
        cout << endl;
        int nummonth = 0;
        if (month == "января" || month == "январь" || month == "Января" || month == "Январь") nummonth = 1;
        if (month == "февраля" || month == "февраль" || month == "Февраля" || month == "Февраль") nummonth = 2;
        if (month == "марта" || month == "март" || month == "Марта" || month == "Март") nummonth = 3;
        if (month == "апреля" || month == "апрель" || month == "Апреля" || month == "Апрель") nummonth = 4;
        if (month == "мая" || month == "май" || month == "Мая" || month == "Май") nummonth = 5;
        if (month == "июня" || month == "июнь" || month == "Июня" || month == "Июнь") nummonth = 6;
        if (month == "июля" || month == "июль" || month == "Июля" || month == "Июль") nummonth = 7;
        if (month == "августа" || month == "август" || month == "Августа" || month == "Август") nummonth = 8;
        if (month == "сентября" || month == "сентябрь" || month == "Сентября" || month == "Сентябрь") nummonth = 9;
        if (month == "октября" || month == "октябрь" || month == "Октября" || month == "Октябрь") nummonth = 10;
        if (month == "ноября" || month == "ноябрь" || month == "Ноября" || month == "Ноябрь") nummonth = 11;
        if (month == "декабря" || month == "декабрь" || month == "Декабря" || month == "Декабрь") nummonth = 12;

        if (this->Validate(second, hour, day, nummonth, year)) {
            this->second = second;
            this->hour = hour;
            this->day = day;
            this->month = nummonth;
            this->year = year;
        }

    }

};
DateTime get_Now()//Функция для сохранения нынешнего времени
{
    time_t now = time(0);
    struct tm Tstruct;
    localtime_s(&Tstruct, &now);
    DateTime date{ Tstruct.tm_sec + (Tstruct.tm_min * 60),Tstruct.tm_hour,Tstruct.tm_mday,Tstruct.tm_mon + 1,Tstruct.tm_year + 1900 };
    return date;
}

int main()
{
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");


    DateTime date;
    date = get_Now();

    bool flag_1 = true, flag_2 = true;
    int second, hour, day, year, min, Num;
    string month, str;
    stringstream ss;

    while (flag_1)
    {

        if (flag_2)
        {
            cout << "\n1-Проверка на равенство двух обьектов структуры\n";
            cout << "2-Добавить к дате N дней\n";
            cout << "3-Добавить к дате M месяцев\n";
            cout << "4-Добавить к дате Y лет\n";
            cout << "5-День недели текущей даты\n";
            cout << "6-Вывести текущую дату\n";
            cout << "7-Ввести свою дату\n";
            cout << "8-Вернуть текущую дату\n";
            cout << "9-Прекратить работу\n";
            cout << "10-Ввести дату через string\n";
            cout << "11-Проверка на равенство двух обьектов структуры через string\n";
            cout << "\nВыберете одну из операций:";

            cin >> Num;
        }

        switch (Num)
        {
        case 1:

            flag_2 = true;

            cout << "Введите секунды:";
            cin >> second;
            if (!cin.fail())
            {
                cout << "Введите минуты:";
                cin >> min;
            }
            if (!cin.fail())
            {
                cout << "Введите текущий час:";
                cin >> hour;
            }

            if (!cin.fail())
            {
                cout << "Введите день месяца:";
                cin >> day;
            }

            if (!cin.fail())
            {
                cout << "Введите месяц:";
                cin >> month;
            }

            if (!cin.fail())
            {
                cout << "Введите год:";
                cin >> year;
            }
            if (cin.fail())
            {
                cin.clear();
                cin.ignore((numeric_limits<streamsize>::max)(), '\n');
                cout << "Вы ввели не корректное число!" << endl << endl;
                flag_2 = false;
            }
            if (flag_2)
            {
                bool flag_3 = true;
                for (int i = 0; i < month.length(); i++)
                    if (!isdigit(month[i])) flag_3 = false;
                if (flag_3)
                {
                    DateTime date1{ second + min * 60,hour, day,stoi(month),year };
                    cout << date.checking_for_equality(date1);
                }
                else
                {
                    DateTime date1{ second + min * 60,hour, day,month,year };
                    cout << date.checking_for_equality(date1);
                }

            }
            break;
        case 2:
            int N;
            cout << "Введите кол-во дней:";
            cin >> N;
            while (cin.fail()) {
                cin.clear();
                cin.ignore((numeric_limits<streamsize>::max)(), '\n');
                cout << "Пожалуйста введите корректное число месяцев!\n";
                cin >> N;
            }
            date.AddDays(N);
            break;
        case 3:
            int M;
            cout << "Введите кол-во месяцев:";
            cin >> M;
            while (cin.fail())
            {
                cin.clear();
                cin.ignore((numeric_limits<streamsize>::max)(), '\n');
                cout << "Пожалуйста введите корректное число месяцев!\n";
                cin >> M;
            }
            date.AddMonth(M);
            break;
        case 4:
            cout << "Введите кол-во лет:";
            int Y;
            cin >> Y;
            while (cin.fail())
            {
                cin.clear();
                cin.ignore((numeric_limits<streamsize>::max)(), '\n');
                cout << "Пожалуйста введите корректное число лет!\n";
                cin >> Y;
            }
            date.AddYears(Y);
            break;
        case 5:
            cout << date.DayofWeek() << endl;
            break;
        case 6:
            cout << date.ToString() << endl;
            break;
        case 7:
            flag_2 = true;
            cout << "Введите секунды:";
            cin >> second;
            if (!cin.fail())
            {
                cout << "Введите минуты:";
                cin >> min;
            }

            if (!cin.fail())
            {
                cout << "Введите текущий час:";
                cin >> hour;
            }

            if (!cin.fail())
            {
                cout << "Введите день месяца:";
                cin >> day;
            }

            if (!cin.fail())
            {
                cout << "Введите месяц:";
                cin >> month;
            }

            if (!cin.fail())
            {
                cout << "Введите год:";
                cin >> year;
            }
            if (cin.fail())
            {
                cin.clear();
                cin.ignore((numeric_limits<streamsize>::max)(), '\n');
                cout << "Вы ввели не корректное число!" << endl << endl;
                flag_2 = false;
            }
            if (flag_2)
            {
                bool flag_3 = true;
                for (int i = 0; i < month.length(); i++)
                    if (!isdigit(month[i])) flag_3 = false;
                if (flag_3)
                {
                    DateTime date1{ second + min * 60,hour, day,stoi(month),year };
                    date = date1;
                }
                else
                {
                    DateTime date1{ second + min * 60,hour, day,month,year };
                    date = date1;
                }

            }
            break;
        case 8:
            date = get_Now();
            break;
        case 9:
            flag_1 = false;
            break;
        case 10:
        {
            cout << "Введите дату(секунды_минуты_часы_день_месяц_год)\n";
            for (int i = 0; i < 6; i++)
            {
                cin >> str;
                ss << str << " ";
            }
            ss >> second >> min >> hour >> day >> month >> year;
            bool flag_3 = true;
            for (int i = 0; i < month.length(); i++)
                if (!isdigit(month[i])) flag_3 = false;
            if (flag_3)
            {
                DateTime date1{ second + min * 60,hour, day,stoi(month),year };
                date = date1;
            }
            else
            {
                DateTime date1{ second + min * 60,hour, day,month,year };
                date = date1;
            }
            break;
        }
        case 11:
        {
            cout << "Введите дату(секунды_минуты_часы_день_месяц_год)\n";
            for (int i = 0; i < 6; i++)
            {
                cin >> str;
                ss << str << " ";
            }
            ss >> second >> min >> hour >> day >> month >> year;
            bool flag_3 = true;
            for (int i = 0; i < month.length(); i++)
                if (!isdigit(month[i])) flag_3 = false;
            if (flag_3)
            {
                DateTime date1{ second + min * 60,hour, day,stoi(month),year };
                cout << date.checking_for_equality(date1);
            }
            else
            {
                DateTime date1{ second + min * 60,hour, day,month,year };
                cout << date.checking_for_equality(date1);
            }
            break;
        }
        default:
            cout << endl << "Вы выбрали несуществующую операцию!" << endl;
        }
    }
}
