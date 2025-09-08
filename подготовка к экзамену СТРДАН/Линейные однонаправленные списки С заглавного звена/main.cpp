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
	head->next = new Node;
	head->next->data = a;
	head->next->next = nullptr;
}

bool isEmpty(Node* head)
{
	return head->next == nullptr;
}

void addElemAfterNode(Node* This, int a)
{
	if (This == nullptr)
		return;
	Node* p = new Node;
	p->data = a;
	p->next = This->next;
	This->next = p;
}


void deleteElemArterNode(Node* This)
{
	if (This == nullptr || This->next == nullptr)
		return;
	Node* p = This->next;
	This->next = p->next;
	delete p;
	p = nullptr;
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
			if (arr[i] >= head->next->data)
			{
				addElemAfterNode(head->next, arr[i]);
				continue;
			}
		}
		if (arr[i] <= head->data)
		{
			addElemAfterNode(head, arr[i]);
			continue;
		}
		Node* cur = head;
		Node* curNext = cur->next;
		while (cur->next != nullptr && arr[i] > curNext->data)
		{
			cur = cur->next;
			curNext = cur->next;
		}
		addElemAfterNode(cur, arr[i]);

	}
}

void clean(Node*& head)
{
	while (head->next)
		deleteElemArterNode(head);
}

void printList(Node* head)
{
	Node* cur = head->next;
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
	createListSort(head, a, 7);
	/*printList(head);
	clean(head);
	printList(head);*/


	printRec(head);
}