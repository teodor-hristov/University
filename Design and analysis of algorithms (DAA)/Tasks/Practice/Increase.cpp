#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

void init(size_t& n, size_t& m, vector<int>& nums){
    int tmp = 0;
    
    scanf("%ld %ld", &n, &m);
    
    for (size_t i = 0; i < n; i++)
    {
        cin >> tmp;
        nums.push_back(tmp);
    }
    
}

int slices(vector<int>& nums, const int k){
    int n = nums.size();
    int max_num = nums[0];
    int tmp = 0;
    vector<int> tmp_nums;

    for (size_t i = 0; i < n; i++)
    {
        tmp_nums.push_back(nums[i] + (i+1)*k);
        tmp += tmp_nums.back(); 
        if (tmp < 0){
            tmp_nums.clear();
            tmp = 0;
        }

        max_num = max(tmp, max_num);
    }
    

    return max_num;
}

bool possibleSum(vector<int>& nums, const int k, const int m) {
    vector<int> tmp = nums;
    return slices(tmp, k) >= m;
}

int binarySearchIterative(size_t& m, vector<int>& nums) {
    int min_result = 1000000; //max value
    long l = -1 * m;
    long r = m;
    int mid;

    while (l <= r) {
        mid = l + (r-l)/2;

        if (possibleSum(nums, mid, m)) {
            min_result = min(min_result, mid);
            r = mid - 1;
        } else {
            l = mid + 1;
        }

        //printf("l: %d r: %d mid: %d min_result: %d\n", l,r,mid, min_result);

    }

    return min_result;
}

int main() {
    size_t n,m;
    vector<int> nums;

    init(n, m, nums);
    cout << binarySearchIterative(m, nums) << endl;;
}

/*
5 21
-5 4 -13 -3 -7

10 42
5 17 -4 13 0 0 21 17 11 19
*/