#include <iostream>
#include "Money.h"
#include <cstdlib>
using namespace std;

void error(bool flag)
{
	if (!flag)
	{
		cerr << "Введено недопустимое значение" << endl;
		exit(0);
	}
}

void subtractionError(bool flag)
{
	if (!flag)
	{
		cerr << "НЕВОЗМОЖНАЯ ОПЕРАЦИЯ!!!" << endl << endl;
	}
}

int main()
{
	void (*ptrError)(bool) = error;
	setlocale(0, "");
	int bill100, bill500, bill2000, bill5000;
	bool flag(true);

	cout << "Введите средства первого человека (кол-во 100, кол-во 500, кол-во 2000, кол-во 5000)" << endl;
	cin >> bill100 >> bill500 >> bill2000 >> bill5000;
	Money temp1(bill100, bill500, bill2000, bill5000);
	temp1.check_unsigned(flag);
	error(flag);

	cout << "Введите средства второго человека (кол-во 100, кол-во 500, кол-во 2000, кол-во 5000)" << endl;
	cin >> bill100 >> bill500 >> bill2000 >> bill5000;
	Money temp2(bill100, bill500, bill2000, bill5000);
	temp2.check_unsigned(flag);
	error(flag);

	cout << "Выберите операцию:" << "\n"  <<
			"1. Поменять средства первого человека" << "\n" <<
			"2. Поменять средства второго человека" << "\n" <<
			"3. Сложить средства людей" << "\n" <<
			"4. Из средств первого вычесть средства второго" << "\n" <<
			"5. Вывести средства первого" << "\n" << 
			"6. Вывести средства второго" << "\n" <<
			"0. Завершить работу" << "\n" << endl;
	int x;
	Money tempSum;
	Money tempSubtraction;
	do
	{
		cout << "Выберите операцию" << endl;
		cin >> x;
		switch (x)
		{
		case 1:
		{
			cout << "Введите средства первого человека (кол-во 100, кол-во 500, кол-во 2000, кол-во 5000)" << endl;
			cin >> bill100 >> bill500 >> bill2000 >> bill5000;
			temp1.set_bill_100(bill100);
			temp1.set_bill_500(bill500);
			temp1.set_bill_2000(bill2000);
			temp1.set_bill_5000(bill5000);
			temp1.check_unsigned(flag);
			error(flag);
			break;
		}
		case 2:
		{
			cout << "Введите средства второго человека (кол-во 100, кол-во 500, кол-во 2000, кол-во 5000)" << endl;
			cin >> bill100 >> bill500 >> bill2000 >> bill5000;
			temp2.set_bill_100(bill100);
			temp2.set_bill_500(bill500);
			temp2.set_bill_2000(bill2000);
			temp2.set_bill_5000(bill5000);
			temp2.check_unsigned(flag);
			error(flag);
			break;
		}
		case 3:
		{
			tempSum = temp1.sum(temp2);
			cout << tempSum.toString() << endl;
			break;
		}
		case 4:
		{
			tempSubtraction = temp1.subtraction(temp2, subtractionError);
			break;
		}
		case 5:
		{
			cout << temp1.toString() << endl;
			break;
		}
		case 6:
		{
			cout << temp2.toString() << endl;
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