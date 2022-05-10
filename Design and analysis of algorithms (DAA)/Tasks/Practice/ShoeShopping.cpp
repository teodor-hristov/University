#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

bool pred(const int& lhs, const int& rhs){
    return lhs < rhs;
}

int next(int arr[], int target, int end)
{
      // Minimum size of the array should be 1
      if(end == 0) return -1;
    // If target lies beyond the max element, than the index of strictly smaller
      // value than target should be (end - 1)
      if (target >= arr[end - 1]) return end-1;
   
    int start = 0;
 
    int ans = -1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
 
        // Move to the left side if the target is smaller
        if (arr[mid] > target)
        {
            end = mid - 1;
        }
 
        // Move right side
        else
        {
            ans = mid;
            start = mid + 1;
        }
    }
    return ans;
}

int main(){
    int shoe_number;
    int q_count;
    int shoes[100050] = {0};
    int q[100050][2] = {0};

    cin >> shoe_number >> q_count;
    for(int i = 0; i < shoe_number; i++){
        cin >> shoes[i];
    }
    
    for(int i = 0; i < q_count; i++){
        cin >> q[i][0] >> q[i][1];
    }

    sort(shoes, &shoes[shoe_number], pred);
    // for(int i = 0; i < shoe_number; i++)
    //     cout << shoes[i] << " ";
    
    // cout << endl;
    int ind = 0;
    int bought = 0;
    for (size_t i = 0; i < q_count; i++)
    {
        bought = 0;
        ind = next(shoes, q[i][1] , shoe_number); 
        //printf("ind: %d\n", ind);
        for (size_t j = 0; ind >= 0 && j < shoe_number; j++)
        {
            if (q[i][0] >= shoes[ind])
            {
                //cout <<q[i][0] <<" "<< q[i][1] << " " << shoes[ind] << endl;
                q[i][0]-=shoes[ind];
                //printf("+1\n");
                bought++;
            }
            else {
                if (bought || q[i][1] >= shoes[ind])
                    break;
            }
            ind--;
        }

        cout << bought << endl;
       // ind = 0;
    }
}

/*
7 5
70 10 130 50 40 20 40
150 100
140 50
190 130
60 80
300 60


130 70 50 40 40 20 10
*/