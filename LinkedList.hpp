#ifndef lista_wiazana
#define lista_wiazana
#include <iostream>
struct Node {
public:
    int data;
    Node* next; //wskaznik do nast elementu
    Node(int data);
    Node() //pusty konstruktor
    {
        data = 0;
        next = nullptr;
    }
};


class LinkedList
{
private:
    Node* head;
    Node* tail;
	int size; //liczba elementów w liście
public:
   LinkedList();
    ~LinkedList(); //destruktor
    void search(int value, bool print); //szukanie wartości
    void pushFront(int value);
    void pushBack(int value);
    void insert(int index, int data); //dodawanie na wskazany indeks
    void deleteIndex(int index);
    void popFront(); //usuwanie pierwszego el
    void popBack(); //usuwanie ostatniego el
    void print(); //wypis tablicy
    bool isEmpty();
};
#endif
