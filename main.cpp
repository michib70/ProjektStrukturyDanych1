#include <iostream>
#include <chrono>
#include <fstream>
#include "DynamicArray.hpp"
#include "LinkedList.hpp"

using namespace std;
using namespace chrono;

template <typename F>
long long test(F func, int rep) {
    long long totalTime = 0;
    for (int i = 0; i < rep; ++i) {
        auto start = high_resolution_clock::now(); //start pomiaru
        func(); //wykonanie funkcji
        auto stop = high_resolution_clock::now(); // koniec pomiaru
        totalTime += duration_cast<nanoseconds>(stop - start).count();
    }
    return totalTime / rep;
}

int main() {
    ofstream results("results.txt");

    int size = 1000000;
    int rep = 100;

    DynamicArray dynamic(size);
    LinkedList linked;

    for (int i = 0; i < size; ++i) {
        dynamic.pushBack(i);
        linked.pushFront(i);
    }

    cout << "Start testow" << endl;

    results << "Dynamiczna pushFront: " << test([&]() { dynamic.pushFront(400); }, rep) << " ns\n";
    results << "Wiazana pushFront: "    << test([&]() { linked.pushFront(400); }, rep) << " ns\n";

    results << "Dynamiczna pushBack: "  << test([&]() { dynamic.pushBack(400); }, rep) << " ns\n";
    results << "Wiazana pushBack: "     << test([&]() { linked.pushBack(400); }, rep) << " ns\n";

    results << "Dynamiczna insert: "    << test([&]() { dynamic.insert(size / 2, 400); }, rep) << " ns\n";
    results << "Wiazana insert: "       << test([&]() { linked.insert(size / 2, 400); }, rep) << " ns\n";

    results << "Dynamiczna popFront: "  << test([&]() { dynamic.popFront(); }, rep) << " ns\n";
    results << "Wiazana popFront: "     << test([&]() { linked.popFront(); }, rep) << " ns\n";

    results << "Dynamiczna popBack: "   << test([&]() { dynamic.popBack(); }, rep) << " ns\n";
    results << "Wiazana popBack: "      << test([&]() { linked.popBack(); }, rep) << " ns\n";

    results << "Dynamiczna deleteAtIndex: " << test([&]() { dynamic.deleteIndex(size / 2); }, rep) << " ns\n";
    results << "Wiazana deleteAtIndex: "    << test([&]() { linked.deleteIndex(size / 2); }, rep) << " ns\n";

    results << "Dynamiczna search (90): "   << test([&]() { dynamic.search(90, 0); }, rep) << " ns\n";
    results << "Wiazana search (90): "      << test([&]() { linked.search(90, 0); }, rep) << " ns\n";

    results.close();
    cout << "Testy zakonczone, wyniku w pliku results.txt" << endl;
    return 0;
}
