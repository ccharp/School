#include "bsTree.h"
#include <iostream>

using namespace std;

int main(int argc, char * argv[])
{
    bsTree<int> tree1;

    tree1.insert(10);
    tree1.insert(6);
    tree1.insert(15);
    tree1.insert(2);
    tree1.insert(7);
    tree1.insert(4);
    tree1.insert(17);
    tree1.insert(21);

    tree1.inOrderTraversal();

   if( tree1.search(21) != NULL )
   {
       cout << "21 was found" << endl;
   }
   else
   {
       cout << "21 was not found" << endl;
   }

   tree1.remove(2);
		
   tree1.remove(15);
		
   tree1.inOrderTraversal();

   tree1.remove(6);
	
	tree1.inOrderTraversal(); cout << endl;
   tree1.remove(7);

   tree1.inOrderTraversal(); cout << endl;

   tree1.remove(10);
	 tree1.inOrderTraversal();cout << endl;

   tree1.remove(17);
	
   tree1.inOrderTraversal();cout << endl;
	
   tree1.remove(4);

   tree1.inOrderTraversal();cout << endl;

   tree1.remove(21);

   tree1.inOrderTraversal();cout << endl;

}

