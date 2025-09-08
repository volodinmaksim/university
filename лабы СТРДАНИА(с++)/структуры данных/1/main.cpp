#include <iostream> 
#include "Node.h" 
using namespace std;


int main()
{
	setlocale(0, "");
	int x, value, data(0), n(0);
	Node* list;
	initList(list, data);

	cout << "Выберите операцию:" << "\n" <<
		"1. Добавить элемент в начало" << "\n" <<
		"2. Добавить элемент в конец" << "\n" <<
		"3. Добавить элемент после заданого" << "\n" <<
		"4. Удалить весь список" << "\n" <<
		"5. Удалить первый элемент" << "\n" <<
		"6. Удалить последний элемент" << "\n" <<
		"7. Удалить элемент после заданого" << "\n" <<
		"8. Удалить все вхождения" << "\n" <<
		"9. Поиск элемента в списке" << "\n" <<
		"10. Оставить только первые вхождения" << "\n" <<
		"0. Завершить программу" << "\n";

	deleteElemFromEnd(list);

	do
	{
		cout << "Выберите операцию" << endl;
		cin >> x;
		switch (x)
		{
		case 1:
		{
			cout << "Введите элемент" << endl;
			cin >> data;
			addElemFromHead(list, data);
			printList(list);
			break;
		}
		case 2:
		{
			cout << "Введите элемент" << endl;
			cin >> data;
			addElemFromEnd(list, data);
			printList(list);
			break;
		}
		case 3:
		{
			cout << "Введите элемент, после которого хотите вставить" << endl;
			cin >> value;
			cout << "Введите элемент, который хотите вставить" << endl;
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
			cout << "Введите элемент, после которого хотите удалить" << endl;
			cin >> value;
			deleteAfterElem(list, value);
			printList(list);
			break;
		}
		case 8:
		{
			cout << "Введите элемент, который хотите удалить" << endl;
			cin >> value;
			deleteAllValue(list, value);
			printList(list);
			break;
		}
		case 9:
		{
			cout << "Введите элемент, который хотите найти" << endl;
			cin >> value;
			if (search(list, value))
				cout << "Элемент найден" << endl;
			else
				cout << "Элемент не найден" << endl;
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
			cout << "Введена неверная цифра, введите новую" << endl;
			break;
		}
		}
	} while (x != 0);

}