#include <iostream> 

using namespace std;

void printAscii(char str[]) {
    for(int i = 0; str[i] != '\0'; i++) {
        cout << (int)str[i] << ' ';
    }
    cout << endl;
}
int numberOfDigits(const char* str) {
    unsigned count = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] >= '0' && str[i] <= '9') {
            count++;
        }
    }

    return count;
}

int numberOfCharA(const char* str) {
    unsigned count = 0;

    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == 'a'){
            count++;
        }
    }

    return count;
}

char digitToChar(const int n) {
    return (char)n;
}

char lastDigitToChar(const int n) {
    return digitToChar(n % 10);
}

char firstDigitToChar(const int n) {
    int tempN = n;
    while(1) {
        if(tempN/10 == 0) {
            return (char)tempN;
        }
        tempN = tempN % 10;
        tempN /= 10;
    }
}

bool areAllUpcase(char* str) {
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] < 'A' || str[i] > 'Z'){
            return false;
        }
    }

    return true;
}

void readAndPrintAscii(const unsigned n){
    char str[n+1];
    for(unsigned i = 0; i < n; i++) {
        cin >> str[i];
    }
    str[n] = '\0';

    printAscii(str);
}

unsigned length(char* str) {
    unsigned result;

    for(result = 0; str[result] != '\0'; result++);

    return result;
}

//asdasd\0
// void reverse(char* str) {

//     unsigned len = length(str);    
//     char* tempStr = str;

//     for(int i = 0; i < len; i++) {
//         str[i] = tempStr[len - i - 1];
//     }

// }

const int MAX_LENGTH = 35;
int main() {

    char str[50] = "ASaD";
    int n = 9;

    cout << numberOfCharA(str) << endl;
    cout << numberOfDigits(str) << endl;
    cout << digitToChar(n) << endl;
    cout << lastDigitToChar(n) << endl;
    cout << firstDigitToChar(n) << endl;
    cout << areAllUpcase(str) << endl;

    //unsigned num;
    // cin >> num;
    // readAndPrintAscii(num);
    
    reverse(str);
    cout << str << endl;
}