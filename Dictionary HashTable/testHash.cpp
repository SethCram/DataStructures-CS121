/* testHash.cpp
 * Test the Hash table code.
 */
#include <iostream>
#include <cstdlib>

#include "hash.cpp"

int main()
{
  int numOfProbes; //keeps track of total number of probes used

  // Put values from both dictionaries in the table...
  storeDictionary();
  
  // print out all names and definitions in the hash table
  //  PrintHashTable();

  // prints number of words per bucket
  numOfWordsPerBucket();

  // prints out the min and max number of words that a bucket has 
  minMaxInaBucket();

  // search for ten words in the hash table, display number of probes total
  numOfProbes = 
      numOfProbesLookup( "zoomania" ) + numOfProbesLookup( "cleg" )
    + numOfProbesLookup( "Dyssodia" ) + numOfProbesLookup( "echinid" )
    + numOfProbesLookup( "panne" ) + numOfProbesLookup( "Gil" )
    + numOfProbesLookup( "unark" ) + numOfProbesLookup( "abigeus" )
    + numOfProbesLookup( "vagas" );
  cout << numOfProbes 
       << " probes required to find the words: zoomania, cleg, Dyssodia,"
       << "\n echinid, panne, unark, abigeus and vagas in a size " 
       << HASH_TABLE_SIZE  << " hash table." << endl;

  // displays how many empty buckets there are in hash table
  cout << "There are " << numOfEmptyBuckets() << " empty buckets." << endl;

  //test:   char testStr[] = "Aaru";
  //test:   Lookup( testStr );

  return EXIT_SUCCESS;

}
