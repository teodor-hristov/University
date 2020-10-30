#include <iostream>

int main() {
    // Task 1

    // Task 2
   /*
    const int practH = 14, practM = 15, practS = 0;
    int h,m,s;

    
    std::cin >> h >> m >> s;

    if(h > practH && m > practM && s > practS) { 
        std::cout << "I am late" << std::endl;
    } else {
        std::cout << "I am not late" << std::endl;
    }
    */

    //Task 3
    /*
    int day;

    std::cin >> day;

    switch(day) {
        case 1:
            std::cout << "DIS \nLA \nUP" << std::endl;
        break;
        
        case 2:
        std::cout << "DIS \nLA \nUP" << std::endl;
        break;
        
        case 3:
        std::cout << "DIS \nLA \nUP upr" << std::endl;
        break;
        
        case 4:
        std::cout << "DIS \nLA upr \nUP" << std::endl;
        break;
        
        case 5:
        std::cout << "DIS \nLA \nUP" << std::endl;
        break;
        
        default :
            std::cout << "ninam" << std::endl;     
        break;
    }
    */

   //Task 4

   /*
    int a, b;

    std::cin >> a >> b;

    for (int i = a; i <= b; i++) {
        if(i & 1)
            std::cout << i << " " ;
    }
        std::cout << std::endl;
    */

   //Task 5
    /*
   int n, sum = 0;

   std::cin >> n;

   for (int i = 1; i <= n; i++) {
       if(i % 5 == 0) {
           sum += 2*i;
       } else {
           sum += i + 2;
       }
   }

   std::cout << sum;
   */

    //Task 6
    /*
    int prev = 0, next = 1, n, temp;

    std::cin >> n;

    for(int i = 0; i < n-2 ; i++) {
        temp = next;
        next = next + prev;
        prev = temp;
    }
    std::cout << next << std::endl;
    */

   //Task 7

   int num = 0, newNum = 0;
   std::cin >> num;

   for (int i = 1; i <= sizeof(int)*8; i++)
   {

       for(int j = 0; j < sizeof(int)*8; j++) {
           if(num & 1) {
               newNum = (newNum + 1) << 1;
           } else {
               newNum = newNum << 1;
           }
       }

       std::cout << newNum % 2;
       newNum /= 2;

       if(i % 8 == 0)
        std::cout << "'";

   }
       std::cout << std::endl;

   
}