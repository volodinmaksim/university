#include <iostream>
#include "Node.h"
#include "dateOpen.h"
#include "sickLeave.h"
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

void ERROR(bool flag)
{
	if (!flag)
		cerr << "Ошибка!!!" << endl;
}


int main()
{
	setlocale(0, "");
	bool flag(true);
	ifstream filein("Больничный лист.txt");
	if (!filein.is_open())
	{
		cerr << "Ошибка открытия файла Больничный лист.txt" << endl;
		return 1;
	}
	dateOpen per;
	int day, month, year;
	Node* head = new Node;
	ERROR(flag);
	removeList(head);
	int x;
	cout << "Выберите операцию:" << "\n" <<
		"1. Добавить элемент из файла в начало" << "\n" <<
		"2. Добавить элемент из файла в конец" << "\n" <<
		"3. Удалить первый элемент" << "\n" <<
		"4. Удалить последний элемент" << "\n" <<
		"5. Напечатать диагноз, который чаще всего встречается в больничных листах" << "\n" <<
		"6. Удалить информацию о больничных листах, открытых позднее указанной даты" << "\n" <<
		"7. Определить предприятия, сотрудники которых болели дольше всего" << "\n" <<
		"8. Найти день, в который было открыто наибольшее количество больничных листов" << "\n" <<
		"0. Завершить программу" << "\n";

	do
	{
		cout << "Выберите операцию" << endl;
		cin >> x;
		switch (x)
		{
		case 1:
		{
			if (!filein.eof())
			{
				addElemFromHead(head, readtxt(filein));
				printList(head);
			}
			else
				cout << "Файл кончился" << endl;
			break;
		}
		case 2:
		{
			if (!filein.eof())
			{
				addElemFromEnd(head, readtxt(filein));
				printList(head);
			}
			else
				cout << "Файл кончился" << endl;
			break;
		}
		case 3:
		{
			deleteElemFromHead(head);
			printList(head);
			break;
		}
		case 4:
		{
			deleteElemFromEnd(head);
			printList(head);
			break;
		}
		case 5:
		{
			frequentDiagnosis(head);
			break;
		}
		case 6:
		{
			cout << "Введите дату после которой надо удалить записи(день, месяц, год через пробел (22 12 2024))" << endl;
			cin >> day >> month >> year;
			per.setDay(day);
			per.setMonth(month);
			per.setYear(year);
			deleteByDate(head, per);
			printList(head);
			break;
		}
		case 7:
		{
			companyBigDiseases(head);
			break;
		}
		case 8:
		{
			DayBigDesease(head);
			break;
		}
		case 0:
			break;
		default:
		{
			cout << "Введена неверная цифра, введите новую" << endl;
			break;
		}
		}
	} while (x != 0);

}