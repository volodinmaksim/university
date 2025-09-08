#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

template <class Data>
class List
{

	/*
		Node* head;
		void addToHead(int elem);
		void addAfterNode(Node* p, data elem);
		Node* findPlace(int elem);
		void deleteElemFromHead()
		void addElemFromEnd(Data data);
		bool search(Data data)
		void toSet()
	public:
		List();
		List(const List& other);
		~list();
		void clear();
		void add(int elem);
		void remove();
		Iterator start()
		Iterator end()
		void addGroup(int startIndex, int endIndex, istream& is)
		void deleteGroup(int startIndex, int amount)
		void replaceGroup(int startIndex, int amount, istream& is)
		bool searchGrope(int amount, istream& is)
		void ListsUnion(const List& other)
		void ListsIntersection(const List& other)
	*/





	struct Node
	{
		Data data;
		Node* next;
		Node(Data data) : data(data), next(nullptr) {};
	};

	Node* head;
	void addToHead(Data elem)
	{
		Node* tmp = new Node(elem);
		tmp->next = head;
		head = tmp;
	}
	void addAfterNode(Node* p, Data elem)
	{
		Node* tmp = new Node(elem);
		tmp->next = p->next;
		p->next = tmp;
	}
	Node* findPlace(Data elem)
	{
		Node* cur = head;
		while (cur->next != nullptr && cur->data < elem)
		{
			cur = cur->next;
		}
		return cur;
	}

	void deleteElemFromHead()
	{
		if (head != nullptr)
		{
			Node* p = head;
			head = head->next;
			delete p;
			p = nullptr;
		}
	}

	void remove(Node*& p)
	{
		if (head == nullptr)
		{
			return;
		}
		if (p == head)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
			temp = nullptr;
			p = head;
			return;
		}
		Node* temp = head;
		while (temp->next != p && temp != nullptr)
			temp = temp->next;
		if (temp == nullptr || temp->next == nullptr)
			return;
		Node* ptr = temp->next;
		temp->next = ptr->next;
		ptr->next = nullptr;
		delete ptr;
		ptr = nullptr;
		p = temp->next;
	}

	void addElemFromEnd(Data data)
	{
		if (head == nullptr)
		{
			head = new Node(data);
			head->next = nullptr;
		}
		else
		{
			Node* point = head;
			while (point->next != nullptr)
				point = point->next;
			Node* temp = new Node(data);
			point->next = temp;
			temp->next = nullptr;
		}
	}

	bool search(Data data) const
	{
		if (head != nullptr)
		{
			Node* temp = head;
			while (temp->next != nullptr)
			{
				if (temp->data == data)
					return true;
				temp = temp->next;
			}
			if (temp->data == data)
				return true;

			return false;
		}
		else
			return false;
	}

	void toSet()
	{
		List<Data> temp;
		Node* cur = head;
		Node* prev = nullptr;

		while (cur != nullptr)
		{
			if (!temp.search(cur->data))
			{
				temp.addElemFromEnd(cur->data);
				prev = cur;
				cur = cur->next;
			}
			else
			{
				Node* toRemove = cur;
				cur = cur->next;
				if (prev)
				{
					prev->next = cur;
				}
				else
				{
					head = cur;
				}
				delete toRemove;
			}
		}
	}


public:




	class Iterator
	{
		Node* current;
	public:

		/*
		Iterator(Node*& p) : current(p) {};
		Iterator() : current(nullptr) {};
		Iterator& operator++();
		Iterator operator++(int);
		int operator*();
		bool operator==(const Iterator& other);
		bool operator!=(const Iterator& other);
		Iterator& operator--()
		Iterator operator--(int)
		*/


		Iterator(Node* p) : current(p) {};
		Iterator() : current(nullptr) {};


		Iterator& operator++()
		{
			current = current->next;
			return *this;
		}
		Iterator operator++(int)
		{
			Iterator temp(current);
			current = current->next;
			return temp;
		}



		Data operator*()
		{
			return current->data;
		}
		bool operator==(const Iterator& other)
		{
			if (this->current == other.current)
				return true;
			else
				return false;
		}
		bool operator!=(const Iterator& other)
		{
			return !this->operator==(other);
		}
		Node* getCurrent()
		{
			return current;
		}

	};

	List() : head(nullptr) {}
	List(const List& other)
	{
		Iterator temp(other.head);
		while (temp.getCurrent() != nullptr)
		{
			this->add(*temp);
			temp++;
		}
	}
	~List()
	{
		clear();
	}
	void clear()
	{
		while (head != nullptr)
		{
			remove(head);
		}
	}
	void add(Data elem)
	{
		/*if (head == nullptr || elem < head->data)
		{
			addToHead(elem);
		}
		else
		{
			Node* p = findPlace(elem);
			addAfterNode(p, elem);
		}*/
		addElemFromEnd(elem);
	}
	void addGroup(int startIndex, int amount, istream& is)
	{
		Data data;
		if (startIndex <= 0)
			startIndex = 1;

		if (startIndex == 1)
		{
			is >> data;
			addToHead(data);
			amount--;
			for (Iterator it = move(startIndex); it != move(startIndex + amount); it++)
			{
				is >> data;
				addAfterNode(it.getCurrent(), data);
			}
		}
		else
		{
			for (Iterator it = move(startIndex - 1); it != move(startIndex + amount - 1); it++)
			{
				is >> data;
				addAfterNode(it.getCurrent(), data);
			}
		}
	}

	void deleteGroup(int startIndex, int amount)
	{
		if (startIndex <= 0 || amount <= 0)
			return;

		Iterator it = move(startIndex);
		for (int i = 0; i < amount && it != end(); ++i)
		{
			Node* temp = it.getCurrent();
			it++;
			remove(temp);
		}
	}

	void replaceGroup(int startIndex, int amount, istream& is)
	{
		Data data;
		if (startIndex <= 0)
			startIndex = 1;
		for (Iterator it = move(startIndex); it != move(startIndex + amount); it++)
		{
			is >> data;
			it.getCurrent()->data = data;
		}
	}

	bool searchGroup(int amount, istream& is)
	{
		List<Data> temp;
		Data data;
		for (int i = 0; i < amount; i++)
		{
			is >> data;
			temp.addElemFromEnd(data);
		}
		for (Iterator it = start(); it != end(); )
		{
			Iterator tempIt = temp.start();
			Iterator currentIt = it;

			bool found = true;
			while (tempIt != temp.end())
			{
				if (currentIt == end() || *currentIt != *tempIt)
				{
					found = false;
					break;
				}
				tempIt++;
				currentIt++;
			}

			if (found)
			{
				return true;
			}
			else
			{
				it++;
			}
		}

		return false;
	}


	void ListsUnion(const List& other) 
	{
		this->toSet();
		for (List::Iterator it = other.start(); it != other.end(); it++)
		{
			if (!this->search(*it))
				this->addElemFromEnd(*it);
		}
	}
	void ListsIntersection(const List& other) 
	{
		this->toSet();
		for (List::Iterator it = this->start(); it != this->end(); )
		{
			if (!other.search(*it))
			{
				Node* p = it.getCurrent();
				it++;
				this->remove(p);
			}
			else 
			{
				it++;
			}
		}
	}


	Iterator start() const
	{
		return Iterator(head);
	}
	Iterator end() const
	{
		return Iterator();
	}
	Iterator move(int index )
	{
		Iterator temp(head);
		if (index <= 0)
			return temp;
		for (int i = 1; i < index; i++)
		{
			
			if (temp.getCurrent() == nullptr)
				return end();
			temp++;
		}
		return temp;
	}
};

