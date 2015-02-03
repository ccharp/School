#include "MyListIterator.h"

MyListIterator::MyListIterator(const MyList * aList, node * cP):theList(aList), currNode(cP)
{
	;
}

const int MyListIterator::operator *()
{
	return currNode->getValue();
}

MyListIterator MyListIterator::operator ++()
{
	currNode = currNode->getNext();
	return(*this);
}

bool  MyListIterator :: operator == (const MyListIterator&anoPt) const
{
  return ( ( theList == anoPt.theList) && (currNode == anoPt.currNode) );
}

bool  MyListIterator :: operator != (const MyListIterator&anoPt) const
{
  return ! ( (*this) == anoPt );
} 

