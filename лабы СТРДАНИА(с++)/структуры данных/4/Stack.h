#pragma once
#include <iostream>
using namespace std;

template <class Data>
class Stack
{
	struct Node
	{
		Data data;
		Node* next;
		Node() : data(0), next(nullptr) {};
		Node(Data elem) : data(elem), next(nullptr) {};
	};
	Node* top;
public:

	Stack()
	{
		top = nullptr;
	}

	Stack(const Stack& other)
	{
		if (other.top == nullptr)
		{
			top = nullptr;
		}
		else
		{
			top = new Node;
			top->data = other.top->data;
			top->next = nullptr;
			Node* p = top;
			Node* cur = other.top->next;
			while (cur != nullptr)
			{
				p->next = new Node;
				p->next->data = cur->data;
				p->next->next = nullptr;
				p = p->next;
				cur = cur->next;
			}

		}
	}

	~Stack()
	{
		while (!isEmpty())
		{
			pop();
		}
	}

	bool isEmpty()
	{
		return top == nullptr;
	}

	void push(Data elem)
	{
		Node* temp = new Node;
		temp->data = elem;
		temp->next = top;
		top = temp;
	}

	void pop()
	{
		if (!isEmpty())
		{
			Node* p = top;
			top = p->next;
			p->next = nullptr;
			delete p;
			p = nullptr;
		}
	}


	Data peek()
	{
		if (!isEmpty())
			return top->data;
	}


};


