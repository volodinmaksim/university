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

	cout << "Введите название товара: ";
	cin >> title;

	cout << "Введите дату регистрации:\n";
	cout << "  День: ";
	cin >> day;
	cout << "  Месяц: ";
	cin >> month;
	cout << "  Год: ";
	cin >> year;

	cout << "Введите количество: ";
	cin >> quantity;

	cout << "Введите номер документа: ";
	cin >> numberOfDoc;

	cout << "Введите цену:\n";
	cout << "  Рубли: ";
	cin >> rub;
	cout << "  Копейки: ";
	cin >> cop;

	Money price(rub, cop);
	Date dataOfRegister(day, month, year);
	Goods goods(price, title, dataOfRegister, quantity, numberOfDoc);

    int choice;

    do {
        cout << "\nМеню:\n";
        cout << "1. Изменить цену\n";
        cout << "2. Изменить количество\n";
        cout << "3. Показать общую стоимость\n";
        cout << "4. Уценить товар\n";
        cout << "5. Показать информацию о товаре\n";
        cout << "0. Завершить работу\n";
        cout << "Выберите операцию: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int rub, cop;
            cout << "Введите новую цену (рубли и копейки): ";
            cin >> rub >> cop;
            goods.changeThePrice(rub, cop);
            cout << "Цена изменена.\n";
            break;
        }
        case 2: {
            int delta;
            cout << "Введите изменение количества (положительное или отрицательное): ";
            cin >> delta;
            goods.changeTheQuantity(delta);
            cout << "Количество изменено.\n";
            break;
        }
        case 3: {
            cout << "Общая стоимость: " << goods.toCost() << " руб.\n";
            break;
        }
        case 4: {
            Date currentDate(26, 10, 2024); 
            goods.markDown(currentDate);
            cout << "Товар уценён в зависимости от просрочки.\n";
            break;
        }
        case 5: {
            cout << goods << endl;
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

    return 0;
}