#include "List.h"


void List::addToHead(int elem)
{
	Node* tmp = new Node(elem);
	tmp->next = head;
	head = tmp;
}

void List::addAfterNode(Node* p, int elem)
{
	Node* tmp = new Node(elem);
	tmp->next = p->next;
	p->next = tmp;
}

List::Node* List::findPlace(int elem)
{
	Node* cur = head;
	while (cur->next != nullptr && cur->data < elem)
	{
		cur = cur->next;
	}
	return cur;
}

List::List(const List& other)
{
}

List::~List()
{
}

//List& List::operator=(const List& other)
//{
//	// TODO: вставьте здесь оператор return
//}

void List::clear()
{

}

void List::add(int elem)
{
	if (head == nullptr || elem < head->data)
	{
		addToHead(elem);
	}
	else
	{
		Node* p = findPlace(elem);
		addAfterNode(p, elem);
	}
}

void List::remove()
{
}

List::Iterator List::start()
{
	return Iterator(head);
}

List::Iterator List::end()
{
	return Iterator();
}

List::Iterator& List::Iterator::operator++()
{
	current = current->next;
	return *this;
}

List::Iterator List::Iterator::operator++(int)
{
	Iterator temp(current);
	current = current->next;
	return temp;
}


int List::Iterator::operator*()
{
	return current->data;
}

bool List::Iterator::operator==(const Iterator& other)
{
	return current == other.current;
}

bool List::Iterator::operator!=(const Iterator& other)
{
	return  current != other.current;
}
