//
// Created by tedo3637 on 10.11.21 г..
//

#ifndef ZADA4KA3_DYNAMICARRAY_H
#define ZADA4KA3_DYNAMICARRAY_H

template <typename T>
class DynamicArray{
private:
    const int resizeFactor = 2;
    size_t size;
    size_t elementsCount;
    T* elements;

    void resize();
public:
    explicit DynamicArray(int size = 10);
    ~DynamicArray();
    DynamicArray(const DynamicArray& rhs);

    void Add(const T& item, const size_t position);
    void Remove(size_t position);
    void ShrinkToFit();

    int getAt(const int pos) const;

    bool isEmpty() const;
    size_t getSize() const;
};

#endif //ZADA4KA3_DYNAMICARRAY_H
