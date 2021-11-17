#pragma once

#ifndef DATASTRUCTURES_STACK_H
#define DATASTRUCTURES_STACK_H

#include "../DynamicArray/DynamicArray.h"

class Stack {
private:
    DynamicArray<int> *container;
public:
    Stack();
    Stack(const Stack& rhs);
    Stack& operator=(const Stack& rhs);
    ~Stack();

    int Pop();
    void Push(const int& item);
    const int& Peek() const;

    bool empty() const;
    size_t size() const;
};

#endif //DATASTRUCTURES_STACK_H
