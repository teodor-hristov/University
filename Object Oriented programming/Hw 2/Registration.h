#ifndef HW_2_REG_H
#define HW_2_REG_H
#pragma once
#include <string>

class Registration{
private:
    std::string registrationNumber;
public:
    Registration(const std::string& number);

    const std::string &getRegistrationNumber() const;

    void setRegistrationNumber(const std::string &registrationNumber);

    static bool isNumberValid(const std::string& number);
};

#endif