#include "Angle.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(0, "");
	Angle first, second, result;
	cout << "������� ������ ������: ";
	cin >> first;
	cout << "\n";
	cout << "������� ������ ������: ";
	cin >> second;
	cout << "\n";

	/*if (first > second)
		cout << "true" << endl;
	else
		cout << "false" << endl;*/


	cout <<
		"1. ��������� �� ������� ������" << "\n" <<
		"2. �������" << "\n" <<
		"3. ��������" << "\n" <<
		"4. ������� �������� �������" << "\n" <<
		"5. ������� �������� �������" << "\n" <<
		"0. ��������� ������" << "\n" << endl;
	int x;
	do
	{
		cout << "�������� ��������" << endl;
		cin >> x;
		switch (x)
		{
		case 1:
		{
			result = first - second;
			cout << result << endl;
			break;
		}
		case 2:
		{
			result = first + second;
			cout << result << endl;
			break;
		}
		case 3:
		{
			if (first == second)
				cout << "(1) == (2)" << endl;

			else if (first > second)
				cout << "(1) > (2)" << endl;

			else if (first < second)
				cout << "(1) < (2)" << endl;
			break;
		}
		case 4:
		{
			cout << first << endl;
			break;
		}
		case 5:
		{
			cout << second << endl;
			break;
		}
		case 0:
			break;
		default:
		{
			cout << "������� �������� �����, ������� �����)" << endl;
			cin >> x;
			break;
		}
		}
	} while (x != 0);
}