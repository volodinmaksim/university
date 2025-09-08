#pragma once
#include "dateOpen.h"
#include "sickLeave.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;


struct Node
{	
	Node* next;
	Node* prev;
	sickLeave data;

	Node();
	Node(sickLeave data);
};

//работа с Node
bool isEmpty(Node* head);
void printList(Node* head);
void addElemFromEnd(Node* &head, sickLeave Data);
void addElemFromHead(Node*& head, sickLeave Data);
void deleteNode(Node*& node);

void removeList(Node*& head);
void deleteElemFromHead(Node*& head);
void deleteElemFromEnd(Node*& head);
bool search(Node* head, sickLeave data);



//по заданию 
void frequentDiagnosis(Node* head);
void deleteByDate(Node*& head, dateOpen date);
void companyBigDiseases(Node* head);
void DayBigDesease(Node* head);


//сортировки
void swapElem(sickLeave& a, sickLeave& b);
void sortedByDateByDecreasing(Node* head);
void sortedByDiagnosis(Node* head);
void sortedByDaysOfIllnessByDecreasing(Node* head);

//считать из файла
sickLeave readtxt(ifstream &filein);