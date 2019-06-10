#include <iostream>
#include <iostream>
#include <stdlib.h>
#include<time.h>

#include "btree.h"

using namespace std;

int main()
{
    BTree myTree;
    int data;
    int n;
    string salir;
    srand(time(NULL));
    do{
//        cout << "Cantidad: ";
//        cin >> n;
//        for(int i(0); i < n; i++){
//            data = rand()% 100000;
//            //cout << "Insertando: " << data <<endl;
//            myTree.insertData(data);
//        }

        myTree.insertData(44);
        myTree.insertData(74);
        myTree.insertData(29);
        myTree.insertData(53);
        myTree.insertData(74);
        myTree.insertData(96);
        myTree.insertData(31);
        myTree.insertData(60);
        myTree.insertData(54);
        myTree.insertData(53);
        myTree.insertData(98);
        myTree.insertData(99);
        cout << "Recorridos: " << endl;
        cout << "PreOrder: " << endl;
        myTree.preOrder();
        cout << endl;
        cout << "\tInOrder: " << endl;
        myTree.inOrder();
        cout << endl;
        cout << "\tPostOrder: " << endl;
        myTree.postOrder();
        cout << endl << endl;
        cout << "Altura del arbol: " << myTree.getHeight() << endl;
        cout << "Altura izquierda: " << myTree.getLeftHeight() << endl;
        cout << "Altura derecha: " << myTree.getRightHeight() << endl << endl;
        cout << "Si no desea volver a ingresar S: " << endl;
        cin >> salir;
    }while (salir != "S");

}
