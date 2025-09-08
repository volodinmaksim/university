#pragma once 
#include <iostream> 
using namespace std;


struct Node
{
	int data;
	Node* next;
};

Node* initList();
void initList(Node*);
void initList(Node*& head, int elem);
void addElemFromHead(Node*& head, int data);
void addElemFromEnd(Node* &head, int data);
void addElem(Node* head, int data, int value);

void removeList(Node*& head);
void deleteElemFromHead(Node*& head);
void deleteElemFromEnd(Node*& head);
void deleteAllValue(Node*& head, int value);
void deleteAfterElem(Node* head, int value);

void deleteNotFirstEntry(Node* head);

bool search(Node* head, int value);
void printList(Node* head);
bool isEmpty(Node* head);

