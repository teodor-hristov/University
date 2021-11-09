#include <iostream>
#include <cstring>
#include "DynamicArray.h"

using namespace std;

template <typename T>
void printArray(const DynamicArray<T> * const arr){
    for (int i = 0; i < arr->getSize(); ++i) {
        cout << arr->getAt(i) << " ";
    }
    cout << endl;
};

int main()
{
    DynamicArray<int> pesho(15);
    DynamicArray<int> pe(pesho);

    for (int i = 0; i < 15; ++i) {
        pesho.Add(i,i);
    }

    pesho.Add(55, 14);
    pesho.Add(55, 29);

    printArray(&pesho);

    for (int i = 0; i < 30; ++i) {
        pesho.Remove(0);
    }

    printArray(&pesho);
}