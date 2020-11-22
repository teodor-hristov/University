#include <iostream>

using namespace std;

int main() {
    int matrix[6][4] = {{0, 1, 2, 3},
                        {4, 5, 6, 7},
                        {0, 4, 7, 3},
                        {7, 6, 2, 3},
                        {5, 1, 2, 6},
                        {0, 1, 5, 4}};
    int uL[2] = {0,0};
    int uR[2] = {0,3};
    int dL[2] = {5,0};
    int dR[2] = {5,3};
    for(int count = 0; count < 2; count++) {

        for(int y = uL[1]; y <= uR[1]; y++) {
            for(int x = uL[0]; x <= uR[0]; x++) {
                cout << matrix[x][y] << " ";
            }
        }

        uL[0]++;
        uL[1]++;
        uR[0]++;
        uR[1]--;

        for(int y = uR[0]; y <= dR[0]; y++) {
            for(int x = dR[1]; x <= dR[1]; x++) {
                cout << matrix[y][x] << " ";
            }
        }

        dR[1]--;

        for(int y = dR[0]; y <= dR[0]; y++) {
            for(int x = dR[1]; x >= dL[1]; x--) {
                cout << matrix[y][x] << " ";
            }
        }

        dR[0]--;
        dL[0]--;

        for(int y = dL[0]; y >= uL[0]; y--) {
            for(int x = dL[1]; x <= dL[1]; x++) {
                cout << matrix[y][x] << " ";
            }
        }

        dL[1]++;

    }

    cout << endl;

}