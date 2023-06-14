/* listT.h
 * class interface for a linked list of strings used in a TV show Database
 *
 * CS 121.Bolden.........gcc verson 4.8.5 ...........Seth Cram
 *   4/18/2020 ......Dell & AMD Ryzen 5 2500U with Radeon Vega Mobile Gfx 
 *   2.00 GHz......cram1479@vandals.uidaho.edu
 * Objective:
 *   store info for a TV show database using a BST in c++
 *--------------------------------------------------------------------------
 */

//file guards
#ifndef _LISTT_H_
#define _LISTT_H_

#include <iostream>

using namespace std;


class LinkedList
{
 private:
  struct node 
  {
    string actorName; // one of the actor names in a specific movie

    node *next; // nodePtr that points to the next node
  };
  typedef node *NodePtr;
  NodePtr start; // pointer to front of list
  NodePtr end; // pointer to end of list

 public:
  // Constructor
  LinkedList()
    {
      start = NULL;
      end = start;
    }
  // Destructor
  ~LinkedList()
    {
      /*
      NodePtr p = start, n; // pointers to the current and previous nodes 
      while (p != NULL)
	{
	  n = p;
	  p = p->next;
	  delete n;
	}
      */
    }
  // Looks through list for a keyword
  bool SearchList( string keyActorName );
  // Put a node at the end of the linked list.
  void AddNodeToEnd( string );

  // Delete every node in the list.
     //  void DeleteAllNodes();

  // Return the first or last node.
     //  char FirstNode();
     //  char LastNode();

  // Output the actor names in the list of nodes.
  void PrintNodes();

  // Return true if a node with the value x is in the list.
     //  bool IsInList( char );

  // Return a count of the number of nodes in the list.
     // int Size();
};
#endif
