#pragma once
#include <iostream>
using namespace std;

class listBoth
{
	struct Node 
	{
		int data;
		Node* next;
		Node* prev;

		Node(int data) : data(data), next(nullptr), prev(nullptr) {}
	};
	Node* head;
	Node* tail;

public:
	listBoth()
	{

	}
};


int main()
{

}