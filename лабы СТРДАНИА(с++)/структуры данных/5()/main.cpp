#include <iostream>
#include "AVLTree.h"
#include <time.h>
#include <chrono>
#include <locale>
using namespace std;

void readtxt(ifstream& filein, AVLTree& tree)
{
    if (!filein.is_open())
    {
        cerr << "Ошибка открытия файла Больничный лист.txt" << endl;
        return;
    }
    string number;
    int temp;
    while (getline(filein, number, ' '))
    {
        stringstream num(number);
        num >> temp;
        tree.insert(temp);
    }
}

void deleteOutOfString(string& str)
{
    int spisok[10] = {0};
    for (int i = 0; i < str.length(); i++)
    {
        spisok[str[i] - '0']++;
    }
    stringstream ss(str);
    string str1;
    str.clear();
    while (getline(ss, str1, ' '))
    {
        string newNumber = "";
        for (int i = 0; i < str1.length(); i++)
        {
            if (spisok[str1[i] - '0'] <= 1)
                newNumber += str1[i];
        }
        if (!newNumber.empty())
            newNumber += ' ';
        str += newNumber;
    }

}



int main()
{
    setlocale(LC_ALL, "RU");
    ifstream fileInTree("Числа.txt");
    ifstream fileInStr("Числа.txt");

    AVLTree Tr;
    readtxt(fileInTree, Tr);
    
    string str;
    if (!fileInStr.is_open())
    {
        cerr << "Ошибка открытия файла Больничный лист.txt" << endl;
        return 0;
    }
    getline(fileInStr, str);

    cout << str << endl;
    auto start1 = chrono::high_resolution_clock::now();
    deleteOutOfString(str);
    auto end1 = chrono::high_resolution_clock::now();
    chrono::duration<double> duration1 = end1 - start1;
    cout << str << endl;
    cout << endl;

    Tr.drawTree();
    auto start2 = chrono::high_resolution_clock::now();
    Tr.deleteNumber();
    auto end2 = chrono::high_resolution_clock::now();
    chrono::duration<double> duration2 = end2 - start2;
    Tr.drawTree();

    cout << "\nВремя выполнения deleteOutOfString: " << duration1.count() << " секунд" << endl;
    cout << "\nВремя выполнения deleteNumber: " << duration2.count() << " секунд" << endl;
    
    
    
}