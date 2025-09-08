#include "Complex.h"
#include "Pair.h"

int main()
{
    setlocale(LC_ALL, "RU");
  
    Complex res;
    cout << "Введите первое комплексное число: " << endl;
    Complex first;
    cin >> first;
    
    cout << "Введите второе комплексное число: " << endl;
    Complex second;
    cin >> second;
    
    
    int choice;
    cout << "\nМеню:\n";
    cout << "1. Изменить перовое число\n";
    cout << "2. Изменить второе число\n";
    cout << "3. Сложить\n";
    cout << "4. Вычесть\n";
    cout << "5. Умножить\n";
    cout << "0. Завершить работу\n";

    do {
        cout << "Выберите операцию: ";
        cin >> choice;

        switch (choice) {
        case 1:
        {
            cout << "Введите новое число:" << endl;
            cin >> first;
            break;
        }
        case 2: 
        {
            cout << "Введите новое число:" << endl;
            cin >> second;
            break; 
        }
        case 3: 
        {
            cout << *(first + second) << endl;
            break;
        }
        case 4: 
        {
            cout << *(first - second) << endl;
            break;
        }
        case 5:
        {
            cout << first * second << endl;
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