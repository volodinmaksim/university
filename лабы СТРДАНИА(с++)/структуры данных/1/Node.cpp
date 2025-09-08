#include <iostream> 
#include "Node.h" 
using namespace std;


void initList(Node*& head)
{
	head->next = nullptr;
}


void initList(Node*& head, int elem)
{
	head = new Node;
	head->data = elem;
	head->next = nullptr;
}


Node* initList()
{
	return nullptr;
}


void addElemFromHead(Node*& head, int data)
{
	Node* newElem = new Node;
	newElem->data = data;
	newElem->next = head;
	head = newElem;
}


void addElemFromEnd(Node*& head, int data)
{
	if (head == nullptr)
	{
		head = new Node;
		head->next = nullptr;
		head->data = data;
	}
	else
	{
		Node* point = head;
		while (point->next != nullptr)
			point = point->next;
		Node* temp = new Node;
		point->next = temp;
		temp->next = nullptr;
		temp->data = data;
	}
}


void addElem(Node* head, int data, int value)
{
	if (isEmpty(head))
	{
		return;
	}
	Node* point = head;
	while (point->data != value)
	{
		point = point->next;
		if (point == nullptr)
			return;
	}
	Node* temp = new Node;
	temp->next = point->next;
	temp->data = data;
	point->next = temp;
}

void deleteElemFromHead(Node*& head)
{
	if (!isEmpty(head))
	{
		Node* p = head;
		head = head->next;
		delete p;
		p = nullptr;
	}
}

void removeList(Node*& head)
{
		while (!isEmpty(head))
	{
		deleteElemFromHead(head);
	}
		
}



void deleteElemFromEnd(Node*& head)
{
	if (!isEmpty(head))
	{
		if (head->next == nullptr)
		{
			head = nullptr;
			delete head;
		}
		else
		{
			Node* tmp = head;
			Node* previous = tmp;
			while (tmp->next != nullptr) {
				previous = tmp;
				tmp = tmp->next;
			}
			delete tmp;
			tmp = nullptr;
			previous->next = nullptr;
		}
	}
}


void deleteAfterElem(Node* head, int value)
{
	Node* temp = head;
	while (temp != nullptr)
	{
		if (temp->next != nullptr && temp->data == value)
		{
			Node* p = temp->next;
			temp->next = p->next;
			delete p;
			p = nullptr;
			return;
		}
		temp = temp->next;
	}
}


void deleteAllValue(Node*& head, int value)
{
	if (isEmpty(head))
	{
		return;
	}
	while (head->data == value)
	{
		deleteElemFromHead(head);
		if (isEmpty(head))
		{
			return;
		}
	}

	Node* temp_prev = head;
	Node* temp = head->next;

	while (temp != nullptr)
	{
		if (temp->data == value)
		{
			temp_prev->next = temp->next;
			delete temp;
			temp = temp_prev->next;
		}
		else
		{
			temp_prev = temp;
			temp = temp->next;
		}
	}
}


bool search(Node* head, int value)
{
	if (!isEmpty(head))
	{
		Node* temp = head;
		while (temp->next != nullptr)
		{
			if (temp->data == value)
				return true;
			temp = temp->next;
		}
		if (temp->data == value)
			return true;

		return false;
	}
	else
		return false;	
}


bool isEmpty(Node* head)
{
	return head == nullptr;
}


void printList(Node* head)
{

	Node* point = head;
	if (isEmpty(head) || head == nullptr)
	{
		cout << "Список пуст" << endl;
		return;
	}
	else if (!isEmpty(head))
		cout << head->data << ' ';
	while (point->next != nullptr)
	{
		point = point->next;
		cout << point->data << ' ';
	}
	cout << endl;
}


void deleteNotFirstEntry(Node* head)
{
	if (!isEmpty(head))
	{
		
		Node* arr;
		initList(arr, head->data);
		Node* temp1 = head;
		Node* temp2 = head->next;
		if (temp1->next == nullptr)
			return;
		
		while (temp2->next != nullptr)
		{
			if (search(arr, temp2->data))
			{
				Node* p = temp2;
				temp1->next = temp2->next;
				temp2 = temp2->next;
				delete p;
				p = nullptr;
			}
			else 
			{
				addElemFromEnd(arr, temp2->data);
				temp1 = temp2;
				temp2 = temp2->next;
			}

		}
		if (search(arr, temp2->data))
		{
			Node* p = temp2;
			temp1->next = temp2->next;
			delete p;
			p = nullptr;
		}
		removeList(arr);
	}
}
