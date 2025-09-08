#pragma once
#include <iostream>
#include <ostream>
#include <string>
using namespace std;

template <class Data>
class List
{
	struct Node
	{
		Data data;
		Node* next;
		Node* prev;

		Node(Data elem) : next(nullptr), prev(nullptr), data(elem){};
	};
	
	Node* head;


	void swapElem(Data& a, Data& b)
	{
		Data temp = a;
		a = b;
		b = temp;
	}
	
public:

	List() : head(nullptr) {};
	List(Data elem) 
	{
		head = new Node(elem);
	}
	bool isEmpty()
	{
		return head == nullptr;
	}
	void addElemFromEnd(Data data)
	{
		Node* p = new Node(data);
		if (isEmpty())
		{
			head = p;
		}
		else
		{
			Node* cur = head;
			while (cur->next != nullptr)
			{
				cur = cur->next;
			}
			p->prev = cur;
			cur->next = p;
		}
	}
	
	friend ostream& operator<< (ostream& out, const List& obj)
	{
		Node* cur = obj.head;
		while (cur != nullptr)
		{
			out << cur->data << "; ";
			cur = cur->next;
		}
		return out;
	}


	void sorted()
	{
		if (isEmpty())
			return;

		bool flag;
		Node* temp;
		Node* lastSort = nullptr;

		do {
			flag = false;
			temp = head;

			while (temp->next != lastSort)
			{
				if (temp->data > temp->next->data)
				{
					swapElem(temp->data, temp->next->data);
					flag = true;
				}
				temp = temp->next;
			}
			lastSort = temp;
		} while (flag);
	}
};

