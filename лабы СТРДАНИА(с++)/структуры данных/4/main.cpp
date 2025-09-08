#include <iostream>
#include <fstream>
#include "Stack.h"
#include "Pair.h"
#include "List.h"
#include <string>
using namespace std;

void calculator(ifstream& fileIn)
{
    char symbol;
    int count = 0;
    Stack<int> stack;
    List<Pair> list;
    while (!fileIn.eof())
    {
        symbol = fileIn.get();
        count++;
        if (symbol == '(')
            stack.push(count);
        if (symbol == ')')
        {
            Pair temp(stack.peek(), count);
            list.addElemFromEnd(temp);
            stack.pop();
        }
        
    }
    list.sorted();
    cout << list << endl;
}


int main()
{

	setlocale(0, "");
    ifstream fileIn("text.txt");
    if (!fileIn.is_open())
    {
        cerr << "Ошибка открытия файла Больничный лист.txt" << endl;
        return 1;
    }

    calculator(fileIn);


}