#include "tree.h"

Node* merge(Node* leftNode, Node* rightNode){
    if (leftNode == nullptr)
        return rightNode;
    if (rightNode == nullptr)
        return leftNode;
    if (leftNode->p < rightNode->p){
        leftNode->rightSon = merge(leftNode->rightSon, rightNode);
        return leftNode;
    } else {
        rightNode->leftSon = merge(leftNode, rightNode->leftSon);
        return rightNode;
    }
}

std::pair <Node*, Node*> split(Node* cur, int key){
    if (cur == nullptr)
        return {nullptr, nullptr};
    if (cur->key <= key){
        auto parts = split(cur->rightSon, key);
        cur->rightSon = parts.first;
        return {cur, parts.second};
    } else {
        auto parts = split(cur->leftSon, key);
        cur->leftSon = parts.second;
        return {parts.first, cur};
    }
}

Tree::~Tree()
{
    delete root;
}

void recalcWidth(Node* cur){
    if (cur == nullptr) return;
    recalcWidth(cur->leftSon);
    recalcWidth(cur->rightSon);

    cur->wLeft = cur->leftSon == nullptr ? 0 : cur->leftSon->w;
    cur->wRight = cur->rightSon == nullptr ? 0 : cur->rightSon->w;
    cur->w = cur->wLeft + cur->wRight + 1;
}

Tree::Tree()
{
    root = nullptr;
}

void Tree::add(int x)
{
    Node* newNode = new Node(x);
    auto parts = split(root, x);
    root = merge(parts.first, newNode);
    root = merge(root, parts.second);
}

void Tree::recalc()
{
    recalcWidth(root);
}
