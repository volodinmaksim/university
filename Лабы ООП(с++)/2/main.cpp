#include "Angle.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(0, "");
	Angle first, second, result;
	cout << "Введите первый объект: ";
	cin >> first;
	cout << "\n";
	cout << "Введите второй объект: ";
	cin >> second;
	cout << "\n";

	/*if (first > second)
		cout << "true" << endl;
	else
		cout << "false" << endl;*/


	cout <<
		"1. вычестмть из первого второй" << "\n" <<
		"2. сложить" << "\n" <<
		"3. сравнить" << "\n" <<
		"4. Вывести средства первого" << "\n" <<
		"5. Вывести средства второго" << "\n" <<
		"0. Завершить работу" << "\n" << endl;
	int x;
	do
	{
		cout << "Выберите операцию" << endl;
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
			cout << "Введена неверная цифра, введите новую)" << endl;
			cin >> x;
			break;
		}
		}
	} while (x != 0);
}