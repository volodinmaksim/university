#include <iostream>
#include <ostream>
using namespace std;


class Item 
{
	int id;
	string name;
public:
	Item(int id = 0, string name = " ") : id(id), name(name) {}
	Item(const Item& other) : id(other.id), name(other.name) {}

	Item& operator=(const Item& obj) {
		id = obj.id;
		name = obj.name;
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
	enum Status {
		FREE, USED, DELETED
	};
	struct Cell
	{
		Status status;
		Item elem;
		Cell(Item data) : status(FREE), elem(data) {}
		Cell() : status(FREE) {}
	};

	Cell* table;
	int SIZE;
	int C;
	int amount;


	int hash(int i, long long h)
	{
		return (h + i * C) & SIZE;
	}

	void resize()
	{
		int OldSize = SIZE;
		SIZE *= 2;
		Cell* tmp = new Cell[SIZE];
		for (int i = 0; i < OldSize; i++)
		{
			if (table[i].status == USED)
				insertToTable(tmp, table[i].elem);
		}
		delete[] table;
		table = tmp;
	}

	void insertToTable(Cell* table, const Item& elem)
	{
		int h = elem.hash() % SIZE;
		if (table[h].status != USED)
		{
			table->elem = elem;
			table->status = USED;
		}
		else
		{
			int i = 0;
			int hash_i = hash(i, h);
			while (table[hash_i].status == USED)
			{
				i++;
				hash_i = hash(i, h);
			}
			table[hash_i].elem = elem;
			table[hash_i].status = USED;
		}
	}

	int indexOf(const Item& elem)
	{
		int h = elem.hash() % SIZE;
		int i = 0;
		int hash_i = h;
		while (table[hash_i].status != FREE)
		{
			if (table[hash_i].status == USED && table[hash_i].elem == elem)
				return hash_i;
			i++;
			hash_i = hash(i, h);
		}
		return -1;
	}

public:


	void insert(const Item& elem)
	{
		if (amount * 3 > 2 * SIZE)
			resize();
		insertToTable(table, elem);
		amount++;
	}

	HashTable(int _size, int _c)
	{
		SIZE = _size;
		C = _c;
		amount = 0;
		table = new Cell[SIZE];
	}
	~HashTable()
	{
		delete[] table;
	}
	bool search(const Item& elem)
	{
		if (indexOf(elem) != -1)
			return true;
		return false;
	}

	void remove(const Item& elem)
	{
		int index = indexOf(elem);
		if (index != -1)
		{
			table[index].status = DELETED;
			amount--;
		}
	}
};