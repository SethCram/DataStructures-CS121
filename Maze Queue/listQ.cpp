/* listQ.cpp
Implementation file for a class of a sorted linked list of characters
*/
#include "listQ.h"

using namespace std;

void LinkedList::AddNodeToEnd( char maze_char, int X, int Y )
{
  NodePtr n = new node; // initialize and allocate memory
  n->info = maze_char;
  n->CurrX = X;
  n->CurrY = Y;
  n->next = NULL;
  if( start == NULL ) {
    start = n;
    end = start;
  } else {
    end->next = n;
    end = end->next;
  }
}
void LinkedList::DeleteNode()
  {
    NodePtr curr; // pointer to the current node
    if( start != NULL )
      {
	curr = start;
	start = start->next;
	RIGHTNOWX = curr->CurrX;
	RIGHTNOWY = curr->CurrY;
	delete curr;
      }
  }
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
	cout << p->info << " ";
	p = p->next;
      }
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
int LinkedList::Size()
  {
    int count = 0; // an integer to count nodes 
    NodePtr curr = start; // a node pointer to the beginning of the list
    while( curr != NULL )
      {
	count++;
	curr = curr->next;
      }
    return count;
  }
