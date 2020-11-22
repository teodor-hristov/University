#include <iostream>
#include <math.h>

using namespace std;

int main() {
    const unsigned n = 1231241;
    bool eratostenArray[n] = {0,};

    for(int i = 2; i < sqrt(n); i++) {
        if(!eratostenArray[i]) {
            for(int j = i*i; j < n; j += i) {

                if(!eratostenArray[j]) {
                    eratostenArray[j] = true;
                }

            }
        }
    }

    for(int i = 2; i < n ; i++) {
        if(eratostenArray[i] == false) {
            cout << i << " ";
        }
    }
    cout << endl;
}