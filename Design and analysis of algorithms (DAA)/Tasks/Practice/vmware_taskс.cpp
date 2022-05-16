#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#include <numeric>
#include <unordered_map>

using namespace std;

int binarySearch(vector<int> arr, int l, int r, int target){
    if (r < l){
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


string findNumber(vector<int> arr, int k) {
    int n;
    int tmp;

    sort(arr.begin(), arr.end());

    if (binarySearch(arr,0,arr.size(),k) < 0){
        return "NO";
    } else {
        return "YES";
    }
}

vector<int> oddNumbers(int l, int r) {
    vector<int> res;
    for (int i = l; i <= r; i++){
        if (i & 1){
            res.push_back(i);
        }
    }

    return res;
}

int main() {
   oddNumbers(3,5);
}