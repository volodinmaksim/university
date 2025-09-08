#include <iostream>
#include "List.h"
using namespace std;

typedef int data2;

void PrintList(const List<data2>& list)
{
    for (List<int>::Iterator it = list.start(); it != list.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    setlocale(0, "");
    List<data2> list;
    List<data2> list2;
    List<data2> listRes;


    int choice, value;

    int startIndex, amount;
    cout << "\n����:\n";
    cout << "1. ������ ������ ������\n";
    cout << "2. ������ ������ ������\n";
    cout << "3. ������� ������(�� 1 list-�)\n";
    cout << "4. �������� ������(�� 1 list-�)\n";
    cout << "5. �������� ������(�� 1 list-�)\n";
    cout << "6. ����� ������(�� 1 list-�)\n";
    cout << "7. �����������\n";
    cout << "8. �����������\n";
    cout << "0. ��������� ������\n";

    do {
        cout << "�������� ��������: ";
        cin >> choice;

        switch (choice) {
        case 1:
        {
            cout << "������� ����� (�� 0) :" << endl;
            cin >> value;
            while (value != 0)
            {
                list.add(value);
                cin >> value;
            } 
            break;
        }
        case 2:
        {
            cout << "������� ����� (�� 0) :" << endl;
            cin >> value;
            while (value != 0)
            {
                list2.add(value);
                cin >> value;
            }
            break;
        }
        case 3:
        {
            cout << "[1]������� � ������ ������� �������(���������� ������� � 1) � [2]���������� ���������" << endl;
            cin >> startIndex >> amount;
            list.deleteGroup(startIndex, amount);
            PrintList(list);
            break;
        }
        case 4:
        {
            cout << "[1]������� � ������ ������� ��������(���������� ������� � 1), [2] ���������� ��������� � ��� ������ ��������[3]" << endl;
            cin >> startIndex >> amount;
            list.addGroup(startIndex, amount, cin);
            PrintList(list);
            break;
        }
        case 5:
        {
            cout << "[1]������� � ������ ������� ��������(���������� ������� � 1), [2] ���������� ��������� � ��� ������ �������� �������[3]" << endl;
            cin >> startIndex >> amount;
            list.replaceGroup(startIndex, amount, cin);
            PrintList(list);
            break;
        }
        case 6:
        {
            cout << "[1]������� ���������� ��������� �[2] ������������������ ������� ������ �����" << endl;
            cin >> amount;
            if (list.searchGroup(amount, cin))
                cout << "����" << endl;
            else
                cout << "����" << endl; 
            break;
        }
        case 7:
        {
            list.ListsUnion(list2);
            PrintList(list);
            break;
        }
        case 8:
        {
            list.ListsIntersection(list2);
            PrintList(list);
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

}