//
// Created by tedo3637 on 17.11.21 г..
//

#include "Stack.h"

DynamicArray<int> lastElementPosition() {

}

Stack::Stack(){
    this->container = new DynamicArray<int>();
}

Stack::~Stack() {
    delete this->container;
}

int Stack::Pop() {
    int temp;

    temp = container->getAt(container->Length() - 1);
    container->Remove(container->Length() - 1);

    return temp;
}

void Stack::Push(const int& item) {
    container->Add(item, container->Length() - 1);
}

const int& Stack::Peek() const {
    if (this->container->isEmpty())
        throw std::bad_exception();

    return (*container)[this->container->Length() - 1];
}
