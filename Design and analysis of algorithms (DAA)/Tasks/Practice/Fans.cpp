#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int arr[10050];
int teams[10050];

bool OK(int mid, int n, int k){
    //hotel[0] - hotel[1] < mid 
    int count = 0;
    for(int i=0; i<n-1; ++i){
        for(int j=i+1; j<n; ++j){
            if(arr[j] - arr[i] >= mid){
                count++;
                i = j-1;
                break;
            }
        }
        if(count >= k-1){
            return true;
        }
    }
    return false;
}

int binarySearch(int *arr, int l, int r, int target){
    if (r < l){
        if (r < 0)
            return -1;
    }

    int mid = l + (r-l)/2;
    if (arr[mid] == target){
        return mid;
    }
    else if(arr[mid] > target){
        return binarySearch(arr, l, mid-1, target);
    }
    else{
        return binarySearch(arr, mid+1, r, target);
    }
}

int main() {
     int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr, &arr[n]);
   
//    while(k!=0){
//        //binarySearch(arr, arr[0], arr[n-1], arr[(n-1)/2]);
//    }

for (size_t i = 0; i < n; i++)
    {
        cout << teams[i] << " ";
    }
    cout << "OK: " << OK(35, 7, 2) << endl;

    return 0;
}

/*
5 2
5 8 12 32 1

1 5 8 12 32 -> 31

7 3
1 15 35 10 69 60 28

1 10 15 28 35 60 69

7 5
1 15 35 10 69 60 28

1| 10 15 |16| 35 60 |69
*/