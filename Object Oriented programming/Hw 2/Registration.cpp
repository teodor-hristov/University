#include <string>
#include "Registration.h"

#define MAX_LEN 8
#define MIN_LEN 7

const std::string &Registration::getRegistrationNumber() const {
    return registrationNumber;
}

void Registration::setRegistrationNumber(const std::string &registrationNumber) {
    if(isNumberValid(registrationNumber)){
        Registration::registrationNumber = registrationNumber;
    } else {
        //todo throw except.
    }
}

Registration::Registration(const std::string &number) {
    setRegistrationNumber(number);
}

bool Registration::isNumberValid(const std::string &number) {
    // 7 <= len <= 8
    std::size_t len = number.length();

    if(len > MAX_LEN || len < MIN_LEN){
        return false;
    }else {
        if(len == 7){
            //C1234AB
            return isalpha(number[0]) && isdigit(number[1]) &&
                    isdigit(number[2]) && isdigit(number[3]) &&
                    isdigit(number[4]) && isalpha(number[0]) && isalpha(number[0]);
        } else {
            //XY1111YX

            return isalpha(number[0]) && isalpha(number[1]) &&
                    isdigit(number[2]) && isdigit(number[3]) &&
                    isdigit(number[4]) && isdigit(number[5]) &&
                    isalpha(number[6]) && isalpha(number[7]);
        }
    }

}
