#ifndef NODE_H
#define NODE_H

#include <random>

class Node
{
public:
    Node();
    Node(int _key);
    Node* leftSon, * rightSon;
    int key, p;
    int w, wLeft, wRight;
};

#endif // NODE_H
