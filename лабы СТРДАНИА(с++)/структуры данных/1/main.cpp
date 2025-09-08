#include <iostream> 
#include "Node.h" 
using namespace std;


int main()
{
	setlocale(0, "");
	int x, value, data(0), n(0);
	Node* list;
	initList(list, data);

	cout << "�������� ��������:" << "\n" <<
		"1. �������� ������� � ������" << "\n" <<
		"2. �������� ������� � �����" << "\n" <<
		"3. �������� ������� ����� ��������" << "\n" <<
		"4. ������� ���� ������" << "\n" <<
		"5. ������� ������ �������" << "\n" <<
		"6. ������� ��������� �������" << "\n" <<
		"7. ������� ������� ����� ��������" << "\n" <<
		"8. ������� ��� ���������" << "\n" <<
		"9. ����� �������� � ������" << "\n" <<
		"10. �������� ������ ������ ���������" << "\n" <<
		"0. ��������� ���������" << "\n";

	deleteElemFromEnd(list);

	do
	{
		cout << "�������� ��������" << endl;
		cin >> x;
		switch (x)
		{
		case 1:
		{
			cout << "������� �������" << endl;
			cin >> data;
			addElemFromHead(list, data);
			printList(list);
			break;
		}
		case 2:
		{
			cout << "������� �������" << endl;
			cin >> data;
			addElemFromEnd(list, data);
			printList(list);
			break;
		}
		case 3:
		{
			cout << "������� �������, ����� �������� ������ ��������" << endl;
			cin >> value;
			cout << "������� �������, ������� ������ ��������" << endl;
			cin >> data;
			addElem(list, data, value);
			printList(list);
			break;
		}
		case 4:
		{
			removeList(list);
			printList(list);
			break;
		}
		case 5:
		{
			deleteElemFromHead(list);
			printList(list);
			break;
		}
		case 6:
		{
			deleteElemFromEnd(list);
			printList(list);
			break;
		}
		case 7:
		{
			cout << "������� �������, ����� �������� ������ �������" << endl;
			cin >> value;
			deleteAfterElem(list, value);
			printList(list);
			break;
		}
		case 8:
		{
			cout << "������� �������, ������� ������ �������" << endl;
			cin >> value;
			deleteAllValue(list, value);
			printList(list);
			break;
		}
		case 9:
		{
			cout << "������� �������, ������� ������ �����" << endl;
			cin >> value;
			if (search(list, value))
				cout << "������� ������" << endl;
			else
				cout << "������� �� ������" << endl;
			break;
		}
		case 10:
			deleteNotFirstEntry(list);
			printList(list);
			break;
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