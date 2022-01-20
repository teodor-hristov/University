//
// Created by tedo3637 on 17.11.21 г..
//

#include "Stack.h"

Stack::Stack(){
    this->container = new DynamicArray<int>();
}

Stack::Stack(const Stack &rhs) : Stack() {
    *container = *(rhs.container);
}

Stack &Stack::operator=(const Stack &rhs) {
    if (&rhs == this)
        throw std::invalid_argument("Self assign.");

    *container = *(rhs.container);

    return *this;
}

Stack::~Stack() {
    delete this->container;
}

int Stack::Pop() {
    if (container->isEmpty())
        return 0;

    int temp = container->getAt((int)container->Length() - 1);
    container->Remove(container->Length() - 1);

    return temp;
}

void Stack::Push(const int& item) {
    container->Add(item, container->Length());
}

const int& Stack::Peek() const {
    if (this->container->isEmpty())
        throw std::bad_exception();

    return (*container)[this->container->Length() - 1];
}

bool Stack::empty() const {
    return container->isEmpty();
}

size_t Stack::size() const {
    return container->Length();
}
