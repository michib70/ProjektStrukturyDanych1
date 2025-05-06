#include <iostream>
#include "LinkedList.hpp"


Node::Node(int val) // konstruktor węzła
{
	data = val; // ustawienie wartości elementu
	next = nullptr; // ustawienie wskaźnika do następnego elementu na nullptr
}
LinkedList::LinkedList() // konstruktor listy
{
    head = nullptr;  //pusta lista - inicjalizacje na nullptr
    tail = nullptr;     
    size = 0;          //pusta lista
}
LinkedList::~LinkedList()  // destruktor listy
{
    Node* element = head;   //wskaźnik do aktualnego elementu
    Node* nextNode;     //wskaźnik do następnego elementu
    while (element != nullptr) 
    {
		nextNode = element->next; // zapamiętanie następnego elementu
		delete element;  // usunięcie aktualnego elementu
		element = nextNode;  // przejście do następnego elementu
    }
	head = nullptr;     // ustawienie wskaźnika do pierwszego elementu na nullptr   
	tail = nullptr;     // ustawienie wskaźnika do ostatniego elementu na nullptr
}
bool LinkedList::isEmpty()
{
	return head == nullptr; // jeśli head wskazuje na pusty Nodde
}

void LinkedList::pushFront(int val) // dodawanie na początek
{
    if (isEmpty())
    {
		head = new Node(val); //jeśli lista jest pusta, dodajemy nowy element jako pierwszy
        tail = head;
    }
    else
    {
		Node* addedNode = new Node(val); //wskaźnik do nowego node
		addedNode->next = head; // ustawiamy wskaźnik na pierwszy element
		head = addedNode; // przesuwamy wskaźnik head na nowy dodany element
    }  
	size++; // zwiększamy licznik elementów
}
void LinkedList::pushBack(int val) // dodawanie na koniec
{
    if(isEmpty())
    {
        head = new Node(val);     // jeśli pusta, dodajemy jako pierszy element
        tail = head; 
    }
    else
    {
		Node* addedNode = new Node(val); //tworzymy nowy element
        tail->next = addedNode;
        tail = addedNode;
    }
    size++;
}
void LinkedList::insert(int i, int val) //dodanie na okreslone miejsce
{
		if (i == 0) // jeśli dodajemy na początek
        {
            pushFront(val);     //uzywamy zaimplementowanej funkcji
            return;
        }
        if (i < 0 || i > size) // sprawdzenie czy indeks jest w rozmiarze listy
        {
            std::cout << "Blad: Indeks poza zakresem 0 a " << size<< std::endl;
            return;
        }
		if (i == size) // jeśli dodajemy na koniec
            {
                pushBack(val);     //dodajemy na koniec
                return;
            }
        Node* addedNode = new Node(val);
        Node* element = head; 
		for (int j = 0; j < i - 1; j++) // przechodzimy do elementu przed indeksem
        {
            element = element->next;
        }
		addedNode->next = element->next; // ustawiamy wskaźnik nowego node na nastepny node
		element->next = addedNode; // ustawiamy wskaźnik elementu na dodany node
        size++; 
}
void LinkedList::deleteIndex(int i) // usuwanie z wskazanego indeksu
{
	if (i < 0 || i >= size) // sprawdzenie czy indeks nie wykracza poza zakres listy
    {
        std::cout << "Blad: Indeks poza zakresem 0 a " << size << std::endl;
        return;
    }

	if (i == size - 1) //usuwamy ostatni element
    {
        popBack();
        return;
    }
    if(i == 0) //usuwamy pierwszy element
    {
        popFront();
        return;
    }

    Node* element = head;
	for (int j = 0; j < i - 1; j++) // przechodzimy do elementu przed indeksem
    {
        element = element->next;
    }
    Node* Temp = element->next;
    element->next = Temp->next;
    delete Temp;
}
void LinkedList::popFront()
{
	if (isEmpty()) // jesli lista pusta
    {
        std::cout << "Blad: usuniecie z pustej listy" << std::endl;
        return;
    }
    Node* element = head; // wskaźnik do elementu do usunięcia
    head = head->next; // przesunięcie wskaźnika do pierwszego elementu na następny
    delete element; 
    size--;
    if (head == nullptr)    //jeśli pusta, tail ustawiamy na nullptr
    { 
        tail = nullptr;
    }
}
void LinkedList::popBack() // usuwanie końca
{
    if (isEmpty()) 
    {
        std::cout << "Lista jest pusta." << std::endl;
        return;
    }
    if (head == tail) // jeśli jest tylko jeden element w liście
     { 
        delete head;
        head = nullptr; //podmieniamy head i tail tak aby na nic nie wskazywaly
        tail = nullptr;
    } 
    else 
    {
        Node* element = head;
        while (element->next != tail) // przesuwamy do ostatniego elementu
         { 
            element = element->next;
        }
        delete tail; //usuwamy stary tail
        tail = element; // ustawiamy nowy
        tail->next = nullptr; // zmieniamy wskaznik taila na nullptr
    }
    size--;
}
void LinkedList::print() // pokazywanie listy
{
    if (isEmpty()) 
    {
        std::cout << "Lista jest pusta." << std::endl;
        return;
    }
    Node* element = head; 
    int i = 0;
	while (element != nullptr)  // dopóki nie osiągniemy końca listy
    { 
        std::cout << "L[" << i << "] = " << element->data << " ";
        element = element->next;
        i++;
    }
    std::cout << "\n";
}
void LinkedList::search(int val, bool print) //szukamy wartosci, funkcja działa tylko na pierwszy indeks ze znalezioną wartoscia
{
    if (isEmpty()) 
    {
        std::cout << "Lista jest pusta." << std::endl;
        return;
    }
    Node* element = head;
    int i = 0;
    while (element != nullptr) // dopóki nie osiągniemy końca listy
     { 
        if (element->data == val && print == 1)    //sprawdzamy czy aktualny element to szukana wartość
        {
            std::cout << "Znaleziono element " << val << " na indexie " << i << std::endl;
            return;
        }
        else if(element->data == val) {
            return;
        }
        element = element->next; //przesuwamy sie dalej po liscie
        i++;
    }
    if(print == 1)
    std::cout << "Nie znaleziono elementu " << val << std::endl;
}
