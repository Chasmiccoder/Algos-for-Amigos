/*
Problem:
https://codeforces.com/problemset/problem/1325/B

===============
Spoilers Ahead!
===============

The answer is the same as the number of unique numbers
Just use a set if coding in c++
Since we're in C, we need to implement our own hash table that keeps tracks of elements
and their frequencies.

We've used a simple modulo Hash Function, coupled with Linear Probing
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


struct Element {
    int key;   // Number
    int value; // Frequency
};


int hashFunction(int key, int size) {
    return key % size;
}


void insert(struct Element **hashTable, int key, int value, int size) {
    
    struct Element *e = (struct Element*) malloc(sizeof(struct Element));
    e->key = key;
    e->value = value;

    int index = hashFunction(key, size);

    while ( hashTable[index] != NULL ) {
        index++;
        index = index % size;
    }

    hashTable[index] = e;
}


struct Element* search(struct Element **hashTable, int key, int size) {

    int index = hashFunction(key,size);

    while( hashTable[index] != NULL ) {
        

        if ( hashTable[index]->key == key ) {
            
            return hashTable[index];
        }

        index++;
        index = index % size;
    }
    return NULL;
}


void update(struct Element **hashTable, int key, int value, int size) {
    int index = hashFunction(key,size);
    while( hashTable[index] != NULL ) {
        if( hashTable[index]->key == key ) {
            hashTable[index]->value = value;
            return;
        }
        index++;
        index = index % size;
    }

    // Key not found
    return;
}


int findNextPrime(int n) {
    /*
    Return the first prime number that is equal to or greater than n
    */
    
    for(int i = 2; i <= (int)pow(n,0.5) + 1; i++ ) {
        if ( n % i == 0 ) {
            // Try the next number, since n is not prime
            return findNextPrime(n+1);
        }
    }

    // Found a prime!
    return n;
}

int numUnique(struct Element **hashTable, int size) {
    int count = 0;
    for ( int i = 0; i < size; i++ ) {
        if ( hashTable[i] != NULL ) {
            count++;
        }
    }
    return count;
}


int main() {

    int testcases;
    scanf("%d", &testcases);
    for ( int t = 0; t < testcases; t++ ) {

        int n;
        scanf("%d", &n);

        // It is ideal to set the size of the hash table to a prime number
        int size = findNextPrime(n);

        // Initialize the Hash Table
        struct Element **hashTable;
        
        hashTable = (struct Element**)malloc( size * sizeof(struct Element*) );

        for ( int i = 0; i < size; i++ ) {
            struct Element *e = NULL;
            hashTable[i] = e;
        }

        // Insert values into the table
        for ( int i = 0; i < n; i++ ) {
            int num;
            scanf("%d", &num);

            struct Element *e = search(hashTable,num,size);

            // Not present in the table
            if ( e == NULL ) {
                insert(hashTable,num,0,size);
            }
            // Update the table if key is present
            else {
                update(hashTable,num,e->value+1,size);
            }
        }
        
        int unique = numUnique(hashTable,size);
        printf( "%d\n", unique);
        
    }
    return 0;
}