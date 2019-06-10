#include "btree.h"


void BTree::copyAll(Node*& orig,Node*& dest)
{
    if(orig == nullptr){
        return;
    }
    try {
        if((dest = new Node(orig->getData())) == nullptr){
            throw Error("Memoria no disponible, ");
    }
    } catch (Error ex) {
        throw Error("Memoria no disponible");
    }
    copyAll(orig->getLeft(),dest->getLeft());
    copyAll(orig->getRight(), dest->getRight());
}


void BTree::insertData(Node*& r, const int& e)
{
    if(r == nullptr){
        try{
            if((r = new Node(e)) == nullptr){
                throw Error("Memoria no disponible, insertData");
            }
        }
        catch (Error ex) {
            throw Error(ex.what());
          }
        return;
        }
    if(e < r->getData()){
        insertData(r->getLeft(),e);
        }
    else{
        insertData(r->getRight(),e);
        }
    //doBalancing(r);
}


Node*& BTree::findData(Node*& r, const int& e)
{
    if(r == nullptr or e == r->getData()){
        return r;
        }
    if(e < r->getData()){
        return findData(r->getLeft(),e);
        }
    return findData(r->getRight(),e);
}


Node*& BTree::getTheLowest(Node*& r)
{
    if(r == nullptr or r->getLeft() == nullptr){
        return r;
        }
    return getTheLowest(r->getLeft());
}


Node*& BTree::getTheHighest(Node*& r)
{
    if(r == nullptr or r->getRight() == nullptr){
        return r;
        }
    return getTheHighest(r->getRight());
}

void BTree::preOrder(Node *r)
{
    if(r == nullptr){
        return;
    }
    std::cout << r->getData() << ", ";
    preOrder(r->getLeft());
    preOrder(r->getRight());
}

void BTree::inOrder(Node *r)
{
    if(r==nullptr){
            return;
        }
        inOrder(r->getLeft());
        std::cout << r->getData() << ", ";
        inOrder(r->getRight());

}

void BTree::postOrder(Node *r)
{
    if(r == nullptr){
            return;
        }
        postOrder(r->getLeft());
        postOrder(r->getRight());

        std::cout << r->getData() << ", ";
}

int BTree::balanceFactor(Node *&r)
{
    return getHeight(r->getRight()) - getHeight(r->getLeft());
}


void BTree::deleteAll(Node*&r)
{
    if(r == nullptr){
        return;
    }

    deleteAll(r->getLeft());
    deleteAll(r->getRight());
    delete r;
    r = nullptr;
}


int BTree::getHeight(Node*& r)
{
    /*if(r == nullptr){
        return 0;
        }
    int leftHight(getHeight(r->getLeft()));
    int rightHeight(getHeight(r->getRight()));

    if(leftHight > rightHeight){
        return leftHight + 1;
        }
    return rightHeight + 1;*/

    if(r == nullptr){
        return 0;
        }
    int AuxLeftHight(getHeight(r->getLeft()));
    int AuxRightHeight(getHeight(r->getRight()));
    leftHeight = AuxLeftHight;
    rightHeight = AuxRightHeight;
    return 1 + (AuxLeftHight > AuxRightHeight ? AuxLeftHight : AuxRightHeight);
}



//Public

BTree::BTree(): root(nullptr) {}


BTree::BTree(BTree &t): root(nullptr)
{
    copyAll(t.root,root);
}


BTree::~BTree()
{
    deleteAll(root);
}


bool BTree::isEmpty() const
{
    return root == nullptr;
}


bool BTree::isLeaf(Node*& r) const
{
    return r != nullptr and r->getLeft() == r->getRight();
}


void BTree::insertData(const int& e)
{
    insertData(root, e);
}


void BTree::deleteData(Node*&)
{

}


Node*& BTree::findData(const int& e)
{
    return findData(root,e);
}


int& BTree::retrieve(Node*& r)
{
    if(r == nullptr){
        throw Error("Posicion invalida, retrieve");
        }
    return r->getData();
}


BTree& BTree::operator=(BTree &t)
{
    deleteAll();

    copyAll(t.root,root);

    return *this;
}


int BTree::getHeight()
{
    return getHeight(root);
}


void BTree::deleteAll()
{
    deleteAll(root);
    root = nullptr;
}

void BTree::preOrder()
{
    preOrder(root);
}

void BTree::inOrder()
{
    inOrder(root);
}

void BTree::postOrder()
{
    postOrder(root);
}

int BTree::getLeftHeight()
{
    return leftHeight;
}

int BTree::getRightHeight()
{
    return rightHeight;
}

void BTree::simpleRotationToTheLeft(Node*& r){
    Node* aux1(r->getRight());
    Node* aux2(aux1->getLeft());

    r->setRight(aux2);
    aux1->setLeft(r);
    r = aux1;
}

void BTree::simpleRotationToTheRight(Node*& r)
{
    Node* aux1(r->getLeft());
    Node* aux2(aux1->getRight());

    r->setLeft(aux2);
    aux1->setRight(r);
    r = aux1;
}

void BTree::doubleRotationToTheLeft(Node*& r){
    simpleRotationToTheRight(r->getRight());
    simpleRotationToTheLeft(r);
}

void BTree::doubleRotationToTheRight(Node*& r){
    simpleRotationToTheLeft(r->getLeft());
    simpleRotationToTheRight(r);
}

void BTree::doBalancing(Node*& r)
{
    switch(balanceFactor(r)){
        case 2:
            if(balanceFactor(r->getRight()) == 1){
                simpleRotationToTheLeft(r);
            }
            else{
                doubleRotationToTheLeft(r);
            }
        break;

        case -2:
            if(balanceFactor(r->getLeft()) == -1){
                simpleRotationToTheRight(r);
            }
            else{
                doubleRotationToTheRight(r);
            }
        break;

    }
}
