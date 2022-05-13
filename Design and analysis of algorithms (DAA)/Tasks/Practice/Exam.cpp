#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;
size_t n, f;

size_t makeSum(size_t number) {
    return (number+1)*f + number*(number + 1)/2;
}   

int bs() {
    size_t l = 1;
    size_t r = n/f;
    size_t mid;
    size_t result = 0;

    size_t sum;
    while (l <= r) {
        mid = l + (r-l)/2;
        sum = makeSum(mid);
        printf("l: %ld r: %ld sum: %ld mid: %ld\n", l,r,sum,mid);
       
        if (sum >= n) {
            result = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return result + 1;
}

int main() {
    cin >> n >> f;
    cout << bs() << endl;
}

/*
900000 44444
240000 80260
235711131719232931 12345


80260 + 80261 + 80262 = 240783 


3 4 5 6 7 8 9
2+1 2+2 2+3 2+4 2+5 2+6



l---------------x-----r
l----------mid-----x-----r
------------l---x--mid---r
------------l--mid-x-r----
235711131719232931
8475948939142

1986009638
1985997293
 686589625

*/