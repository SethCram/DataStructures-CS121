/*
 * Seth Cram
 * sec #02
 * 10/25/19
 * Prog Assign #9:
 *   generic board game
 * All of the objectives should be completed, besides the additional game variable. I was able to impliment it, but never got it to work properly.
 */
#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
#include<cstdlib>
using namespace std;
// Declaration of the square class
class square{ // a square on the board
private:
  int move; 
  string message; // displlayed when landed on
  char symbol; // on board
  int limbs;
public:
  square();
  void print(); // prints the symbol
  int action(); // prints message and returns move
  int limb();
  void set(int,char,string,int); // set values for sq
};
// Function Prototypes
void print_board(square[], int, int);
void read_board(square[]);
void check_position(int &);
// Global variables
const int board_length = 20;

int main(){
  int player1_limbs = 4;
  int player2_limbs = 4;
  int current_player = 1, roll;
  int player1_position = 0, player2_position = 0;
  square the_board[board_length];  // declare an array of squares
  int choice;
  cout << "Sword drawn and ready for whatever happens next, you push on.\n";
  cout << "So far its been a cake walk and you start to consider this area too weak for you.\n";
  cout << "Type enter to walk through the giant double doors.\n";
  cin.ignore();
  cout << "Suddenly the floor falls out beneath you and you roll to the nearest rock that isn't sinking.\n";
  cout << "High above the falling landscape, you look down and discover an ocean of magma.\n";
  cout << "You look around and realize there's another player trapped here, looking just as surprised.\n";
  cout << "The door falls into the ocean...\n";
  cout << "...Its a race then.\n";
  srand(time(NULL)); // what
  read_board(the_board);
  cout << endl;
  print_board(the_board,player1_position,1);
  cout << endl;
  print_board(the_board,player2_position,2);

  do{
    cout<<"\n\n\nPlayer "<< current_player <<" type enter to roll, leap, dive, jump, hurtle, or somersault.\n";
    cin.ignore();
    if(current_player == 1){  
      if(player1_limbs == 4){
	roll = 1 + (rand() % 5);
      }
      if(player1_limbs == 3){
	roll = 1 + (rand() % 4);
      }
      if(player1_limbs == 2){
	roll = 1 + (rand() % 3);
      }
      if(player1_limbs == 1){
	roll = 1 + (rand() % 2);
      }
      if(player1_limbs == 0){
	cout << "Player " << current_player << " slowly bleeds out.\n";
	cout << "Player " << (current_player % 2) + 1 << " is teleported above ground and can't re-enter the cave despite their best efforts.\n";
	return 0;
      }
    }else{
      if(player2_limbs == 4){
        roll = 1 + (rand() % 5);
      }
      if(player2_limbs == 3){
        roll = 1 + (rand() % 4);
      }
      if(player2_limbs == 2){
        roll = 1 + (rand() % 3);
      }
      if(player2_limbs == 1){
        roll = 1 + (rand() % 2);
      }
      if(player2_limbs == 0){
        cout << "Player " << current_player << " slowly bleeds out.\n";
        cout << "Player " << (current_player % 2) + 1 << " is teleported above ground and can't re-enter the cave despite their best efforts.\n";
	return 0;
      }
    }
    if(roll == 1){
      cout << "Player "<< current_player <<" hopped to a platform. \n"<< endl;
    }
    if(roll == 2){
      cout << "Player "<< current_player <<" leapt a couple platforms. \n"<< endl;
    }
    if(roll == 3){
      cout << "Player "<< current_player <<" dove to even more than a couple platforms. \n" << endl;
    }
    if(roll == 4){
      cout << "Player "<< current_player <<" hurtled a pretty great number of platforms. \n"<< endl;
    }
    if(roll == 5){
      cout << "Player "<< current_player <<" somersaulted and springboarded like an olypmic acrobat across an insane number of platforms. \n"<< endl;
    }
    if(current_player == 1){
      player1_position += roll;
      check_position(player1_position);
      player1_position += the_board[player1_position].action(); // adds move from player's tile 
      check_position(player1_position);
      player1_limbs = player1_limbs - the_board[player1_position].limb(); // remove limbs at tile position if necessary (DOESN'T WORK)?????
      }
    else{
      player2_position += roll;
      check_position(player2_position);
      player2_position += the_board[player2_position].action(); 
      check_position(player2_position);
      player2_limbs = player2_limbs - the_board[player2_position].limb(); // remove limbs at tile posiiton if needed (DOESN'T WORK)????????
    }
    cout << endl;
    print_board(the_board,player1_position,1);
    cout << endl;
    print_board(the_board,player2_position,2); // ex: player 1 
    cout << "Player 1 has "<<  player1_limbs << " limbs left.\n";
    cout << "Player 2 has " << player2_limbs << " limbs left.\n"; 
    current_player = (current_player % 2) + 1; // ex: switches player to player 2
  }while((player1_position < board_length-1) && (player2_position < board_length-1));
  current_player = (current_player % 2) + 1; // ex: switches player back to player 1
  cout << "What will you do champion?\n";
  cout << "Secure victory (1), help your opponent (2), or play with your sword (3)\n";
  cin >> choice;
  switch(choice){
  case 1:
   cout << "\nPlayer " << current_player << " yells that they have the high ground! They whip around and rain rocks from the heavens until the other";
   cout << " player plunges into the magma below.\n";
   cout << "As player " << current_player << " approaches the giant chest on the last floating platform...\n";
   cout << "A floating message appears and displayes 'Congratulations! You've taken anothers life.'\n";
   cout << "Launched from the platform, another adventurer falls to their death, as a loud cackle is heard from the victory platform...\n";
   cout << "\n\n\nYOU DIED\n\n\n";
   cin.ignore();
   return 0;
 case 2:
   cout << "You look back at the armour clad warrior fearful of what you decide.\n";
   cout << "You search around inside the chest and find something that looks like a grappling hook gun.\n";
   cout << "You try and shoot it into the floating rock the other adventurer stands on but end up skewering him with it...\n";
   cout << "His lifeless corpse propels towards you and you don't dodge in time.\n";
   cout << "Soon enough, the two fall together into the pit.\n";
   cout << "\n\n\nYOU DIED\n\n\n";
   cin.ignore();
   return 0;
 case 3:
   cout << "You take out your entire collection of swords you've used on this character.\n";
   cout << "You like to keep them as momentos of your progress and the hardships you've overcome.\n";
   cout << "You start practicing blade art in wide arcs, dancing around, and suddenly blood explodes from behind the chest...\n";
   cout << "You grab the now visible illusionist who played this foul trick and make him release you and the other adventurer from this nightmare.\n";
   cout << "Congratulations! Both players survived!\n";
   cin.ignore();
   return 0;
  default:
    cout << "You swan dive into the magma for no aparrent reason...................nice\n";
    cin.ignore();
    return 0;
  }
}

