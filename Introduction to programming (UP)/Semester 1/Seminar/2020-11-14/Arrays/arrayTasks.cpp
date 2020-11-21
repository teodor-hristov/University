#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void insertNumbers(unsigned n);
void printNumbers(const int array[], unsigned length);
int findMinimum(unsigned n);

int main() {

#pragma region task1

    // int n;
    // cin >> n;
    // insertNumbers(n);

#pragma endregion task1

#pragma region task2
    
    int n;
    cin >> n;
    cout << findMinimum(n) << endl;

#pragma endregion task2
}

int findMinimum(unsigned n) {
    int temp = 0;
    int min;
    
    cin >> min;
    
    for (unsigned i = 1; i < n; i++)
    {
        cin >> temp;
        if(min > temp) {
            min = temp;
        }
    }
    
    return min;
}

void insertNumbers(const unsigned n) {
    int array[n];

    for (unsigned i = 0; i < n; i++)
    {
        cin >> array[i];
    }  
    printNumbers(array, n);
}

void printNumbers(const int array[], unsigned length) {
    for (unsigned i = 0; i < length; i++)
    {
        cout << array[i] << endl;
    }
}