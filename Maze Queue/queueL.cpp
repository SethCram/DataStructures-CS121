/* queueL.cpp
This implementation file uses a list.
*/

#include "queueL.h"

using namespace std;

Queue::Queue()
{
  // default constructor
}
Queue::Queue( const Queue &q ) : L(q.L)
{
  // copy constructor
}
Queue::~Queue()
{
  // destructor
}
void Queue::EnQueue( QueueItemType newItem, int X, int Y )
{    
  L.AddNodeToEnd( newItem, X, Y ); // adds node to list
}
void Queue::DeQueue()
{
  // char cVal;
  //  cVal = L.FirstNode();
  L.DeleteNode();
  //  return cVal;
}

/*
char Queue::GetFront()
{
  L.FirstNode();
}
char Queue::GetEnd()
{
  return L.LastNode();
}
*/

bool Queue::IsEmpty()
{
  int length = L.Size(); // stores length of list
  return bool(length == 0 );
}
void Queue::PrintN()
{
  L.PrintNodes();
}
void Queue::ShowMaze() 
{
  for(int i = 0; i < height + 2; i++)
    {
      for(int j = 0; j < width + 2; j++)
	{
	  cout << mazeArray[ i ][ j ];
	}
      cout << endl;
    }
}
bool Queue::WalkMaze( bool empty ) // solves the maze
{
  DeQueue(); // remove and deletes first node in list 

  //  sets current coordinates to the dequeued node's coordinates
  int X = RIGHTNOWX;
  int Y = RIGHTNOWY;

  mazeArray[ Y ][ X ] = PATH; // marks place as visited with an 'O'
  
  //check:  cout << "Insanity? " << RightNowX << ", " << RightNowY << endl;
  //check:  ShowMaze();
  //check:  PrintN();
    if ( X + 1 == EndPointX || Y + 1 == EndPointY || X - 1 == EndPointX || Y - 1 == EndPointY ) // checks if currently next to goal
      {
	if( X == EndPointX || Y == EndPointY )
	  {
	    return true;
	  }
      }
    
    if( X > 1 && mazeArray[ Y ][ X - 1 ] == FREE ) // adds node to the left if moveable spot '.'
      {
	EnQueue( mazeArray[ Y ][ X - 1 ], X - 1, Y );
      }
    
    if ( X < width+2 && mazeArray[ Y ][ X + 1 ] == FREE ) // adds node to right if moveable spot '.'
      {
	EnQueue( mazeArray[ Y ][ X + 1 ], X + 1, Y );
      }
    if ( Y > 1 && mazeArray[ Y - 1 ][ X ] == FREE ) // adds node below if moveable spot '.'
      {
	EnQueue( mazeArray[ Y - 1 ][ X ], X, Y - 1 );
      }
    if ( Y < height + 2 && mazeArray[ Y + 1 ][ X ] == FREE ) // adds node above if moveable spot '.'
      {
	EnQueue( mazeArray[ Y + 1 ][ X ], X, Y + 1 );
      }

    //check:    PrintN();
    if( IsEmpty() == true ) // checks for empty list, so if maze unsolveable
      {
	empty = true;
      }
    if( empty == true ) // if the list is empty, stop recursing bc unsolveable
      {
	return false;
      }
    if( WalkMaze( empty ) == true ) // recursively iterates until finds goal  
      {
	//check:      ShowMaze();
	return true;
      }

    //erase faulty paths:    
    //    mazeArray[Y][X] = FREE;
    //    return false;
   
}

void Queue::StartOfNewMaze()
{
  bool empty = false; // variable to represent whether list empty or not 
  
  //check for IsEmpty():
  //  if(IsEmpty() == true)
  //  {
  //   cout << "List is empty" << endl;
  //  }

  // reads in start coordinates and end coordinates
  for( int i = 0; i < height + 2; i++ ){

    for( int j = 0; j < width + 2; j++ ){

      if( mazeArray[i][j] == START ){
        StartPointX = j;
        StartPointY = i;

	//check:        cout << "Start Coords: " << StartPointX << "," << StartPointY << endl;
      }
      if( mazeArray[ i ][ j ] == GOAL ){
        EndPointX = j;
        EndPointY = i;
	//check:       cout << "End Coords: " << EndPointX << "," << EndPointY << endl;
      }
    }
  }

  EnQueue( mazeArray[ StartPointY ][ StartPointX ], StartPointX, StartPointY ); // add the starter node to the queue

  if( WalkMaze( empty ) == true ) // checks if maze solved
    {
      cout << "Maze: Solved" << endl;
    }
  else // otherwise fails to solve maze 
    {
      cout << "Mission failed...maze unsolveable" << endl;
    }
  cout << "Visited spaces marked below with O :" << endl;
}

	
	


