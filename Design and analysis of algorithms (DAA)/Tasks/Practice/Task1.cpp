#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int points[1000050];
int points_dummy[1000050] = {0};
int queries[100050][2];

int sum(int *arr,int findex,int sindex){
    int sum = 0;
    for (int i = findex; i <= sindex; i++)
    {
        if (arr[i] > 0)
            sum += points_dummy[i];
    }
    
    return sum;
}

int main() {
    int pointsCount, queriesCount;
    cin >> pointsCount >> queriesCount;
    for (int i = 0; i < pointsCount; i++){
        cin >> points[i];
    }

    for (int i = 0; i < pointsCount; i++){
        points_dummy[points[i]] = points_dummy[points[i]] + 1;
    }   

    for (int i = 0; i < queriesCount; i++){
        cin >> queries[i][0] >> queries[i][1];
    }
    //cout << binarySearch(points, 0, pointsCount, 11) << endl;
    //queriesCount*logn
    for (int i = 0; i < queriesCount; i++)
    {
        printf("%d\n",sum(points_dummy, queries[i][0], queries[i][1]));
    }
}
//3 5 1 7 13 11 9
//1 3 5 7 9 11 13 200
/*
7 3
3 5 1 7 13 11 9
3 7
1 12
0 15
*/
//3 5 1 7 13 11 9 2 0 18 19 58
//0 1 2 3 5 7 9 11 13 18 19 58
/*
12 5
3 5 1 7 13 11 9 2 0 18 19 58
3 7
1 12
0 15
1 90
0 1090

10 3
15 12 4 6 13 3 7 12 10 2
8 12
11 14
8 14
*/