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
void reverse(char* str) {

    const unsigned len = length(str);    
    char tempFirst = 0;

    for(int i = 0; i < len/2; i++) {
        tempFirst = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = tempFirst;
    }
}

const int MAX_LENGTH = 35;
int main() {

    char str[50] = "ASahD";
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
    cout << "Task 9: " << areAllUpcase(str) << endl;

}