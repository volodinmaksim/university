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
		cerr << "������!!!" << endl;
}


int main()
{
	setlocale(0, "");
	bool flag(true);
	ifstream filein("���������� ����.txt");
	if (!filein.is_open())
	{
		cerr << "������ �������� ����� ���������� ����.txt" << endl;
		return 1;
	}
	dateOpen per;
	int day, month, year;
	Node* head = new Node;
	ERROR(flag);
	removeList(head);
	int x;
	cout << "�������� ��������:" << "\n" <<
		"1. �������� ������� �� ����� � ������" << "\n" <<
		"2. �������� ������� �� ����� � �����" << "\n" <<
		"3. ������� ������ �������" << "\n" <<
		"4. ������� ��������� �������" << "\n" <<
		"5. ���������� �������, ������� ���� ����� ����������� � ���������� ������" << "\n" <<
		"6. ������� ���������� � ���������� ������, �������� ������� ��������� ����" << "\n" <<
		"7. ���������� �����������, ���������� ������� ������ ������ �����" << "\n" <<
		"8. ����� ����, � ������� ���� ������� ���������� ���������� ���������� ������" << "\n" <<
		"0. ��������� ���������" << "\n";

	do
	{
		cout << "�������� ��������" << endl;
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
				cout << "���� ��������" << endl;
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
				cout << "���� ��������" << endl;
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
			cout << "������� ���� ����� ������� ���� ������� ������(����, �����, ��� ����� ������ (22 12 2024))" << endl;
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
			cout << "������� �������� �����, ������� �����" << endl;
			break;
		}
		}
	} while (x != 0);

}