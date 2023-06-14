/* queueL.h
Interface file for the ADT queue.
Header file with a queue class
*/

#ifndef QUEUE_L_H

#define QUEUE_L_H

#include <fstream>

#include "listQ.cpp"

using namespace std;

typedef char QueueItemType; // creates new type of type char

class Queue
{
 private:
  LinkedList L; // list of queue items
  char** mazeArray; // maze array variable
  int width; // width of current maze
  int height; // height of current maze
  // maze symbols 
  const char FREE = '.';
  const char PATH = 'O';
  const char START = 'S';
  const char GOAL = 'G';
  const char BARRIER = '#';
  const char WALL = ' ';
  // starting and end coordinates
  int StartPointX, StartPointY;
  int EndPointX, EndPointY;

 public:
  // constructors
  Queue();
  Queue( const Queue& q );
  ~Queue();
  // functions
  void EnQueue( QueueItemType, int ,int ); // adds node to back of list
  void DeQueue(); // removes and deletes node from front of list 
  //  char GetFront();
  //  char GetEnd();
  bool IsEmpty(); // return whether list is empty or not
  void PrintN(); // prints out the list of nodes
  void ShowMaze(); // prints the current maze
  void StartOfNewMaze(); // scans through array and sets maze start and goal coordinates
  bool WalkMaze( bool ); // traverses the maze, returning whether solveable or not
  void Fill() // creates a 2D array, stores maze symbols in it
  {
    // allocate
    ifstream infile; // an object used to read data from external file
    int choice; // stores user input

    cout << "Which maze would you like to compute? (0,1,2,3)" << endl; // choose which maze to solve
    cin >> choice;
    if( choice == 0 )
      {
	infile.open( "maze.txt" ); // initiliaze infile obj by taking vals from maze.txt
      }
    if( choice == 1 )
      {
	infile.open( "maze1.txt" ); // initiliaze infile obj by taking vals from maze1.txt
      }
    if( choice == 2 )
      {
	infile.open( "maze2.txt" ); // initiliaze infile obj by taking vals from maze2.txt
      }
    if( choice == 3 )
      {
	infile.open( "maze3.txt" ); // initiliaze infile obj by taking vals from maze3.txt
      }

    // initialize from chosen maze file
    infile >> width;  
    infile >> height; 

    mazeArray = new char*[ height + 2 ]; // allocate memory for maze and empty borders around it
    
    for( int i = 0; i < height + 2; i++ ) // fill the 2D array
      {
	if( i == 0 || i == height + 1 ){ // border top and bot of maze with WALL's (empty space)
	  //check:  cout << i << " if statement" << endl;
	  mazeArray[ i ] = new char[ width + 2 ];

	  for( int p = 0; p < width + 2; p++ )
	    {
	      mazeArray[ i ][ p ] = WALL;
	    }

	}else{ // fill in array with maze chars
	  //check:  cout << i << " else statement " <<  endl;
	  mazeArray[ i ] = new char[ width + 2 ];
	  infile >> mazeArray[ i ];

	  for( int k = width + 1; k > -1; k-- )
	    {
	      mazeArray[ i ][ k + 1 ] = mazeArray[ i ][ k ];
	    }
	}	

      }
    for( int i = 0; i < height + 2; i++ ) // border left and right of maze with WALL's (empty space)
      {
	//check:  cout << i << " second for loop" << endl;
	mazeArray[ i ][ 0 ] = WALL;
	mazeArray[ i ][ width + 1 ] = WALL;
      }

     infile.close(); // closes opened maze file
  }  
};
#endif
