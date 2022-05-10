#include <iostream>
#include <algorithm>

using namespace std;

int main(void){

size_t n;
cin >> n;
int *arr = new int[n];

for (size_t i = 0; i < n; i++)
{
    cin >> arr[i];
}

int count = n;
int temp = 0;
for (size_t i = 0; i < n; i++)
{
    if (arr[i] == arr[i+1]){
        count++;
        if (temp > 0){
            count++;
        }
        temp++;
    }else{
        temp = 0;
    }
}

cout << count << endl;
delete[] arr;
}

// 3 2 4 4
//1 -7 5 5 5 2
//000000