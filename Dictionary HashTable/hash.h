/* hash.h
 * 
 * CS 121.Bolden.........gcc verson 4.8.5 ...........Seth Cram
 * 5/5/2020 ......Dell & AMD Ryzen 5 2500U with Radeon Vega Mobile Gfx
 * 2.00 GHz......cram1479@vandals.uidaho.edu
 *
 * *Objective: Examine/explore the effect of the loading factor (λ) 
                on a hash table.*
 * *Description: Hash table that stores 2 dictionaries using open hashing*
 * *List of objectives:
 * * 3. Modify the code as necessary to store the contents of a dictionary 
         in the hash table.
   * 4. Instrument/Modify the code to display how many words are stored in           each bucket (linked list associated with a hash table location).
   * 5. Instrument/Modify the code to display the minimum and maximum                number of values stored in the buckets.
   * 6. Instrument/Modify the code to search for at least ten words in the
         hash table. How many probes are required?
   * 7. Examine effects of the size of the hash table for the following              values: 8017, 11037, and 49957.
          • Repeat steps 4–6.
          • How many (if any) empty buckets are there.*
 * Hash table interface file
 *---------------------------------------------------------------------
 */
#ifndef HASH_H
#define HASH_H

using namespace std;

struct nList /* table entry: */
{
  char *name; /* defined name */
  char *defn; /* replacement text */

  struct nList *next; /* next entry in chain */
};
typedef struct nList *NListPtr;

unsigned Hash( char *s );

NListPtr Lookup( char *s );

NListPtr Insert( char *name, char *defn );

void PrintHashTable();

void storeDictionary();

void numOfWordsPerBucket();

void minMaxInaBucket();

int numOfProbesLookup( char *s );

int numOfEmptyBuckets();

#endif /* HASH_H */
