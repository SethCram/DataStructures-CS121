/*
 * Seth Cram
 * 2/12/2020
 * Prog Assign #2:
 *   animals linked list
 * test_animal_linked_list.cpp (test file)
 */

#include <iostream>
#include <fstream>
using namespace std;

#include "animal_linked_list.h"


int main(){
  node *head, *temp;  // pointers to a node object
  string d_or_a[43]; // to read in the delete or add to list
  string name[43]; // to read in animal name
  int upper_bound; // both upper+lower bound used for 'for loops' to input names to functions
  int lower_bound = 0;

  ifstream obj1; 
  obj1.open("list_of_animals.txt");
  for(int i = lower_bound; i < 43; i++) // reads animal txt's that I combined into one file, stores values in arrays 
    {
      obj1 >> d_or_a[i];
      obj1 >> name[i];
    }
  // test cases for if list empty
  head -> clear(head,name[1]);
  temp = new node();    // repeat
  head -> append(head,temp);
  temp -> setdata(name[1]);


  upper_bound = 8;
  for(int i = lower_bound; i < upper_bound; i++) // add starting nodes to list
    {
      if(i == lower_bound){
	temp = new node();  // create a new node object
	temp -> setdata(name[i]); // add data
	temp -> setnext(NULL);  // make the next object Null
	head = temp;
      }else{     
	temp = new node();    
	head -> append(head,temp);  // add nodes to end of list
	temp -> setdata(name[i]);
      }
    }
 //count outputs 
 cout << "List of Members: \n"; 
 head -> print(); // prints the list
 head -> count(head,"aardvark");
 head -> count(head,"bird");
 head -> count(head,"cat");
 head -> count(head,"dog");
 head -> count(head,"hamster");
 head -> count(head,"rabbit");
 head -> count(head,"zebra \n");


 lower_bound = 8;
 upper_bound = 14;
 for(int i = lower_bound; i < upper_bound; i++)
   {
     if(d_or_a[i] == "add"){      
       temp = new node();    
       head -> append(head,temp); // adds specified nodes
       temp -> setdata(name[i]);
     }else{
       head -> clear(head,name[i]); // deletes specified nodes
     }
   }
 cout << "List of Members: \n"; //print
 head -> print();
 head -> count(head,"aardvark"); // counts
 head -> count(head,"bird");
 head -> count(head,"cat");
 head -> count(head,"dog");
 head -> count(head,"hamster");
 head -> count(head,"rabbit");
 head -> count(head,"zebra \n");


 // just rinse and repeat below
 lower_bound = 14;
 upper_bound = 18;
 for(int i = lower_bound; i < upper_bound; i++)
   {
     if(d_or_a[i] == "add"){
       temp = new node();    // repeat
       head -> append(head,temp);
       temp -> setdata(name[i]);
     }else{
       head -> clear(head,name[i]);
     }
   }

 cout << "List of Members: \n"; //print
 head -> print();
 head -> count(head,"aardvark");
 head -> count(head,"bird");
 head -> count(head,"cat");
 head -> count(head,"dog");
 head -> count(head,"hamster");
 head -> count(head,"rabbit");
 head -> count(head,"zebra \n");



 lower_bound = 18;
 upper_bound = 30;
 for(int i = lower_bound; i < upper_bound; i++)
   {
     if(d_or_a[i] == "add"){
       temp = new node();    // repeat
       head -> append(head,temp);
       temp -> setdata(name[i]);
     }else{
       head -> clear(head,name[i]);
     }
   }
 cout << "List of Members: \n"; //print
 head -> print();
 head -> count(head,"lizard");
 head -> count(head,"bird");
 head -> count(head,"cat");
 head -> count(head,"dog");
 head -> count(head,"hamster");
 head -> count(head,"rabbit");
 head -> count(head,"zebra");
 head -> count(head,"frog");
 head -> count(head,"snake");
 head -> count(head,"horse");
 head -> count(head,"dolphin \n");

 lower_bound = 30;
 upper_bound = 34;
 for(int i = lower_bound; i < upper_bound; i++)
   {
     if(d_or_a[i] == "add"){
       temp = new node();    // repeat
       head -> append(head,temp);
       temp -> setdata(name[i]);
     }else{
       head -> clear(head,name[i]);
     }
   }
 cout << "List of Members: \n"; //print
 head -> print();
 head -> count(head,"lizard");
 head -> count(head,"bird");
 head -> count(head,"cat");
 head -> count(head,"dog");
 head -> count(head,"hamster");
 head -> count(head,"rabbit");
 head -> count(head,"zebra");
 head -> count(head,"frog");
 head -> count(head,"snake");
 head -> count(head,"horse");
 head -> count(head,"dolphin \n");

 lower_bound = 34;
 upper_bound = 38;
 for(int i = lower_bound; i < upper_bound; i++)
   {
     if(d_or_a[i] == "add"){
       temp = new node();    // repeat
       head -> append(head,temp);
       temp -> setdata(name[i]);
     }else{
       head -> clear(head,name[i]);
     }
   }
 cout << "List of Members: \n"; //print
 head -> print();
 head -> count(head,"lizard");
 head -> count(head,"bird");
 head -> count(head,"cat");
 head -> count(head,"dog");
 head -> count(head,"hamster");
 head -> count(head,"rabbit");
 head -> count(head,"zebra");
 head -> count(head,"frog");
 head -> count(head,"snake");
 head -> count(head,"horse");
 head -> count(head,"dolphin \n");

 lower_bound = 38;
 upper_bound = 42;
 for(int i = lower_bound; i < upper_bound; i++)
   {
     if(d_or_a[i] == "add"){
       temp = new node();    // repeat
       head -> append(head,temp);
       temp -> setdata(name[i]);
     }else{
       head -> clear(head,name[i]);
     }
   }
 cout << "List of Members: \n"; //print
 head -> print();
 head -> count(head,"lizard");
 head -> count(head,"bird");
 head -> count(head,"cat");
 head -> count(head,"dog");
 head -> count(head,"hamster");
 head -> count(head,"rabbit");
 head -> count(head,"zebra");
 head -> count(head,"frog");
 head -> count(head,"snake");
 head -> count(head,"horse");
 head -> count(head,"dolphin \n");

}
