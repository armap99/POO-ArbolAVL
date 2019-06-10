#ifndef BTREE_H
#define BTREE_H
#include "node.h"

class BTree
{
private:
    Node* root;
    int rightHeight;
    int leftHeight;
    void copyAll(Node *&, Node *&);
    void insertData(Node*&, const int&);
    Node*& findData(Node*&, const int&);
    void deleteAll(Node*&);
    int getHeight(Node*&);
    Node*& getTheLowest(Node*&);
    Node*& getTheHighest(Node*&);
    void preOrder(Node*);
    void inOrder(Node*);
    void postOrder(Node*);

    //Avl
    int balanceFactor(Node*&);
    void simpleRotationToTheLeft(Node*&);
    void simpleRotationToTheRight(Node*&);
    void doubleRotationToTheLeft(Node*&);
    void doubleRotationToTheRight(Node*&);

    void doBalancing(Node*&);
public:
    BTree();
    BTree(BTree&);
    ~BTree();
    bool isEmpty() const;
    bool isLeaf(Node*&) const; //Saber si es hoja
    void insertData(const int&);
    void deleteData(Node*&);
    Node*& findData(const int&);
    int& retrieve(Node*&);
    BTree& operator = ( BTree&);
    int getHeight();
    void deleteAll();
    void preOrder();
    void inOrder();
    void postOrder();
    int getLeftHeight();
    int getRightHeight();


};

#endif // BTREE_H
