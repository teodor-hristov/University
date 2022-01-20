#ifndef BSTREE_BSTREE_H
#define BSTREE_BSTREE_H

struct Node {
private:
    int value;
    Node *lInheritor;
    Node *rInheritor;

    void copy(const Node &node);

public:
    Node();

    Node(int value);

    Node(const Node &rhs);

    Node &operator=(const Node &rhs);

    int getValue() const;
    Node* getLeft();
    Node* getRight();
    void setLInheritor(Node *lInheritor);
    void setRInheritor(Node *rInheritor);

};

struct BSTree{
private:
    Node* root;

    void printRec(Node* node) const;
public:
    BSTree();
    BSTree(int value);
    void insert(int value);
    void remove(int value);
    Node& find(int value);
    void print() const;
    ~BSTree();
};

#endif //BSTREE_BSTREE_H
