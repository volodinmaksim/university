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

//������ � Node
bool isEmpty(Node* head);
void printList(Node* head);
void addElemFromEnd(Node* &head, sickLeave Data);
void addElemFromHead(Node*& head, sickLeave Data);
void deleteNode(Node*& node);

void removeList(Node*& head);
void deleteElemFromHead(Node*& head);
void deleteElemFromEnd(Node*& head);
bool search(Node* head, sickLeave data);



//�� ������� 
void frequentDiagnosis(Node* head);
void deleteByDate(Node*& head, dateOpen date);
void companyBigDiseases(Node* head);
void DayBigDesease(Node* head);


//����������
void swapElem(sickLeave& a, sickLeave& b);
void sortedByDateByDecreasing(Node* head);
void sortedByDiagnosis(Node* head);
void sortedByDaysOfIllnessByDecreasing(Node* head);

//������� �� �����
sickLeave readtxt(ifstream &filein);