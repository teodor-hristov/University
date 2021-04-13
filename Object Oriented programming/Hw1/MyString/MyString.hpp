#pragma once
#include <iostream>

class MyString {
private:
    char* str;
    size_t length;
    size_t lastIndex;

public:
    MyString();

    ~MyString();
    MyString(const MyString &str1);
    MyString& operator=(MyString &str1);

    MyString(const char *str);
    char& at(std::size_t pos);
    //const char& at(std::size_t pos);
    char& operator[](std::size_t pos);
    const char& operator[](std::size_t pos) const;
    char& front();
    const char& front() const;
    const char& back() const;
    bool empty() const;
    std::size_t size() const;
    void clear();
    void push_back(char c);
    void pop_back();

    MyString& operator+=(char c);
    MyString& operator+=(const MyString& rhs);
    MyString operator+(char c) const;
    MyString operator+(const MyString& rhs) const;

    const char* c_str() const;

    bool operator==(const MyString &rhs) const;
    bool operator<(const MyString &rhs) const;

};