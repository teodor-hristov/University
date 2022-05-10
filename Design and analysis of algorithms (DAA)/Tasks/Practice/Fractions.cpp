#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <tuple>
#include <algorithm>
#include <unordered_map>

using namespace std;

pair<int,int> kurec[100000000];

int gcd(int a, int b){
    int t;
    while (b != 0){
        t = b;
        b = a % b;
        a = t;
    }
       
    return a;
}

bool pred(pair<int,int> a, pair<int,int> b){
    return (double)a.first/(double)a.second <= (double)b.first/(double)b.second;
}

int main() {
    int n;
    int index = 0;
    cin >> n;

    cout << 0 << " ";
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (i < j && gcd(i,j) == 1)
                kurec[index].first = i;
                kurec[index].second = j;
                index++;
                //cout << i << "/" << j << " ";
        }
    }

    sort(kurec, kurec+index,pred);

    for (int i = 0; i < index; i++){
        if (kurec[i].first != 0 && kurec[i].second != 0)
        cout << kurec[i].first << "/" << kurec[i].second << " ";
    }

}