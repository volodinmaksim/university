#include <iostream>
#include "Money.h"
#include <cstdlib>
using namespace std;

void error(bool flag)
{
	if (!flag)
	{
		cerr << "������� ������������ ��������" << endl;
		exit(0);
	}
}

void subtractionError(bool flag)
{
	if (!flag)
	{
		cerr << "����������� ��������!!!" << endl << endl;
	}
}

int main()
{
	void (*ptrError)(bool) = error;
	setlocale(0, "");
	int bill100, bill500, bill2000, bill5000;
	bool flag(true);

	cout << "������� �������� ������� �������� (���-�� 100, ���-�� 500, ���-�� 2000, ���-�� 5000)" << endl;
	cin >> bill100 >> bill500 >> bill2000 >> bill5000;
	Money temp1(bill100, bill500, bill2000, bill5000);
	temp1.check_unsigned(flag);
	error(flag);

	cout << "������� �������� ������� �������� (���-�� 100, ���-�� 500, ���-�� 2000, ���-�� 5000)" << endl;
	cin >> bill100 >> bill500 >> bill2000 >> bill5000;
	Money temp2(bill100, bill500, bill2000, bill5000);
	temp2.check_unsigned(flag);
	error(flag);

	cout << "�������� ��������:" << "\n"  <<
			"1. �������� �������� ������� ��������" << "\n" <<
			"2. �������� �������� ������� ��������" << "\n" <<
			"3. ������� �������� �����" << "\n" <<
			"4. �� ������� ������� ������� �������� �������" << "\n" <<
			"5. ������� �������� �������" << "\n" << 
			"6. ������� �������� �������" << "\n" <<
			"0. ��������� ������" << "\n" << endl;
	int x;
	Money tempSum;
	Money tempSubtraction;
	do
	{
		cout << "�������� ��������" << endl;
		cin >> x;
		switch (x)
		{
		case 1:
		{
			cout << "������� �������� ������� �������� (���-�� 100, ���-�� 500, ���-�� 2000, ���-�� 5000)" << endl;
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
			cout << "������� �������� ������� �������� (���-�� 100, ���-�� 500, ���-�� 2000, ���-�� 5000)" << endl;
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
			cout << "������� �������� �����, ������� �����)" << endl;
			cin >> x;
			break;
		}
		}
	} while (x != 0);

}