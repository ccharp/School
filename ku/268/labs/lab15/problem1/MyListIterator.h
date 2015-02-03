#ifndef MYLISTITERATOR_H
#define MYLISTITERATOR_H
#include "node.h"
#include "MyList.h"

class MyList;

class MyListIterator
{
	public:
		MyListIterator(const MyList *aList, node *np);

		const int operator *();
		MyListIterator operator ++();
		bool operator == (const MyListIterator & anoPt) const;
		bool operator != (const MyListIterator & anoPt) const;
		friend class MyList;
	
	private:
		const MyList *theList;
		node *currNode;
};
#endif
