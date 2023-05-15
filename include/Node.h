#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

template <typename T>

class Node
{
public:
    T dado;
    Node *proximo;

    Node(T dado)
    {
        this->dado = dado;
        this->proximo = nullptr;
    }

    ~Node()
    {
    }
};

#endif