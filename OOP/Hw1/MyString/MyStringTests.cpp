#pragma once

#include "../catch_amalgamated.hpp"
#include "MyString.hpp"

TEST_CASE("Default constructor"){
MyString str = MyString();
    REQUIRE(str.size() == 0);
}

TEST_CASE("Constructor with one arg"){
    MyString str = MyString("Quick brown fox");
    char str1[] = "Quick brown fox";
    REQUIRE(str.size() == 15);
    for(int i = 0; i < 15; i++){
        REQUIRE(str.at(i) == str1[i]);
    }
}

TEST_CASE("MyString .at()"){
    MyString str = MyString("Quick brown fox");
    CHECK_THROWS(str.at(str.size()));
    CHECK_THROWS(str.at(-1));
}

TEST_CASE("MyString [] operator"){
    const char primaryString[] = "Quick brown fox";
    MyString str = MyString(primaryString);
    for(int i = 0; i < 15; i++){
        REQUIRE(str[i] == primaryString[i]);
    }
}