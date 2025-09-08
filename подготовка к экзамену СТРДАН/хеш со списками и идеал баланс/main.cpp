#include <iostream>
using namespace std;


class Item
{
	int id;
	string name;
public:
	Item(int id = 0, string name = " ") : id(id), name(name) {}
	Item(const Item& other) : id(other.id), name(other.name) {}

	Item& operator=(const Item& obj) {
		if (this != &obj)
		{
			id = obj.id;
			name = obj.name;
		}
		return *this;
	}

	bool operator==(const Item& obj) {
		if (this->id == obj.id && this->name == obj.name)
			return true;
		return false;
	}

	friend ostream& operator<<(ostream& os, const Item& obj) {
		return os << obj.name << " " << obj.id;
	}

	long long hash() const
	{
		long long h = 0;
		for (int i = 0; i < name.length(); i++) {
			h += (int)name[i] * pow(23, i);
		}
		return h + id;
	}
};


class HashTable
{
	struct Node 
	{
		Item elem;
		Node* next;

		Node() : elem(Item()), next(nullptr) {}
		Node(Item elem) : elem(elem), next(nullptr) {}
		~Node() { delete next; next = nullptr; }
	};

	Node** table;
	int SIZE;
	int amount;

	void clear(Node* head)
	{
		while (head)
			deleteFromHead(head);
	}

	void deleteFromHead(Node*& head)
	{
		if (head == nullptr)
			return;
		Node* p = head;
		head = head->next;
		delete p;
		p = nullptr;
	}

	void addToHead(Node*& head, const Item& elem)
	{
		Node* p = new Node(elem);
		p->next = head; 
		head = p;
	}

public:

	HashTable(int size)
	{
		SIZE = size;
		amount = 0;
		table = new Node * [SIZE];
		for (int i = 0; i < SIZE; i++)
		{
			table[i] = nullptr;
		}
	}

	~HashTable()
	{
		for (int i = 0; i < SIZE; i++)
		{
			clear(table[i]);
		}
		delete[] table;
	}

	void resize()
	{
		Node** tmp = new Node * [SIZE * 2];
		for (int i = 0; i < SIZE * 2; i++)
		{
			tmp[i] = nullptr;
		}

		for (int i = 0; i < SIZE; i++)
		{
			if (table[i])
			{
				Node* cur = table[i];
				int h = cur->elem.hash() % SIZE * 2;
				while (cur != nullptr)
				{
					addToHead(tmp[h], cur->elem);
					cur = cur->next;
				}
			}
		}
		SIZE *= 2;
		delete[] table;
		table = tmp;
	}


	void insert(const Item& elem) 
	{
		if (amount * 3 > 2 * SIZE)
			resize();
		int h = elem.hash() % SIZE;
		addToHead(table[h], elem);
		amount++;
	}

	void deleteNode(Node*& head, Node* node) 
	{
		if (head == node && head->next == nullptr)
		{
			delete head;
			head = nullptr;
			return;
		}

		Node* curPrev = head;
		Node* cur = head->next;
		while (cur != nullptr)
		{
			if (cur == node)
			{
				curPrev->next = cur->next;
				delete cur;
				cur = nullptr;
			}
			curPrev = cur;
			cur = cur->next;
		}

	}

	void remove(const Item& elem)
	{
		int h = elem.hash() % SIZE;
		Node* cur = table[h];
		while (cur)
		{
			if (cur->elem == elem)
			{
				deleteNode(table[h], cur);
				amount--;
				return;
			}
			cur = cur->next;
		}
	}

	

	bool search(const Item& elem)
	{
		int h = elem.hash() % SIZE;
		Node* cur = table[h];
		while (cur)
		{
			if (cur->elem == elem)
			{
				return true;
			}
			cur = cur->next;
		}
		return false;
	}
};



































struct Node
{
	Item elem;
	Node* next;
	Node() : next(nullptr) {}
	Node(const Item& elem) : next(nullptr), elem(elem) {}


};

Node** table;
int SIZE;
int amount;




void addToHead(Node*& head, const Item& elem)
{
	Node* p = new Node(elem);
	if (head != nullptr)
		p->next = head;
	head = p;
}
public:

	HashTable(int size)
	{
		SIZE = size;
		amount = 0;
		table = new Node * [SIZE];
		for (int i = 0; i < SIZE; i++)
			table[i] = nullptr;
	}

	~HashTable()
	{
		for (int i = 0; i < SIZE; i++)
			clear(table[i]);
		delete[] table;
	}

	void clear(Node*& head)
	{
		while (head)
			deleteFromHead(head);
	}

	void insert(const Item& elem)
	{
		if (3 * amount > 2 * SIZE)
		{
			resize();
		}
		int h = elem.hash() % SIZE;
		addToHead(table[h], elem);
		amount++;
	}

	Node* search_pos(Node* head, const Item& elem)
	{
		Node* cur = head;
		while (cur != nullptr)
		{
			if (cur->elem == elem)
				return cur;
			cur = cur->next;
		}
	}



	void resize()
	{
		Node** tmp = new Node * [SIZE * 2];
		for (int i = 0; i < SIZE * 2; i++)
			tmp[i] = nullptr;
		for (int i = 0; i < SIZE; i++)
		{
			if (table[i])
			{
				int h = table[i]->elem.hash() % (SIZE * 2);
				addToHead(tmp[hash], table[i]->elem);
			}
		}
		SIZE *= 2;
		delete[] table;
		table = tmp;
	}