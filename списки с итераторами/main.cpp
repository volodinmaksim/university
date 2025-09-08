#include<iostream>
#include "List.h"
using namespace std;

int main()
{
	List list;
	list.add(5);
	list.add(1);
	list.add(52);
	float avg = 0;
	int count = 0;
	for (List::Iterator it = list.start(); it != list.end(); it++)
	//for (int elem: list)
	{
		avg += *it;
		count++;
	}
	cout << avg/count;
}