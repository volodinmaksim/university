#include "Complex.h"
#include "Pair.h"

int main()
{
    setlocale(LC_ALL, "RU");
  
    Complex res;
    cout << "������� ������ ����������� �����: " << endl;
    Complex first;
    cin >> first;
    
    cout << "������� ������ ����������� �����: " << endl;
    Complex second;
    cin >> second;
    
    
    int choice;
    cout << "\n����:\n";
    cout << "1. �������� ������� �����\n";
    cout << "2. �������� ������ �����\n";
    cout << "3. �������\n";
    cout << "4. �������\n";
    cout << "5. ��������\n";
    cout << "0. ��������� ������\n";

    do {
        cout << "�������� ��������: ";
        cin >> choice;

        switch (choice) {
        case 1:
        {
            cout << "������� ����� �����:" << endl;
            cin >> first;
            break;
        }
        case 2: 
        {
            cout << "������� ����� �����:" << endl;
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
            cout << "���������� ������...\n";
            break;
        default:
            cout << "������� �������� �����, ���������� �����.\n";
            break;
        }
    } while (choice != 0);
}