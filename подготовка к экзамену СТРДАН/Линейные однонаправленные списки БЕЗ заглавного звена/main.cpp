#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

void initList(Node*& head, int a)
{
	head = new Node;
	head->next = nullptr;
	head->data = a;
}

bool isEmpty(Node* head)
{
	return head == nullptr;
}

void addToHead(Node*& head, int a)
{
	Node* p = new Node;
	p->next = head;
	p->data = a;
	head = p;
}

void addElemAfterNode(Node* This, int a)
{
	if (isEmpty(This))
		return;
	Node* p = new Node;
	p->data = a;
	p->next = This->next;
	This->next = p;
}

void deleteElemFromHead(Node*& head)
{
	if (isEmpty(head))
		return;
	Node* p = head;
	head = head->next;
	delete p; 
	p = nullptr;
}

void deleteElemArterNode(Node* This)
{
	if (isEmpty(This) || This->next == nullptr)
		return;
	Node* p = This->next;
	This->next = p->next;
	delete p;
	p = nullptr;
}

void createListNorm(Node*& head, int arr[], int size)
{
	for (int i = size-1; i >= 0; --i)
	{
		if (i == size-1)
			initList(head, arr[i]);
		else
		{
			addToHead(head, arr[i]);
		}
	}
}
void createListNotNorm(Node*& head, int arr[], int size)
{
	for (int i = 0; i <  size; ++i)
	{
		if (i == 0)
			initList(head, arr[i]);
		else
		{
			addToHead(head, arr[i]);
		}
	}
}
void createListSort(Node*& head, int arr[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (i == 0)
		{
			initList(head, arr[i]);
			continue;
		}
		if (i == 1)
		{
			if (arr[i] >= head->data)
			{
				addElemAfterNode(head, arr[i]);
				continue;
			}
		}
		if (arr[i] <= head->data)
		{
			addToHead(head, arr[i]);
			continue;
		}
		Node* cur = head;
		Node* curNext = cur->next;
		while (cur->next != nullptr && arr[i] > curNext->data )
		{
			cur = cur->next;
			curNext = cur->next;
		}
		addElemAfterNode(cur, arr[i]);

	}
}

void clean(Node*& head)
{
	while (head)
		deleteElemFromHead(head);
}

void printList(Node* head)
{
	Node* cur = head;
	while (cur)
	{
		cout << cur->data << ' ';
		cur = cur->next;
	}
}




void printRec(Node* head)
{
	if (head == nullptr)
		return;
	else
	{
		printRec(head->next);
		cout << head->data << " ";
	}
}




int main()
{
	Node* head;
	int a[7] = { 6,3,5,1,2,7,4 };
	/*initList(head, a[0]);
	addElemAfterNode(head, a[1]);
	addElemAfterNode(head->next, a[2]);
	addElemAfterNode(head->next->next, a[3]);
	addElemAfterNode(head->next->next->next, a[4]);
	addElemAfterNode(head->next->next->next->next, a[5]);
	addElemAfterNode(head->next->next->next->next->next, a[6]);*/
	
	
	
	/*createListSort(head, a, 7);
	printList(head);
	clean(head);
	printList(head);*/


	createListSort(head, a, 7);
	printRec(head);
	
}