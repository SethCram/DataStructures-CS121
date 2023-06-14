/*
 * Seth Cram
 * 2/12/2020
 * Prog Assign #2:
 *   animals linked list
 * animal_linked_list.h (interface+implementation file)
 */
#include<iostream>
#include<string>
using namespace std;

class node{
 private:
  node *next;
  string animal_name;
 public:
  void setnext(node *n){next = n;} // sets next node in main
  void setdata(string); // sets the animal names in main
  void print(); // prints list
  void append(node *,node *); // adds a node onto the end
  void clear(node *,string); // deletes the specified node
  void count(node *, string);  //returns count of number of an animal in list
};

void node::append(node *head,node *n){ // add an animal node to end, if empty list first node done in main then append called
  if(head == NULL)
    {
      cout << "Empty list, give it a node first" << endl; //check for empty list
    
    }else{
  
      if(next != NULL){
        next -> append(head,n);
      }else{
        next = n;
        n -> next = NULL;
      }
    }
}



void node::setdata(string name){ // can set data from main
  animal_name = name;
}

void node::clear(node *head,string name){ // deletes specified node
  node *prev,*cur;
  if(head == NULL){ // checks for empty list

    cout << "Empty List, can't delete an animal that isn't there" << endl;

  }else{

    prev = head;
    cur = head;

    while(cur != NULL && cur -> animal_name != name){ //traverses list

      prev = cur;
      cur = cur->next;

    }    
    if(cur == NULL){ // case for name not being in list
      
      cout << "Failed to delete member because " << name << " not in list \n"; 
      
    }else{
      if(cur != NULL)
      {
	if(cur == prev){
	  head = cur->next;      // moves head to next node 
	  
	}else{
	  prev->next = cur->next;        // pointer of prev node moves to current node to keep list linked
	}

	cur->next == NULL; // deletes pointer to next node
	delete cur;         // deletes this node
	cout << name << " deleted" << endl;
      }
    }
  }
}


void node::print(){ // prints animal list
  cout << animal_name << endl;
  if(next != NULL)  // walks to end of list
    next -> print();
}

void node::count(node *head, string name){ // counts up and outputs number of each animal
  node *cur = head;
  int counter = 0;

  while(cur != NULL){ // walks to end of list, but doesn't come back since recursion not used
    if(cur -> animal_name == name){

      counter++;

    }

    cur = cur -> next; 

  }

  cout << counter << " " << name << endl;
  
}


