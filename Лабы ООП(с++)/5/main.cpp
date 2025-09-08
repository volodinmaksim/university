#include "Ellipse.h"
#include "Hyperbola.h"

int main()
{
    setlocale(0, "");


    double X, a_, b_;
    cout << "������� x � ������������ a,b: (x, a, b) " << endl;
    cin >> X >> a_ >> b_;

    Function* hyperbola = new Hyperbola(a_, b_);
    Function* ellipse = new Ellipse(a_, b_);

    int choice;
    cout << "\n����:\n";
    cout << "1. ������\n";
    cout << "2. ���������\n";
    cout << "0. ��������� ������\n";
    
    do
    {
        cout << "�������� ��������: ";
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
            cout << "����� ��������\n";
            break;
        }
        default:
        {
            cout << "������� �������� �����, ���������� �����.\n";
            break;
        }
        }
    } while (choice != 0);
}