void read_board(square b[]){ // reads in tiles, where the player is, and their character
  ifstream infile;
  infile.open("game.txt"); // opens dif file
  int square_number, square_move;
  string square_message;
  char square_symbol;
  int square_limbs;
  while(!infile.eof()){ // eof = end of file
    infile >> square_number >> square_move >> square_symbol >> square_limbs; // 3 +2 ? 0 
    getline(infile,square_message); // reads rest of line 
    if(square_number < board_length)
      b[square_number].set(square_move,square_symbol,square_message,square_limbs);
  }
}
void print_board(square b[], int player_position, int player_number){
  for(int i = 0; i < board_length; i++){
    if(i != player_position){
      cout << "  ";
      b[i].print();
    }else{
      cout << "  " << player_number;
    }
  }
  cout << "Loot\n";
  for(int i = 0; i < board_length; i++){
    if(i == 4 || i == 5){
      cout << "  ";
      cout << " ";
    }else{
      cout << "  ";
      cout << "-";
    }
  }
  cout << "\n";
}
void check_position(int &p){ // keep player in bounds
  if(p < 0)
    p = 0;
  if(p >= board_length)
    p = board_length-1;
}

// Functions of the class square
square::square(){
  symbol = ' ';
  move = 0;
  message = "";
  limbs = 0;
}
int square::action(){
  cout << message << endl;
  return move;
}
void square::print(){
  if(symbol == 'L' || symbol == 'R'){
    cout << " ";
  }else{
  cout << symbol;
  }
}
int square::limb(){
  
  return limbs;
}
void square::set(int m, char s, string a_message, int li){
  move = m;
  symbol = s;
  message = a_message;
  limbs = li;
}
