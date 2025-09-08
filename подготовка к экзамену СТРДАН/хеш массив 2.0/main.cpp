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
    enum Status { FREE, DELETED, USED };
    struct Cell
    {
        Item elem;
        Status status;

        Cell(Item elem) : elem(elem), status(FREE) {}
        Cell() : elem(Item()), status(FREE) {}
    };

    Cell* table;
    int C, SIZE, amount;

    int hash(int i, long long h)
    {
        return (h + i * C) % SIZE;
    }

    void insertToTable(Cell*& table, const Item& elem)
    {
        int h = elem.hash() % SIZE;
        if (table[h].status != USED)
        {
            table[h].elem = elem;
            table[h].status = USED;
        }
        else
        {
            int i = 0;
            int hash_i = hash(i, h);
            while (table[hash_i].status == USED)
            {
                ++i;
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
        int hash_i = hash(h, i);
        while (table[hash_i].status != FREE)
        {
            if (table[hash_i].status == USED && table[hash_i].elem == elem)
            {
                return hash_i;
            }
            ++i;
            hash_i = hash(h, i);
        }
        return -1;
    }



public:

    HashTable(int size)
    {
        SIZE = size;
        table = new Cell[SIZE];
        C = 1;
        amount = 0;
    }

    ~HashTable()
    {
        delete[] table;
    }


    void insert(const Item& elem)
    {
        if (amount * 3 > SIZE * 2)
            resize();
        insertToTable(table, elem);
        amount++;
    }

    bool search(const Item& elem)
    {
        if (indexOf(elem) == -1)
            return false;
        return true;
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


    void resize()
    {
        Cell* tmp = new Cell[SIZE * 2];
        for (int i = 0; i < SIZE; i++)
        {
            if (table[i].status == USED)
            {
                insertToTable(tmp, table[i].elem);
            }
        }
        SIZE *= 2;
        delete[] table;
        table = tmp;
    }
};