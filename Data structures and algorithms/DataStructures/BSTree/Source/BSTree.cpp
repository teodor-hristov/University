#include "../Header/BSTree.h"
#include <cassert>

void Node_t::copy(const Node_t &node) {
    assert(this);
    this->value = node.value;
    this->rInheritor = node.rInheritor;
    this->lInheritor = node.lInheritor;
}

Node_t::Node_t() : value(0), lInheritor(nullptr), rInheritor(nullptr) {}

Node_t::Node_t(const int value) : Node_t() {
    this->value = value;
}

Node_t::Node_t(const Node_t &rhs) : Node_t() {
    copy(rhs);
}

Node_t &Node_t::operator=(const Node_t &rhs) {
    if (this == &rhs) {
        assert(false);
    }

    copy(rhs);
    return *this;
}

BSTree::BSTree() {

}

void BSTree::insert(Node node) {

}

void BSTree::remove(int value) {

}

void BSTree::find(int value) {

}

BSTree::~BSTree() {

}
