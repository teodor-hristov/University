#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int arr[1000000];
int longestSubarray(int a[], int n)
{
    int count = 0;
    int maxlen = 0;
    unordered_map<int, int> hash;

    int starti = 0;
    for (int i = 0; i < n; i++) {
        // if (hash.count(a[i]) <= starti){
        //     count++;
                starti = max(hash[a[i]], starti);
        //     hash.insert({a[i], a[i]});
                maxlen = max(maxlen, i - starti + 1);
                hash[a[i]] = i + 1;
        // }
        // else{
        //     count=1;
        //     //hash.clear();
        //     starti++;
        //     i = starti;
        // }
        // cout << "count: " << count;
        // cout << " times: " << hash.count(a[i]);
        // cout << " i: " << i << endl;

        maxlen = max(maxlen, count);
    }
 
    return maxlen;
}

int main() {
     int arrsize;
    cin >> arrsize;
    for (int i = 0; i < arrsize; i++){
        cin >> arr[i];
    }
    cout << longestSubarray(arr, arrsize) << endl;
    return 0;
}
/*
5
1 3 2 1 5

5
1 3 1 1 1

7
1 2 40 10 1 59 50 1
*/