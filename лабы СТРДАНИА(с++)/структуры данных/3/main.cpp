#include <iostream>
#include <ostream>
#include <istream>
#include "Queue.h"
#include "Stack.h"
using namespace std;

class Info
{
	int a, b, c;
public:
	Info(int a = 0, int b = 0, int c = 0) : a(a), b(b), c(c) {};
	friend ostream& operator<<(ostream& out, const Info& obj)
	{
		out << "(" << obj.a << ", " << obj.b << ", " << obj.c << ")";
		return out;
	}
	friend istream& operator>>(istream& in, Info& obj)
	{
		in >> obj.a >> obj.b >> obj.c;
		return in;
	}
};

int main()
{
	setlocale(0, "");
	Info I;
	Stack<Info> stack;
	Queue<Info> queue;
	int choice;
	do
	{
		cout << "�������� ����(1) ��� �������(2):" << "\n";
		cin >> choice;
		if (choice == 1)
		{
			cout << "��������:" << "\n" <<
				"1. �������� �������" << "\n" <<
				"2. ������� �������" << "\n" <<
				"3. ���������� �������" << "\n" <<
				"0. ��������� ���������" << "\n";
			do
			{
				cout << "�������� ��������" << endl;
				cin >> choice;
				switch (choice)
				{
				case 1:
				{
					cout << "������� �������(point 3D): ";
					cin >> I;
					stack.push(I);
					break;
				}
				case 2:
				{
					stack.pop();
					break;
				}
				case 3:
				{
					if (!stack.isEmpty())
						cout << stack.peek() << endl;
					else
						cout << "���� ����" << endl;
				}
				case 0:
					break;
				default:
				{
					cout << "������� �������� �����, ������� �����" << endl;
					break;
				}
				}
			} while (choice != 0);
		}
		else if (choice == 2)
		{
			cout << "��������:" << "\n" <<
				"1. �������� �������" << "\n" <<
				"2. ������� �������" << "\n" <<
				"3. ���������� �������" << "\n" <<
				"0. ��������� ���������" << "\n";
			do
			{
				cout << "�������� ��������" << endl;
				cin >> choice;
				switch (choice)
				{
				case 1:
				{
					cout << "������� �������(point 3D): ";
					cin >> I;
					queue.push(I);
					break;
				}
				case 2:
				{
					queue.pop();
					break;
				}
				case 3:
				{
					if (!queue.isEmpty())
						cout << queue.peek() << endl;
					else
						cout << "������� ������" << endl;
					break;
				}
				case 0:
					break;
				default:
				{
					cout << "������� �������� �����, ������� �����" << endl;
					break;
				}
				}
			} while (choice != 0);
		}
		else if (choice == 0)
			break;
		else
			cout << "������ �����" << endl;
	} while (choice != 1 || choice != 2 || choice != 0);
}