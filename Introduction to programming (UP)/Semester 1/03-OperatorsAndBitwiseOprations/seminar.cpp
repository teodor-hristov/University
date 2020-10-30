#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    //Task 1

    // int a, b;

    // cin >> a >> b;

    // cout << a & b << endl;
    // cout << a | b << endl;
    // cout << (a << b) << endl;
    // cout << (a >> b) << endl;

    //Task 2

    // int N;

    // cin >> N;

    // if(N & (1 << 2)) {
    //     cout << "1" << endl;
    // } else {
    //     cout << "0" << endl;
    // }

    //Task 3

    // int N, M;

    // cin >> N >> M;
    // cout << !!(N & (1 << M)) << endl;
    // //5 3
    // //101
    
    //Task 3a

    // int N, M;
    // cin >> N >> M;

    // cout << !!(N & (1 << (32 - M))) << endl;

    //Task 4

    // int N;
    // int mask;

    // cin >> N;

    // for(int i = 0; i < 32; i++) {
    //     mask = (1 << i)
    //     if(N <= mask) {
    //         cout << mask << endl;
    //         break;
    //     }
    // }

    //Task 5

    // int N, count = 0;

    // cin >> N;

    // for(int i = 0; i < 16; i++) {
    //     if(N & (1 << i)) {
    //         count++;
    //     }
    // }

    // cout << count << endl;

    //Task 6

    // int n;
    // bool status = 0;

    // cin >> n;

    // for(int i = 0; i < 32; i++) {

    //     if(status) {
    //         n = n ^ (1 << i);
    //     }

    //     if(n & (1 << i)) {
    //         status = 1;
    //     }
    // }

    // cout << n << endl;
    

    //Task 7 

    // int n;

    // cin >> n;
    // // 000..101 5
    // // 111..010
    // cout << n ^    

    //Task 8
    // int n;

    // cin >> n;

    // if(n & 1) 
    //     cout << "Studeno e!" << endl;

    // if(n & (1 << 1))
    //     cout << "Vali snqg!" << endl;

    // if(n & (1 << 2))
    //     cout << "Vali dyjd!" << endl;

    // if(n & (1 << 3))
    //     cout << "Vetrovito e!" << endl;

    // if(n & (1 << 4))
    //     cout << "Slynchevo e!" << endl;


}