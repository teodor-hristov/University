#ifndef DATASTRUCTURES_STACK_H
#define DATASTRUCTURES_STACK_H

#include "../DynamicArray/DynamicArray.h"

class Stack {
private:
    DynamicArray<int> *container;
public:
    Stack();
    Stack(const Stack& rhs) = delete;
    Stack& operator=(const Stack& rhs) = delete;
    ~Stack();

    int Pop();
    void Push(const int& item);
    const int& Peek() const;
};


#endif //DATASTRUCTURES_STACK_H
