//
// Created by tedo3637 on 10.11.21 г..
//
#include <iostream>
#include "DynamicArray.h"

template <typename T>
DynamicArray<T>::DynamicArray(int size) : size(size), elementsCount(0) {
    this->elements = new T[size]{0};
    if (this->elements == nullptr)
    {
        throw std::bad_alloc();
    }
}
template <typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] this->elements;
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T> &rhs) : elementsCount(rhs.elementsCount), size(rhs.size) {
    if (this == &rhs)
    {
        return;
    }

    this->elements = new T(rhs.size);
    if(this->elements == nullptr)
    {
        throw std::bad_alloc();
    }

    memcpy(this->elements, rhs.elements, rhs.size);
}

template <typename T>
void DynamicArray<T>::resize() {
    size_t newSize = this->size * resizeFactor;
    T* temp = new T[(int)newSize]{0};

    memcpy(temp, this->elements, this->size*sizeof(elements[0]));
    this->size = newSize;

    delete[] this->elements;
    this->elements = temp;
}

template <typename T>
void DynamicArray<T>::Add(const T& item, const size_t position) {
    if (position >= this->size)
    {
        return;
    }

    if (position > this->elementsCount)
    {
        this->elements[position] = item;
        this->elementsCount++;
        return;
    }

    if (this->size < this->elementsCount + 1)
    {
        this->resize();
    }

    for (int i = this->size - 1; i > position; --i) {
        this->elements[i] = this->elements[i-1];
    }

    this->elements[position] = item;
    this->elementsCount++;
}

template <typename T>
size_t DynamicArray<T>::getSize() const {
    return this->size;
}

template <typename T>
bool DynamicArray<T>::isEmpty() const {
    return this->elementsCount == 0;
}

template <typename T>
int DynamicArray<T>::getAt(const int pos) const {
    if (pos < this->size)
    {
        return this->elements[pos];
    }
}

template <typename T>
void DynamicArray<T>::Remove(size_t position) {
    if (this->size <= 1 || position >= this->size)
    {
        return;
    }

    T* temp = new T[this->size-1]{0};
    int tempIndex;
    int realIndex;

    for (realIndex = 0, tempIndex = 0; realIndex < this->size; realIndex++) {
        if (realIndex == position)
        {
            continue;
        }

        temp[tempIndex] = this->elements[realIndex];
        tempIndex++;
    }

    delete[] this->elements;
    this->elements = temp;
    this->elementsCount--;
    this->size--;
}
