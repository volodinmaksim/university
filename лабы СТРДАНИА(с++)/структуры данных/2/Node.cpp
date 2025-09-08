#include <iostream>
#include "Node.h"
#include <fstream>
#include <string>
#include <sstream>
using namespace std;



Node::Node()
{
    this->next = nullptr;
    this->prev = nullptr;
    this->data;
}

Node::Node(sickLeave Data) : next(nullptr), prev(nullptr), data(Data)
{
}


bool isEmpty(Node* head) 
{
    return head == nullptr;
}


void printList(Node* head)
{
    if (isEmpty(head))
    {
        cout << "Список пуст." << endl;
        return;
    }
     
    Node* temp = head;
    while (temp != nullptr)
    {
        temp->data.printStruct();
        temp = temp->next;
    }
    cout << endl;
}


void addElemFromEnd(Node* &head, sickLeave Data)
{
    
    if (head == nullptr)
    {
        head = new Node;
        head->next = nullptr;
        head->prev = nullptr;
        head->data = Data;
    }
    else
    {
        Node* point = head;
        while (point->next != nullptr)
            point = point->next;
        Node* temp = new Node;
        point->next = temp;
        temp->next = nullptr;
        temp->prev = point;
        temp->data = Data;
    }
}

void addElemFromHead(Node*& head, sickLeave data)
{
    if (head == nullptr)
    {
        head = new Node;
        head->next = nullptr;
        head->prev = nullptr;
        head->data = data;
    }
    else
    {
        Node* newElem = new Node;
        newElem->data = data;
        head->prev = newElem;
        newElem->next = head;
        head = newElem;
    }
}

void deleteNode(Node*& node)
{
    if (!isEmpty(node))
    {
        Node* temp = node;
        if (temp->prev == nullptr and temp->next == nullptr)
        {
            delete node;
            node = nullptr;
        }
        else if (temp->prev == nullptr)
        {
            node = node->next;
            node->prev = nullptr;
            delete temp;
            temp = nullptr;
        }
        else if (temp->next == nullptr)
        {
            temp->prev->next = nullptr;
            delete temp;
            temp = nullptr;
        }
        else
        {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            delete temp;
            temp = nullptr;
        }
    }
    
}

void removeList(Node*& head)
{
    while (!isEmpty(head))
        deleteElemFromHead(head);   
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

void deleteElemFromEnd(Node*& head)
{
    if (!isEmpty(head))
    {
        if (head->next == nullptr && head->prev == nullptr)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node* temp = head;
            while (temp->next != nullptr) 
            {
                temp = temp->next;
            }
            Node* p = temp;
            temp->prev->next = nullptr;
            delete p;
            p = nullptr;
        }
    }
}

bool search(Node* head, sickLeave data)
{
    if (!isEmpty(head))
    {
        Node* temp = head;
        while (temp->next != nullptr)
        {
            if (temp->data == data)
                return true;
            temp = temp->next;
        }
        if (temp->data == data)
            return true;

        return false;
    }
    else
        return false;
}


void frequentDiagnosis(Node* head)
{
    sortedByDiagnosis(head);
    string temp_diagnosis = head->data.diagnosis;
    int max_count = 0, Count = 0;
    Node* temp = head;
    Node* NASH = head;
    while (temp != nullptr)
    {
        if (temp->data.diagnosis == temp_diagnosis)
            Count++;
        else
        {
            Count = 1;
            temp_diagnosis = temp->data.diagnosis;
        }
        if (max_count < Count)
        {
            max_count = Count;
            NASH = temp;
        }
        temp = temp->next;
    }
    if (NASH == nullptr)
        cout << "Ошибка" << endl;
    else
        cout << "Самый часто встречаемый диагноз: " << NASH->data.diagnosis << endl;
}

void deleteByDate(Node* &head, dateOpen date)
{
    sortedByDateByDecreasing(head);
    while (head->data.date_open > date)
        deleteNode(head);
}

void companyBigDiseases(Node* head)
{
    if (!isEmpty(head))
    {
        sortedByDaysOfIllnessByDecreasing(head);
        Node* temp = head;
        int maxAil = temp->data.day_of_ail;
        while (temp->data.day_of_ail == maxAil)
        {
            cout << "Место работы: " << temp->data.place_of_work << endl;
            cout << "ФИО: " << temp->data.fio << endl << endl;
            temp = temp->next;
        }
    }
}

void DayBigDesease(Node* head) 
{
    sortedByDaysOfIllnessByDecreasing(head);
    if (!isEmpty(head))
    {
        dateOpen temp_date = head->data.date_open;
        int max_count = 0, Count = 0;
        Node* temp = head;
        Node* NASH = head;
        while (temp != nullptr)
        {
            if (temp->data.date_open == temp_date)
                Count++;
            else
            {
                Count = 0;
                temp_date = temp->data.date_open;
            }
            if (max_count < Count)
            {
                max_count = Count;
                NASH = temp;
            }
            temp = temp->next;
        }
        if (NASH == nullptr)
        {
            cout << "Ошибка" << endl;
        }
        else
        {
            cout << "День, в который было открыто наибольшее количество больничных листов: " <<
                NASH->data.date_open.day << "/" <<
                NASH->data.date_open.month << "/" <<
                NASH->data.date_open.year << endl;
        }
    }
}

void swapElem(sickLeave& a, sickLeave& b) {
    sickLeave temp = a; 
    a = b;              
    b = temp;           
}


void sortedByDateByDecreasing(Node* head)
{
    if (isEmpty(head)) 
        return; 

    bool flag;
    Node* temp;
    Node* lastSort = nullptr;

    do {
        flag = false;
        temp = head;

        while (temp->next != lastSort) 
        {
            if (temp->data.date_open < temp->next->data.date_open) 
            { 
                swapElem(temp->data, temp->next->data);
                flag = true;
            }
            temp = temp->next;
        }
        lastSort = temp;
    } while (flag);
}

void sortedByDiagnosis(Node* head)
{
    if (isEmpty(head))
        return;

    bool flag;
    Node* temp;
    Node* lastSort = nullptr;

    do {
        flag = false;
        temp = head;

        while (temp->next != lastSort)
        {
            if (temp->data.diagnosis.compare(temp->next->data.diagnosis) > 0) 
            {
                swapElem(temp->data, temp->next->data);
                flag = true;
            }
            temp = temp->next;
        }
        lastSort = temp;
    } while (flag);
}

void sortedByDaysOfIllnessByDecreasing(Node* head)
{
    if (isEmpty(head))
        return;

    bool flag;
    Node* temp;
    Node* lastSort = nullptr;

    do {
        flag = false;
        temp = head;

        while (temp->next != lastSort)
        {
            if (temp->data.day_of_ail < temp->next->data.day_of_ail)
            {
                swapElem(temp->data, temp->next->data);
                flag = true;
            }
            temp = temp->next;
        }
        lastSort = temp;
    } while (flag);
}

sickLeave readtxt(ifstream &filein)
{
    sickLeave temp;
    string line;
    getline(filein, line);
    stringstream ss(line);
    string f, i, o;
    ss >> f >> i >> o >> temp.place_of_work >> temp.diagnosis >> temp.date_open.day >>
        temp.date_open.month >> temp.date_open.year >> temp.day_of_ail;
    temp.fio = f + " " + i + " " + o;
    return temp;
}


