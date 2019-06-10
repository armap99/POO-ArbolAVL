#include "node.h"


Node::Node() : dataPtr(nullptr), left(nullptr), right(nullptr) { }


Node::Node(const int& e) : dataPtr(new int(e)), left(nullptr), right(nullptr) {
    if (dataPtr == nullptr) {
        throw Error("MEMORIA NO DISPONIBLE, createNodo");
    }
}

Node::~Node()
{
    delete dataPtr;
}

int& Node::getData()
{
    return *dataPtr;
}

int* Node::getDataPtr() const
{
    return dataPtr;
}

Node*& Node::getRight()
{
    return right;
}

Node*& Node::getLeft()
{
    return left;
}


void Node::setDataPtr(int*& p)
{
    dataPtr = p;
}

void Node::setData(const int& e)
{
    if (dataPtr == nullptr) {
        if ((dataPtr = new int(e)) == nullptr) {
            throw Error("MEMORIA NO DISPONIBLE, setData");
        }
    }

    else {
        *dataPtr = e;
    }
}

void Node::setRight(Node*& p)
{
    right = p;
}

void Node::setLeft(Node*& p)
{
    left = p;
}
