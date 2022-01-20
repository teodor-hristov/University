#pragma once

#include <cstring>
#include <cassert>
#include <iostream>
#include "Node.hpp"

template<class T>
struct linked_list {
private:
    node<T> *firstNode{};
    node<T> *lastNode{};
    size_t size;
public:
    linked_list() {
        firstNode = nullptr;
        lastNode = nullptr;
        size = 0;
    };

    ~linked_list() {
        auto current = firstNode;
        while (current != nullptr) {
            auto next = current->next_element_ptr;
            delete current;
            current = next;
        }
    }

    void push_back(const T &value) {
        auto *new_last = new node<T>();
        new_last->value = value;
        if (lastNode != nullptr) {
            lastNode->next_element_ptr = new_last;
        }
        if (firstNode == nullptr) {
            assert(lastNode == nullptr);
            firstNode = new_last;
        }
        lastNode = new_last;
        size++;
    }

    void push_front(const T &value) {
        auto *new_first = new node<T>();
        new_first->value = value;
        new_first->next_element_ptr = firstNode;
        if (lastNode == nullptr) {
            assert(firstNode == nullptr);
            lastNode = new_first;
        }
        firstNode = new_first;
        size++;

    }

    void pop_front() {
        if (firstNode == nullptr) {
            assert(lastNode == nullptr);
            throw std::invalid_argument("Can't pop empty list!");
        }
        auto first_cpy = firstNode;
        firstNode = firstNode->next_element_ptr;
        delete first_cpy;
        if (firstNode == nullptr) {
            lastNode = nullptr;
        }
        size--;
    }

    void pop_back() {
        if (lastNode == nullptr) {
            assert(firstNode == nullptr);
            throw std::invalid_argument("Can't pop empty list!");
        }
        if (firstNode == lastNode) {
            delete firstNode;
            firstNode = nullptr;
            lastNode = nullptr;
            return;
        }
        auto current = firstNode;
        while (current->next_element_ptr != lastNode) {
            current = current->next_element_ptr;
        }
        current->next_element_ptr = nullptr;
        delete lastNode;
        lastNode = current;
        size--;

    }

    bool empty() {
        return size == 0 || firstNode == nullptr;
    }

    T &front() {
        return firstNode->value;
    }

    T &back() {
        return lastNode->value;
    }
};