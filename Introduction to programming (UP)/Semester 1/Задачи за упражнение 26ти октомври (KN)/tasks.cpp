#include <iostream>

int main () {
    
    //Task 1
    /*
    int a1, b1, c1, a2, b2, c2;
    double crossX, crossY;

    std::cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    if(a1 == a2 && b1 == b2) {
        std::cout << "Perpendicular" << std::endl;
    } else {
        // formulas for crossX and crossY are found
        // from system of linear equations
        // a1x + b1y = -c2 && a2x + b2y = -c2
        crossX = (-(a1*b2 + c2*b1)*b1) / (b1*(b1*a2 - a1*b2));
        crossY = -(a1*crossX + c1)/b1;

        std::cout << "Cross: (x,y) = (" << crossX << "," << crossY << ")" 
        << std::endl;
    } */

    //Task 2
    /*
    int num, divider;
    bool status;

    std::cin >> num >> divider;

    if(num & 1) { 
        status = 0;
    } else {
        while(divider != 0) {
            divider = divider >> 1;
            num = num >> 1;

            if(!(num & 1))
                status = 1;
        }   
    }

    std::cout << status; */

    //Task 3
/*
    int num, newNum = 0;

    std::cin >> num;

    for(int i = 0; i < 15; i++) {
        if(num & 1) {
            newNum = (newNum + 1) << 1;
        } else {
            newNum = newNum << 1;
        }
        num = num >> 1;
    }

    if(num & 1) {
            newNum = newNum + 1;
        }
    std::cout << newNum;
 */   
}