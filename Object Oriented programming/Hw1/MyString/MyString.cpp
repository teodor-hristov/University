#pragma once

#include "MyString.hpp"
#include <stdexcept>
#include <cstring>
#include <cassert>

MyString::MyString() {
    this->str = nullptr;
    this->length = 0;
    this->lastIndex = 0;
}

MyString::~MyString() {
    delete[] str;
    this->length = 0;
    this->lastIndex = 0;
}

MyString::MyString(const MyString &str1) {
    this->str = new char[str1.length];
    strcpy(this->str, str1.str);
    this->length = str1.length;
    this->lastIndex = str1.lastIndex;
}

MyString &MyString::operator=(MyString &str1) {
    this->str = str1.str;
    this->length = str1.length;
    this->lastIndex = str1.lastIndex;

    return *this;
}

MyString::MyString(const char *str) {
    this->length = strlen(str);
    this->str = new char[length + 1];
    strcpy(this->str, str);
    this->lastIndex = length - 1;
}

char &MyString::at(std::size_t pos) {
    if (pos >= length || pos < 0) {
        throw std::out_of_range("");
    }
    return this->str[pos];
}

char &MyString::operator[](std::size_t pos) {
    assert(pos < this->size() && pos >= 0);

    return this->at(pos);
}

const char &MyString::operator[](std::size_t pos) const {
    assert(pos < this->size() && pos >= 0);
    return this->str[pos];
}

char &MyString::front() {
    assert(this->length > 0);
    return this->str[0];
}

const char &MyString::front() const {
    assert(this->length == 0);
    return this->str[0];
}

const char &MyString::back() const {
    assert(this->length > 0);
    return this->str[this->lastIndex];
}


bool MyString::empty() const {
    return !this->length;
}

std::size_t MyString::size() const {
    return this->length;
}

void MyString::clear() {
    this->lastIndex = 0;
    memset(this->str, '\0', this->length);
}

char *makeSpace(MyString &str) {
    char *newString = new char[str.size() + 2]; //size +1 (for new char) and 1 for \0
    assert(newString);

    return newString;
}

void MyString::push_back(char c) {
    char *tempStr;
    tempStr = makeSpace(*this);
    this->length += 1;
    this->lastIndex += 1;

    strcpy(tempStr, this->str);
    tempStr[this->lastIndex] = c; // set here new char
    tempStr[this->lastIndex + 1] = '\0'; // need to add terminating zero

    delete[] this->str;
    this->str = tempStr;
}

void MyString::pop_back() {
    assert(this->size() > 0); //there is nothing to remove if string is empty
    char *tempStr;
    tempStr = makeSpace(*this);
    this->length -= 1;
    this->lastIndex -= 1;

    strcpy(tempStr, this->str);
    tempStr[this->lastIndex + 1] = '\0'; // need to add terminating zero

    delete[] this->str;
    this->str = tempStr;
}

MyString MyString::operator+(char c) const {
    MyString newString = *this;
    newString.push_back(c);

    return newString;
}

MyString &MyString::operator+=(char c) {
    MyString resultStr = *this + c;
    return resultStr;
}

MyString MyString::operator+(const MyString &rhs) const {
    MyString result = *this;
    for (int i = 0; i < rhs.size(); ++i) {
        result.push_back(rhs[i]);
    }

    return result;
}

MyString &MyString::operator+=(const MyString &rhs) {
    char* catString = new char[this->size() + rhs.size() + 1];

    strcpy(catString, this->str);
    strcat(catString, rhs.str);

    delete[] this->str;

    this->str = catString;

    this->length += rhs.length;
    this->lastIndex = this->length - 1;

    return *this;
}

const char *MyString::c_str() const {
    char* constString = new char[this->size() + 1];
    strcpy(constString,this->str);

    return constString;
}

bool MyString::operator==(const MyString &rhs) const {
    bool status = true;

    status = (this->size() == rhs.size()) && (strcmp(this->str, rhs.str) == 0);

    return status;
}

bool MyString::operator<(const MyString &rhs) const {
    return this->size() < rhs.size();
}
