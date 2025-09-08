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
    cout << "\nМеню:\n";
    cout << "1. Ввести первый список\n";
    cout << "2. Ввести второй список\n";
    cout << "3. Удалить группу(из 1 list-а)\n";
    cout << "4. Добавить группу(из 1 list-а)\n";
    cout << "5. Заменить группу(из 1 list-а)\n";
    cout << "6. Найти группу(из 1 list-а)\n";
    cout << "7. Объединение\n";
    cout << "8. Пересечение\n";
    cout << "0. Завершить работу\n";

    do {
        cout << "Выберите операцию: ";
        cin >> choice;

        switch (choice) {
        case 1:
        {
            cout << "Вводите числа (до 0) :" << endl;
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
            cout << "Вводите числа (до 0) :" << endl;
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
            cout << "[1]Введите с какого индекса удалить(начинаются индексы с 1) и [2]количество элементов" << endl;
            cin >> startIndex >> amount;
            list.deleteGroup(startIndex, amount);
            PrintList(list);
            break;
        }
        case 4:
        {
            cout << "[1]Введите с какого индекса добавить(начинаются индексы с 1), [2] количество элементов и что хотите вставить[3]" << endl;
            cin >> startIndex >> amount;
            list.addGroup(startIndex, amount, cin);
            PrintList(list);
            break;
        }
        case 5:
        {
            cout << "[1]Введите с какого индекса заменить(начинаются индексы с 1), [2] количество элементов и что хотите вставить заместо[3]" << endl;
            cin >> startIndex >> amount;
            list.replaceGroup(startIndex, amount, cin);
            PrintList(list);
            break;
        }
        case 6:
        {
            cout << "[1]Введите количество элементов и[2] последовательность которую хотите найти" << endl;
            cin >> amount;
            if (list.searchGroup(amount, cin))
                cout << "есть" << endl;
            else
                cout << "нету" << endl; 
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
            cout << "Завершение работы...\n";
            break;
        default:
            cout << "Введена неверная цифра, попробуйте снова.\n";
            break;
        }
    } while (choice != 0);

}