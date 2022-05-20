#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

struct Student{
    string name;
    int fn;
    int points;

    friend bool operator<(const Student& a, const Student& b)
    {
        return a.points == b.points ? a.fn<b.fn : a.points<b.points;
    }
};

bool f(const Student& a, const Student& b) {
    return a.points == b.points ? a.fn<b.fn : a.points<b.points;
}

Student get_first(vector<Student>& s, const int points) {
    int l = 0;
    int h = s.size() - 1;
    int mid = 0;

    while (l <= h) {
        mid = l + (h-l)/2;

        if (s[mid].points == points) {
            return s[mid];
        }

        if (s[mid].points > points){
            h = mid-1;
        }else {
            l = mid + 1;
        }
    }

    return s[mid];
}

Student next(vector<Student>& arr, int target, int end)
{
    int start = 0;
 
    Student ans;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid].points == target)
            return arr[mid];
        // Move to right side if target is
        // greater.
        if (arr[mid].points <= target)
            start = mid + 1;
 
        // Move left side.
        else
        {
            ans = arr[mid];
            end = mid - 1;
        }
    }
 
    return ans;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,q;
    cin >> n >> q;
    vector<Student> students;
    queue<int> qu;

    string tmp_name;
    int tmp_fn;
    int tmp_points;

    for (size_t i = 0; i < n; i++)
    {
        cin >> tmp_name >> tmp_fn >> tmp_points;
        students.push_back({tmp_name, tmp_fn, tmp_points});
    }

    sort(students.begin(), students.end(),f);

    int tmp;
    for (size_t i = 0; i < q; i++)
    {
        cin >> tmp;
        qu.push(tmp);
    }
    
    while(!qu.empty()){
        Student k = next(students, qu.front(), students.size());
        if (qu.front() <= k.points)
            cout << k.name << " " << k.fn << endl;
        qu.pop();
    }

    return 0;
}

/*
5 3
ivan 31 30
petar 30 30
iskrn 29 30
petia 40 30
anton 35 30
14
16
13

5 5
ivan 31 15
petar 30 15
iskrn 29 13
petia 40 15
anton 35 18
14
16
13
1
500
*/