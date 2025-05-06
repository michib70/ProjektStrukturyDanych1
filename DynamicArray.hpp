#ifndef tablica_dynamiczna
#define tablica_dynamiczna
#include <iostream>

class DynamicArray { //tablica dynamiczna
private:
	int* data; //wskaźnik do tablicy
    int size; //aktualny rommiar tablicy
	int maxSize; //max rozmiar tablicy
    void resize(); //zmiana rozmiaru
public:
    DynamicArray(int n); //konstruktor
    ~DynamicArray(); //dekonstruktor
    void search(int value, bool print); //szukanie wartości
    void showElement(int i);
    void pushFront(int value);
    void pushBack(int value);
    void insert(int index, int data); //dodawanie na wskazany indeks
    void deleteIndex(int index);
    void popFront(); //usuwanie pierwszego el
    void popBack(); //usuwanie ostatniego el
    void print(); //wypis tablicy
};
#endif
