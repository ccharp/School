#include "bsTree.h"
#include <iostream>

using namespace std;

//template <typename T>
int main(int argc, char * argv[])
{
    TNode<int> intNode1(5);
    TNode<int> intNode2(3);
    TNode<int> intNode3(7);

    intNode1.setLeft(&intNode2);
    intNode1.setRight(&intNode3);
    intNode1.setValue(6);

    cout<<"Printing the value of nodes"<<endl;
    cout<<"==========================="<<endl;
    cout<<intNode1.getValue()<<endl;
    cout<<intNode2.getValue()<<endl;
    cout<<intNode3.getValue()<<endl;
    cout<<"Left child of node 1 : "<<intNode1.getLeft()->getValue()<<endl;
    cout<<"Right child of node 1 : "<<intNode1.getRight()->getValue()<<endl;

    bsTree<int> tree1;
    tree1.insert1(5);
    tree1.insert1(4);
    tree1.insert1(6);
    tree1.inOrderTraversal();
	
	return 0;
}

