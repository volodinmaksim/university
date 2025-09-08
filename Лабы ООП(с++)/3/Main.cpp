#include <iostream>
#include <windows.h>
#include "Money.h"
#include "Goods.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");
    SetConsoleOutputCP(1251);
    int rub, cop, day, month, year, quantity, numberOfDoc;
	string title;

	cout << "������� �������� ������: ";
	cin >> title;

	cout << "������� ���� �����������:\n";
	cout << "  ����: ";
	cin >> day;
	cout << "  �����: ";
	cin >> month;
	cout << "  ���: ";
	cin >> year;

	cout << "������� ����������: ";
	cin >> quantity;

	cout << "������� ����� ���������: ";
	cin >> numberOfDoc;

	cout << "������� ����:\n";
	cout << "  �����: ";
	cin >> rub;
	cout << "  �������: ";
	cin >> cop;

	Money price(rub, cop);
	Date dataOfRegister(day, month, year);
	Goods goods(price, title, dataOfRegister, quantity, numberOfDoc);

    int choice;

    do {
        cout << "\n����:\n";
        cout << "1. �������� ����\n";
        cout << "2. �������� ����������\n";
        cout << "3. �������� ����� ���������\n";
        cout << "4. ������� �����\n";
        cout << "5. �������� ���������� � ������\n";
        cout << "0. ��������� ������\n";
        cout << "�������� ��������: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int rub, cop;
            cout << "������� ����� ���� (����� � �������): ";
            cin >> rub >> cop;
            goods.changeThePrice(rub, cop);
            cout << "���� ��������.\n";
            break;
        }
        case 2: {
            int delta;
            cout << "������� ��������� ���������� (������������� ��� �������������): ";
            cin >> delta;
            goods.changeTheQuantity(delta);
            cout << "���������� ��������.\n";
            break;
        }
        case 3: {
            cout << "����� ���������: " << goods.toCost() << " ���.\n";
            break;
        }
        case 4: {
            Date currentDate(26, 10, 2024); 
            goods.markDown(currentDate);
            cout << "����� ����� � ����������� �� ���������.\n";
            break;
        }
        case 5: {
            cout << goods << endl;
            break;
        }
        case 0:
            cout << "���������� ������...\n";
            break;
        default:
            cout << "������� �������� �����, ���������� �����.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}