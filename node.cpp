#include "node.h"

Node::Node()
{

}

Node::Node(int _key)
{
    leftSon = rightSon = nullptr;
    p = rand();
    key = _key;
}
