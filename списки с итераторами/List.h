#pragma once


class List
{
	struct Node
	{
		int data;
		Node* next;
		Node(int data = -1) : data(data), next(nullptr) {};
	
	};


	Node* head;
	void addToHead(int elem);
	void addAfterNode(Node* p, int elem);
	Node* findPlace(int elem);

public:


	class Iterator
	{
		Node* current;
	public:
		Iterator(Node*& p) : current(p) {};
		Iterator() : current(nullptr) {};
		Iterator& operator++();
		Iterator operator++(int);
		int operator*();
		bool operator==(const Iterator& other);
		bool operator!=(const Iterator& other);
		// operator--
	};
	List() : head(nullptr) {}
	List(const List& other);
	~List();
	List& operator=(const List& other);
	void clear();
	void add(int elem);
	void remove();
	Iterator start();
	Iterator end();


	/*{
		clear();
	}
	void clear()
	{
		while (head->next != nullptr)
		{
			remove
		}
	}*/

	//д/з как бегать по дереву
};
	