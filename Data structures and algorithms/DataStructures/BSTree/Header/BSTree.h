#ifndef BSTREE_BSTREE_H
#define BSTREE_BSTREE_H

typedef struct Node_t {
private:
    int value;
    Node_t *lInheritor;
    Node_t *rInheritor;

    void copy(const Node_t &node);

public:
    Node_t();

    Node_t(int value);

    Node_t(const Node_t &rhs);

    Node_t &operator=(const Node_t &rhs);
} *Node;

struct BSTree{
private:
    Node root;
public:
    BSTree() = delete;
    BSTree(int value);
    void insert(Node node);
    void remove(int value);
    void find(int value);
    ~BSTree();
};

#endif //BSTREE_BSTREE_H
