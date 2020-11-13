#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void printNumbers(int);

int main() {
#pragma region task1
    int n;
    cin >> n;
    printNumbers(n);
#pragma ednregion task1
}

void printNumbers(const int n) {
    int array[n];

    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << array[i] << endl;
    }
    
    
}