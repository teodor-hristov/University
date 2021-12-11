#include <cstring>
#include <cassert>
#include <iostream>

template <class T>
struct node
{
    T value{};
    node *next_element_ptr{};
};

template <class T>
struct linked_list
{
public:
    linked_list(){
        first = nullptr;
        last = nullptr;
        size = 0;
    };
    ~linked_list()
    {
        auto current = first;
        while (current != nullptr)
        {
            auto next = current->next_element_ptr;
            delete current;
            current = next;
        }
    }

    void push_back(const T &value)
    {
        node<T> *new_last = new node<T>();
        new_last->value = value;
        if (last != nullptr)
        {
            last->next_element_ptr = new_last;
        }
        if (first == nullptr)
        {
            assert(last == nullptr);
            first = new_last;
        }
        last = new_last;
        size++;
    }

    void push_front(const T &value)
    {
        node<T> *new_first = new node<T>();
        new_first->value = value;
        new_first->next_element_ptr = first;
        if (last == nullptr)
        {
            assert(first == nullptr);
            last = new_first;
        }
        first = new_first;
        size++;

    }

    void pop_front()
    {
        if (first == nullptr)
        {
            assert(last == nullptr);
            throw std::invalid_argument("Cannot pop empty list");
        }
        node<T> *first_cpy = first;
        first = first->next_element_ptr;
        delete first_cpy;
        if(first == nullptr)
        {
            last = nullptr;
        }
        size--;
    }

    void pop_back()
    {
        if (last == nullptr)
        {
            assert(first == nullptr);
            throw std::invalid_argument("Cannot pop empty list");
        }
        if(first == last)
        {
            delete first;
            first = nullptr;
            last = nullptr;
            return;
        }
        node<T> *current = first;
        while (current->next_element_ptr != last)
        {
            current = current->next_element_ptr;
        }
        current->next_element_ptr = nullptr;
        delete last;
        last = current;
        size--;

    }

    const T &operator[](size_t index) const
    {
        auto current = first;
        for (size_t id = 0; id < index; id++)
        {
            current = current->next_element_ptr;
        }
        return current->value;
    }

    bool empty(){
        return size == 0 || first == nullptr;
    }

    T& front(){
        return first->value;
    }

    T& back(){
        return last->value;
    }


private:
    node<T> *first{};
    node<T> *last{};
    size_t size;
};