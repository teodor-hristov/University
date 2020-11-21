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

unsigned length(const char* str) {
    unsigned result;

    for(result = 0; str[result] != '\0'; result++);

    return result;
}

//asdasd\0
void reverse(char* str) {

    const unsigned len = length(str);    
    char tempFirst = 0;

    for(int i = 0; i < len/2; i++) {
        tempFirst = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = tempFirst;
    }
}

bool isValidNaturalNumber(const char* str) {
    bool status = true;
    int len = length(str);
    
    if(str[0] == '0'){
        status = false;
        return status;
    }
    for(int i = 0; i < len; i++) {
        if(str[i] < '1' || str[i] > '9') {
            status = false;
            return status; 
        }
    }
    
    return status;
}

bool isValidNaturalNumberIn16(const char* str) {
    int len = length(str);

    if(str[0] == '0') {
        return false;
    }

    for(int i = 0; i < len; i++) {
        if((str[i] >= '0' && str[i] <= '9') && (str[i] >= 'A' && str[i] <= 'Z')) {
            return true;
        } else {
            return false;
        }
    }

    return true;
}

int parseHexDigit(char c) {
    char chars[17] = "0123456789ABCDEF";

        for(int i = 0; i < 17; i++) {
                if(c == chars[i]) {
                    return i;
                }
        }
}

int power(int a, int b) {
    int result = 1;
    for(int i = 0; i < b; i++) {
        result *= a;
    }

    return result;
}

bool isValidHex(const char* str) {
    int len = length(str);
    for(int i = 0; i < len; i++) {
        if((str[i] >= 'A' && str[i] <= 'F') || (str[i] >= '0' && str[i] <= '9')) {

        } else {
            return false;
        }
    }

    return true;
}

//14A
//
int convertFrom16To10(const char* str) {
    int len = length(str);
    int result = 0;

    if(!isValidHex(str)){
        return -1;
    }

    for(int i = 0; i < len; i++) {
        result += parseHexDigit(str[i]) * power(16, i);
    }

    return result;
}

const int MAX_LENGTH = 35;
int main() {

    char str[50] = "A1D2";
    int n = 9;

    cout << "Task 1: " << numberOfCharA(str) << endl;
    cout << "Task 2: " << numberOfDigits(str) << endl;
    cout << "Task 3: " << digitToChar(n) << endl;
    cout << "Task 4: " << lastDigitToChar(n) << endl;
    cout << "Task 5: " << firstDigitToChar(n) << endl;
    cout << "Task 6: " << areAllUpcase(str) << endl;

    //unsigned num;
    // cin >> num;
    // readAndPrintAscii(num);
    
    reverse(str);
    cout << "Reverse: " << str << endl;
    cout << "Task 9: " << isValidNaturalNumber(str) << endl;
    cout << "Task 10: " << isValidNaturalNumberIn16(str) << endl;
    cout << "Task real 8: " << convertFrom16To10(str) << endl;


}