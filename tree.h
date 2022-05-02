#ifndef TREE_H
#define TREE_H

#include <node.h>

class Tree
{
public:
    Node* root;
    Tree();
    void add(int x);
    void recalc();
};

#endif // TREE_H
