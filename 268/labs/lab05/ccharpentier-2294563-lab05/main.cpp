#include <iostream>
#include "DNode.h"
using namespace std;

int main(int argc, char * argv[])
{
    DNode *myDNode = new DNode();
    myDNode->setValue( 5 );
    DNode *myDNode2 = new DNode( 10, myDNode, NULL ); //1st argument is the value, 2nd arg is the prev pointer, 3rd arg is next pointer
    DNode *myDNode3 = new DNode( 15, NULL, NULL );

    myDNode->setNext( myDNode2 );
    myDNode->setPrevious( myDNode3 );
    myDNode3->setNext( myDNode );

    cout << "The value of the nodes" << endl;
    cout << "=================" << endl;

    cout << myDNode->getValue() << endl;
    cout << myDNode2->getValue() << endl;
    cout << myDNode3->getValue() << endl;

    cout << endl << "In order " << endl;
    cout << "=================" << endl;

    for(DNode *cur = myDNode3; cur != NULL; cur = cur->getNext())
    {
        cout << "Current value: " << cur->getValue() << endl;
    }

    cout << endl << "Reverse order " << endl;
    cout << "=================" << endl;

    for(DNode *cur = myDNode2; cur != NULL; cur = cur->getPrev())
    {
        cout << "Current value: " << cur->getValue() << endl;
    }

    return 0;
}

