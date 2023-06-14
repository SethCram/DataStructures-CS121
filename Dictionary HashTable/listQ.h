/* listQ.h
 * class interface for a linked list of chars used in a queue
 *
 * CS 121.Bolden.........gcc verson 4.8.5 ...........Seth Cram
 * 3/9/2020 ......Dell & AMD Ryzen 5 2500U with Radeon Vega Mobile Gfx 2.00 GHz......cram1479@vandals.uidaho.edu
 *
 * using dynamic arrays and a queue create a maze solving program in c++
 *--------------------------------------------------------------------------
 */

#include <iostream>

using namespace std;

//global variables also global coordinates
int RIGHTNOWX = 0;
int RIGHTNOWY = 0;

class LinkedList
{
 private:
  struct node 
  {
    char info; // maze character 
    // coordinate of node enqueued into list
    int CurrX;
    int CurrY;

    node *next; // node that points to the next node
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
      NodePtr p = start, n; // pointers to the current and previous nodes 
      while (p != NULL)
	{
	  n = p;
	  p = p->next;
	  delete n;
	}
    }
  // Put a node at the end of the linked list.
  void AddNodeToEnd( char, int, int );

  // Delete the first node in the list.
  void DeleteNode();

  // Return the first or last node.
  //  char FirstNode();
  //  char LastNode();

  // Output the maze character in the nodes.
  void PrintNodes();

  // Return true if a node with the value x is in the list.
  //  bool IsInList( char );

  // Return a count of the number of nodes in the list.
  int Size();
};
