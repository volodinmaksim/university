#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include "Collection.h"
using namespace std;

struct elem
{
	string word;
	int value;
	elem(string word, int elem) : value(elem), word(word) {};
	

	bool operator==(const elem& other)
	{
		return this->value == other.value;
	}
	bool operator!=(const elem& other)
	{
		return !this->operator==(other);
	}
	bool operator>(const elem& other)
	{
		return this->value > other.value;
	}
	bool operator<(const elem& other)
	{
		return this->value < other.value;
	}
	bool operator>=(const elem& other)
	{
		return !this->operator<(other);
	}
	bool operator<=(const elem& other)
	{
		return !this->operator>(other);
	}
};




int main()
{
	setlocale(0, "");
	string text;
	cout << "Введите название текста: " << endl;
	cin >> text;
	ifstream readfile(text + ".txt");
	if (!readfile)
	{
		cerr << "не удалось открыть файл" << endl;
		return 1;
	}
	int amountUnicElem = 0;
	string word;
	Сollection dict;
	list<elem> spicok;
	//elem a("f", 0), b("g", 0), c("h", 0), d("k", 0), e("fdf", 0), f("sf", 0);
	
	while (!readfile.eof())
	{
		readfile >> word;
		word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
		for (char& c : word) {
			c = tolower(c);
		}

		if (dict.peek(word) == 0)
		{
			spicok.push_front(elem(word, 0));
			dict.add(word, 1);
		}
		else
		{
			dict.add(word, dict.peek(word)+1);
		}
	}
	
	for (elem& value : spicok) {
		value.value = dict.peek(value.word);
	}

	spicok.sort([](elem a, elem b) { return a > b; });


	int n, k, prev = -1, count = 0;
	cout << "Введите n" << endl;
	cin >> n;
	cout << "Введите k " << endl;
	cin >> k;

	/*for (elem& value : spicok) {
		cout << value.word << "|" << value.value << endl;
	}*/

	for (elem& value : spicok) 
	{
		if (n == count and prev != value.value)
		{
			break;
		}
		if (value.word.length() >= k)
		{
			if (prev != value.value)
			{
				count++;
			}
			prev = value.value;
			cout << value.word << " | " << value.value << endl;
		}


	}

	readfile.close();
}