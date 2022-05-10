#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

size_t arr[100050];
size_t n,k;

void init(){
    scanf("%ld %ld", &n, &k);

    for (size_t i = 0; i < n; i++) {
        scanf("%ld", &arr[i]);
    }
}

bool OK(int a){
    if (a == 0)
        return false;

    int all_cut = 0;
    for (size_t i = 0; i < n; i++) {
        all_cut+= arr[i] / a;
    }

    if (all_cut >= k)
        return true;

    return false;
}

int binarySearchIterative(){
    int l= 0;
    int r = int(1e8)+5;
    int lastSucc = 0;
    int mid;

    while (l <= r) {
        mid = (l+r)/2;//2,3

        if (OK(mid)) {
            lastSucc = mid;
            l = mid + 1;//0,0,4,3,4
        } else {
            r = mid - 1;//42,20,9,
        }
    }

    return lastSucc;
}

int main(){
    init();
    printf("%d\n", binarySearchIterative());
}
/*
3 4
5 3 5

11 42
33 17 42 13 7 5 23 20 1 18 6
*/