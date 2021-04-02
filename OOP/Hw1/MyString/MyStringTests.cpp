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

TEST_CASE("Get last element (.back)"){
    MyString mystr = MyString("Quick brown fo#");
    REQUIRE(strcmp(&mystr.back(),"#") == 0);
}

TEST_CASE("Check if string is empty when it is not"){
    MyString mystr = MyString("Quick brown fo#");
    REQUIRE(!mystr.empty());
}

TEST_CASE("Check if string is empty when it is empty"){
    MyString mystr = MyString("");
    REQUIRE(mystr.empty());
}

TEST_CASE("Push back"){
    MyString mystr = MyString("");
    mystr.push_back('c');
    REQUIRE(strcmp(&mystr.back(), "c") == 0);
    mystr.push_back('0');
    mystr.push_back('%');
    mystr.push_back('\0');
    REQUIRE(strcmp(&mystr.back(), "") == 0);
}

TEST_CASE("Pop back"){
    MyString mystr = MyString("1.9TDI");
    mystr.pop_back();
    mystr.pop_back();
    REQUIRE(strcmp(&mystr.back(), "T") == 0);
}

TEST_CASE("Operator +"){
    MyString mystr = MyString("1.9TDI");
    MyString secondStr = mystr + '1';
    REQUIRE(strcmp(&secondStr.back(), "1") == 0);
}

TEST_CASE("Operator =="){
    MyString firstString = MyString("1.9TDI");
    MyString secString = MyString("1.9TDI");

    REQUIRE(firstString == secString);
}

TEST_CASE("Operator == not equal test"){
    MyString firstString = MyString("1.9TDI");
    MyString secString = MyString("1.8TDI");

    REQUIRE((firstString == secString) == false);
}

TEST_CASE("Operator + (MyString + MyString)"){
    MyString mystr = MyString("1.9TDI");
    MyString secondStr = MyString(" Greatest VW motor");
    MyString comparingString = MyString("1.9TDI Greatest VW motor");

    REQUIRE(comparingString == (mystr + secondStr));
}

TEST_CASE("Operator += (MyString += MyString)"){
    MyString mystr = MyString("^1.9TDI");
    MyString secondStr = MyString(" Greate&t VW motor");
    MyString comparingString = MyString("^1.9TDI Greate&t VW motor");

    mystr += secondStr;

    REQUIRE(mystr == comparingString);
}

TEST_CASE("Operator += (MyString += MyString) test for error"){
    MyString mystr = MyString("^1.9TDI");
    MyString secondStr = MyString(" Greate&t VW motor");
    MyString comparingString = MyString("^2.0TDI Greate&t VW motor");

    mystr += secondStr;

    REQUIRE((mystr == comparingString) == false);
}

