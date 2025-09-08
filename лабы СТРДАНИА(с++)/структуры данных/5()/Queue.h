#pragma once
#include <sstream>
#include <iostream>
using namespace std;

template <typename typ>
class Queue
{
	struct Node
	{
		typ data;
		Node* next;
		Node(typ elem) :data(elem), next(nullptr) {};
	};

	Node* head;
	Node* tail;

public:

	Queue()
	{
		head = tail = nullptr;
	}
	Queue(const Queue& obj)
	{
		head = tail = nullptr;
		//count = obj.count;
		Node* temp = obj.head;
		while (temp)
		{
			enque(temp->data);
			temp = temp->next;
		}
	}
	~Queue()
	{
		clear();
	}
	Queue& operator=(const Queue& obj)
	{
		head = tail = nullptr;
		Node* temp = obj.head;
		while (temp != nullptr)
		{
			this->enque(temp->data);
			temp = temp->next;
		}
		return *this;
	}

	bool isEmpty()
	{
		return(head == nullptr && tail == nullptr);
	}

	void enque(typ elem)// Добавить элемент
	{
		Node* p = new Node(elem);
		if (isEmpty())
		{
			head = tail = p;
		}
		else
		{
			tail->next = p;
			tail = p;
		}
	}
	void deque()// Удалить элемент
	{
		if (!isEmpty())
		{
			if (head != tail)
			{
				Node* p = head;
				head = head->next;
				delete p;
				p = nullptr;
			}
			else
			{
				delete head;
				head = tail = nullptr;
			}
		}
	}
	void clear() // Очистить
	{
		while (!isEmpty())
			deque();
	}
	typ peek() // Просмотреть первый элемент
	{
		if (!isEmpty())
			return head->data;
	}

	friend ostream& operator<<(ostream& out, const Queue& obj)
	{
		stringstream s;
		Node* temp = obj.head;
		while (temp)
		{
			s << temp->data;
			temp = temp->next;
		}
		return out;
	}
};