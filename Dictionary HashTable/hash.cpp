/* hash.cpp
 *
 * Hash table implementation originally from:
 * Kernighan & Ritchie, The C Programming Language,
 * Second Edition, Prentice-Hall, 1988.
 * Adaption by Seth Cram
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <fstream>

#include "hash.h"

// change hash table size for objective 7 (for different output files)
const int HASH_TABLE_SIZE = 101; //used for hashOutput.txt
// const int HASH_TABLE_SIZE = 8017; //used for hashOutputObj7.1.txt
// const int HASH_TABLE_SIZE = 11037; //used for hashOutputObj7.2.txt
// const int HASH_TABLE_SIZE = 49957; //used for hashOutputObj7.3.txt

const int CHAR_MAX = 255; //constant for maximum char value

const int INT_MAX = 2147483647; //constant for max int value

static NListPtr hashTable[ HASH_TABLE_SIZE ];

// Prototypes
//char *strdup( const char * ); // in string.h, but....

/* Hash
 * Generate hash value for string s (isn't always unique)
 */
unsigned Hash( char *s )
{
  unsigned hashVal;

  for( hashVal = 0; *s != '\0'; s++ )
    hashVal = *s + 31 * hashVal; // how hash value calculated

  return hashVal % HASH_TABLE_SIZE; // makes sure hash value in table
}

/* Lookup
 * Look for s in hashTable
 */
NListPtr Lookup( char *s )
{
  NListPtr np;
  for( np = hashTable[Hash(s)] ; np != NULL ; np = np -> next )
    {
      if( strcmp(s, np -> name) == 0 )
	{
	  return np; // found
	}
    }
  return NULL; // not found
}

/* Insert
 * Put (name, defn) in hash table
 */
NListPtr Insert( char *name, char *defn )
{
  unsigned hashVal;
  NListPtr np;
  if( (np = Lookup(name)) == NULL ) // not found
    {
      np = (NListPtr) malloc(sizeof(*np));
      if( np == NULL || (np -> name = strdup(name)) == NULL )
	return NULL;
      hashVal = Hash(name);
      np -> next = hashTable[hashVal];
      hashTable[hashVal] = np;
    }
  else
    { // remove previous definition
      free( (void *)np -> defn );
    }
  if( (np -> defn = strdup(defn)) == NULL )
    return NULL;
  return np;
}

/* PrintHashTable
 * Print the hash table contents and their hash value
 */
void PrintHashTable()
{
  NListPtr np;
  cout << "Hash table contents:" << endl;
  cout << "--------------------\n" << endl;
  for( int i = 0 ; i < HASH_TABLE_SIZE ; i++ ) // i = hash table number
    {
      np = hashTable[i];
      while( np != NULL )
	{
	  // added for clarity
	  cout << "Hash value: " << setw(3) << i;
	  cout << "\t Name: " << np -> name;
	  cout << "\t Definition: " << np -> defn << endl;

	  np = np->next;
	}
    }
}

/* strdup
 * Make a duplicate copy of s
 */
char *strdup( const char *s )
{
  char *p;
  p = (char *)malloc(strlen(s)+1); /* +1 for ’\0’ */
  if( p != NULL )
    strcpy(p,s);
  return p;
}

/* storeDictionary
 * Stores 2 dictionaries of words and their definitions in a hash table
 */
void storeDictionary()
{
  char str[ CHAR_MAX ]; //length of word unkown so designates maximum number
                        // of chars
  fstream inFile; //object to read in info from file

  inFile.open( "dict4.txt" ); //opens file, reads in file to object
  cout << "File dict4 is open" << endl; //check

  while( inFile.is_open() )
    {
      //check:      cout << "File is still  open" << endl;
      if( inFile.eof() == 1 ) //if at end of file, close file and break loop
        {
          inFile.close();
          cout << "File closed" << endl;
          break;
        }
      inFile >> str;
      
      (void)Insert( str , "dict4" ); //dict4 is placeholder for 
                                     // dictionary defs
      //check:      cout << "Inserted " << str << endl;
      
    }
  //repeat above read in process for next file
  inFile.open( "dict8.txt" );
  cout << "File dict8 is open" << endl;

  while( inFile.is_open() )
    {
      //check:      cout << "File is still  open" << endl;
      if( inFile.eof() == 1 ) // checks if at end of file
        {
          inFile.close();
          cout << "File closed" << endl;
          break;
        }
      inFile >> str;

      (void)Insert( str , "dict8" ); //dict8 is placeholder for 
                                     //dictionary defs
      //check:      cout << "Inserted " << str << endl;

    }

}

/* numOfWordsPerBucket
 * Displays how many words are stored in each bucket
 */
void numOfWordsPerBucket()
{
  NListPtr np; //linked list object
  int count = 0; //counts words in a bucket

  for( int i = 0 ; i < HASH_TABLE_SIZE ; i++ ) // i = hash table number
    {
      np = hashTable[i];
      while( np != NULL ) //goes thru bucket if there is one
        {
	  //check:          cout << "Hash value: " << setw(3) << i;
	  //check:          cout << "\t Name: " << np -> name << endl;

	  count++; 	  

          np = np->next; // goes to next word in bucket
        }
      cout << count << " words in bucket " << i << endl;
      count = 0; // reset count for next bucket
    }
}

/* minMaxInaBucket
 * Displays the minimum and maximum number of values stored in the buckets
 */
void minMaxInaBucket()
{
  NListPtr np;
  int count = 0;
  int min = INT_MAX; //uses max int to make sure the min is a table value
  int max = 0;

  for( int i = 0 ; i < HASH_TABLE_SIZE ; i++ ) // i = hash table number
    {
      np = hashTable[i];
      while( np != NULL ) //goes thru bucket if there is one
        {
          count++;
          np = np->next;
        }

      if( count > max ) //check if current bucket has more items than max
	max = count;

      if( count < min ) //check if current bucket has less items than min
	min = count;

      count = 0; // reset count for next bucket
    }

  cout << "Minimum number of values stored in a single bucket: " 
       << min << endl;

  cout << "Maximum number of values stored in a single bucket: "
       << max << endl;

}

/* numOfProbesLookup
 * Search for a word in the hash table,
 *  return the number of probes needed to find it
 */
int numOfProbesLookup( char *s )
{
  NListPtr np;
  int count = 0; //keeps track of number of probes per bucket
  for( np = hashTable[Hash(s)] ; np != NULL ; np = np->next )
    {
      if( strcmp(s, np -> name) == 0 )
        {
          return count; // found
       }
      count++; //a probe is used
    }
  return 0; // not found
}

/* numOfEmptyBuckets
 * Returns how many (if any) empty buckets there are.
 */
int numOfEmptyBuckets()
{
  NListPtr np;
  int probeCount = 0; //keeps track of probes per bucket
  int bucketCount = 0; //keeps track of empty buckets in whole table

  for( int i = 0 ; i < HASH_TABLE_SIZE ; i++ ) // i = hash table number
    {
      np = hashTable[i];
      while( np != NULL ) //goes thru bucket if there is one here
        {
	  probeCount++;
          np = np -> next;
        }
      if( probeCount == 0 ) //checks if empty bucket
	{
	  bucketCount++; //adds 1 if current bucket empty
	}
      probeCount = 0; // reset count for next bucket
    }
  return bucketCount;
}
