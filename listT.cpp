/* listT.cpp
 Implementation file for a class of a linked list of strings
*/

#include "listT.h"

using namespace std;

bool LinkedList::SearchList( string keyActorName )
{
  NodePtr curr = start; // a node pointer to the beginning of the list
  while( curr != NULL )
    {
      // check if actor is in this show
      if( curr -> actorName == keyActorName )
	return true;
      
      curr = curr -> next;
    }
  //check:  cout << "This should return a false" << endl;
  return false;
}

void LinkedList::AddNodeToEnd( string name )
{
  NodePtr n = new node; // initialize and allocate memory

  n -> actorName = name;

  n -> next = NULL;

  if( start == NULL ) {
    start = n;
    end = start;
  } else {
    end -> next = n;
    end = end -> next;
  }
}
/*
void LinkedList::DeleteAllNodes()
  {
    NodePtr p = start, n; // pointers to the current and previous nodes
    while (p != NULL) // while not at end of list
      {
        n = p;
        p = p -> next;
	n -> next = NULL;
        delete n; //delete first node
      }

    
//    NodePtr curr; // pointer to the current node
//    if( start != NULL )
//      {
//	curr = start;
//	start = start -> next;
//	delete curr;
//      }

  }
*/
  
/*
char LinkedList::FirstNode()
  {
    char cVal; // maze character
    if( start != NULL )
      cVal = start->info;
    return cVal;
  }
char LinkedList::LastNode()
  {
    if( end != NULL )
      return end->info;
  }
*/

void LinkedList::PrintNodes()
  {
    NodePtr p = start; // pointer to the starting node
    while( p != NULL )
      {
	cout << p -> actorName << " ";
	p = p -> next;
      }
    cout << "\n" << endl;
  }

/*
bool LinkedList::IsInList(char maze_char)
  {
    NodePtr p = start;
    while (p != NULL && maze_char != p->info)
      p = p->next;
    return (maze_char == p->info);
  }
*/

/*
int LinkedList::Size()
  {
    int count = 0; // an integer to count nodes 
    NodePtr curr = start; // a node pointer to the beginning of the list
    while( curr != NULL )
      {
	count++;
	curr = curr -> next;
      }
    return count;
  }
*/
