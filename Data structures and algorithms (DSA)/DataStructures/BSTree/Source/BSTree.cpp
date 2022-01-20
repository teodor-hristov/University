#include "../Header/BSTree.h"
#include <iostream>
#include <cassert>

void Node::copy(const Node &node) {
    assert(this);
    this->value = node.value;
    this->rInheritor = node.rInheritor;
    this->lInheritor = node.lInheritor;
}

Node::Node() : value(0), lInheritor(nullptr), rInheritor(nullptr) {}

Node::Node(const int value) : Node() {
    this->value = value;
}

Node::Node(const Node &rhs) : Node() {
    copy(rhs);
}

Node &Node::operator=(const Node &rhs) {
    if (this == &rhs) {
        assert(false);
    }

    copy(rhs);
    return *this;
}

int Node::getValue() const {
    return this->value;
}

Node *Node::getLeft() {
    return this->lInheritor;
}

Node *Node::getRight() {
    return this->rInheritor;
}

void Node::setLInheritor(Node *lInheritor) {
    this->lInheritor = lInheritor;
}

void Node::setRInheritor(Node *rInheritor) {
    this->rInheritor = rInheritor;
}

BSTree::BSTree() {
    root = nullptr;
}

BSTree::BSTree(const int value) {
    root = new Node(value);
}

void BSTree::insert(int value) {
    Node *node = new Node(value);
    Node *position = root;

    if (!position) {
        root = node;
        return;
    }

    while (true) {
        if (!position) {
            position = node;
            break;
        }

        if (position->getValue() >= node->getValue()) {
            if (!position->getLeft()) {
                position->setLInheritor(node);
                break;
            }

            position = position->getLeft();
        }

        if (position->getValue() < node->getValue()) {
            if (!position->getRight()) {
                position->setRInheritor(node);
                break;
            }

            position = position->getRight();
        }
    }
}

void BSTree::printRec(Node *node) const {
    if (!node) {
        return;
    }

    std::cout << node->getValue() << " ";

    printRec(node->getLeft());
    printRec(node->getRight());
}

void BSTree::print() const {
    printRec(root);
}

void BSTree::remove(int value) {

}

Node &BSTree::find(int value) {

}

BSTree::~BSTree() {

}
