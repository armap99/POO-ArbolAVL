#ifndef NODE_H
#define NODE_H
#include "error.h"


class Node
{
private:
    int* dataPtr; //Apuntador al dato
    Node* left;
    Node* right;

public:

    Node();
    Node(const int&);

    ~Node();

    int& getData();
    int* getDataPtr() const;

    Node*& getRight();
    Node*& getLeft();

    void setDataPtr(int*&);
    void setData(const int&);

    void setRight(Node*&);
    void setLeft(Node*&);
};

#endif // NODE_H
