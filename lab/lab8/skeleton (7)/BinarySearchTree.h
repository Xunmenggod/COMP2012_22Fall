#ifndef _BINARY_SEARCH_TREE_H
#define _BINARY_SEARCH_TREE_H

const int MAX_NODES_NUMBER=50;

class BinarySearchTree
{
private:
    BinarySearchTree *leftSubTree;
    BinarySearchTree *rightSubTree;
    int value;

public:
    BinarySearchTree() = default;
    BinarySearchTree(int value);
    BinarySearchTree(const BinarySearchTree &other);
    ~BinarySearchTree();

    void add(int newValue);
    bool hasValue(const int valueToFind) const;

    void print(int depth) const;

    bool isSame(const BinarySearchTree* other);
    void buildNewBST(BinarySearchTree* newBST, int value);
    void traverseAdd(BinarySearchTree* newBST);
};

#endif