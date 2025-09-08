#pragma once
#include <iostream>
using namespace std;

template <class Data>
class Queue
{
	struct Node
	{
		Data data;
		Node* next;
		Node(Data elem) : data(elem), next(nullptr) {};
	};
	Node* head, * tail;

public:
	
	Queue()
	{
		head = tail = nullptr;
	}

	~Queue()
	{
		while (!isEmpty())
			pop();
	}

	inline void push(Data elem)
	{
		Node* p = new Node(elem);
		if (head == nullptr)
			head = tail = p;
		else
		{
			tail->next = p;
			tail = p;
		}
	}

	inline void pop()
	{
		if (isEmpty())
			return;
		Node* p = head;
		head = head->next;
		p->next = nullptr;
		delete p;
		p = nullptr;	
	}

	inline Data peek()
	{
		return head->data;
	}

	
	inline bool isEmpty()
	{
		return head == nullptr;
	}
};


