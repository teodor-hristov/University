#ifndef HOMEWORK1_NODE_H

/*Node is used in linked_list.hpp*/
template<class T>
struct node {
    T value{};
    node *next_element_ptr{};
};

#define HOMEWORK1_NODE_H
#endif //HOMEWORK1_NODE_H
