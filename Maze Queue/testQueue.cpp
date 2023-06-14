/* testQueue.cpp
 * Tests 
 * Includes a queue header and implementation file, a list header and implementation file
 */

#include <iostream>

using namespace std;

#include "queueL.cpp"

int main()
{
  int choice; // stores user input
  cout << "How many mazes do you wish to solve?" << endl;
  cin >> choice;
  for( int i = 0; i < choice; i++ ) 
    {
      Queue q1; // a static queue object
      q1.Fill(); // fills maze with file values + adds empty barriers around th 
      cout << "Current unsolved maze: " << endl;
      q1.ShowMaze(); // displays maze w/ barriers
      q1.StartOfNewMaze(); // sets starting value + checks if already goal
      q1.ShowMaze(); // displays current maze
    }

}
