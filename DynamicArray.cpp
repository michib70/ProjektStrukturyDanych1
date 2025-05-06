#include "DynamicArray.hpp"
#include <iostream>

DynamicArray::DynamicArray(int s) //konstruktor
{
    data = new int[s];
    size = 0;
    maxSize = s;
}
DynamicArray::~DynamicArray() //destruktor
{
    delete[] data;  //usuwanie elementow
}
void DynamicArray::resize() { //podwojenie rozmiaru
	int addedmaxSize = maxSize * 2;
	int* addedData = new int[addedmaxSize]; 
    std::copy(data, data + size, addedData); // Kopiowanie starych elementów
	delete[] data; // usuwanie elementow
	data = addedData; // Przypis pamieci
	maxSize = addedmaxSize; // Zmiana wielkosci
}
void DynamicArray::pushFront(int val)
{
    if (size == maxSize)  //jesli tablica pelna, podwajamy jej rozmiar
    {
        resize();
    }
    for (int i = size; i > 0; i--) //przemieszczanie tablicy o 1
    {
        data[i] = data[i - 1];
    }
    data[0] = val;  //pierwszy element = nowy element
    size++; 
}
void DynamicArray::pushBack(int val) //dodawanie na koniec
{
    if (size == maxSize)
    {
        resize();
    }
    data[size] = val;  //dodanie nowej wartości na ostatni indeks
    size++;
}
void DynamicArray::insert(int i, int val)
{
    if (i < 0 || i > size)  //jesli index nie miesci sie w tablicy
    {
        std::cout << "Indeks poza zakresem 0 a " << size << std::endl;
        return;
    }
    if (size == maxSize) //jesli tablica za mala - powiekszamy
    {
        resize();
    }
    for (int j = size; j > i; j--) //
    {
        data[j] = data[j - 1]; //przesuwamy elementy zeby zrobic miejsce na dodany
    }
    size++;
    data[i] = val;
}
void DynamicArray::deleteIndex(int i) //usuwanie ze wskazanego miejsca
{
    if (i < 0 || i >= size) //sprawdzamy czy rozmiar miesci sie w zakresie
    {
        std::cout << "Indeks poza zakresem 0 a " << size << std::endl;
        return;
    }
    for (int j = i; j < size - 1; j++)      //przemieszczanie wszystkich wiekszych elementów o jeden w lewo
    {
        data[j] = data[j + 1];
    }
    size--;
}
void DynamicArray::popFront()
{
    if (size == 0)      //jesli tablica pusta
    {
        std::cout << "Brak elementow do usuniecia" << std::endl;
        return;
    }
    for (int i = 0; i < size - 1; i++)
    {
        data[i] = data[i + 1];      //przesuwamy wszystkie elementy
    }
    size--;
}
void DynamicArray::popBack()
{
    if (size == 0)
    {
        std::cout << "Blad: Pusta Tablica" << std::endl;
        return;
    }
    size--;
}
void DynamicArray::print()  //wydruk tablicy
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "D[" << i << "] = " << data[i] << " ";
    }
    std::cout << "\n";
}
void DynamicArray::search(int val, bool print) //szukanie danej wartości
{
    for (int i = 0; i < size; i++)
    {
        if (data[i] == val && print == 0) {
            return;
        }
        else if (data[i] == val && print == 1)
        {
            std::cout << "Znaleziono " << val << " na indexie " << i << std::endl;
            return;
        }

    }
    if (print == 1)
    std::cout << "Nie znaleziono elementu " << val << std::endl;
}
void DynamicArray::showElement(int i) //Wypis elementu z danego indexu
{
    if (i < 0 || i >= size)
    {
        std::cout << "Indeks poza zakresem 0 a " << size << std::endl;
        return;
    }
    std::cout << "Element na indeksie " << i << " : " << data[i] << std::endl;
}
