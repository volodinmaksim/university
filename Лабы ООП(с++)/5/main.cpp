#include "Ellipse.h"
#include "Hyperbola.h"

int main()
{
    setlocale(0, "");


    double X, a_, b_;
    cout << "Введите x и коэффициенты a,b: (x, a, b) " << endl;
    cin >> X >> a_ >> b_;

    Function* hyperbola = new Hyperbola(a_, b_);
    Function* ellipse = new Ellipse(a_, b_);

    int choice;
    cout << "\nМеню:\n";
    cout << "1. Эллипс\n";
    cout << "2. Гипербола\n";
    cout << "0. Завершить работу\n";
    
    do
    {
        cout << "Выберите операцию: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << ellipse->toString(X) << endl;
            break;
        }
        case 2:
        {
            cout << hyperbola->toString(X) << endl;
            break;
        }
        case 0:
        {
            cout << "Новые значения\n";
            break;
        }
        default:
        {
            cout << "Введена неверная цифра, попробуйте снова.\n";
            break;
        }
        }
    } while (choice != 0);
}