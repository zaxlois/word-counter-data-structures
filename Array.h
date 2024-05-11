#ifndef WORD_COUNTER_DATA_STRUCTURES_ARRAY_H
#define WORD_COUNTER_DATA_STRUCTURES_ARRAY_H

#include <iostream>
#include <fstream>
using namespace std;

#include "WordPair.h" // Include the necessary header files

#define InitialSize 10000 // Starting size of the array and also the increment in IncreaseCapacity()
#define PAIRS 1500

// Class that creates the general type of array and its basic functions
class Array {
protected:
    WordPair *data; // Pointer of a WordPair object;
    int maxSize; // integer variable that stores the maximum size of the array
    int elements; // integer variable that stores the current number of objects in the array
public:
    Array(); // Empty constructor for the creation of the array
    Array(int); // Single argument constructor that creates an array of custom size
    virtual void AddPair(const string &); // Function that creates and adds the pair in the array. Different implement in other classes
    void fixTable(); // Function that gets the array in the correct size and deletes the empty space
    int getElements(); // Getter for the elements
    WordPair getObject(int); // Getter for an object of the array
    virtual bool isPairIn(const string &); // Function that is searching if the pair is in the array. Different implement in the HashTable
    void insertPair(WordPair ); // Function that inserts a WordPair object in the array
protected:
    virtual void IncreaseCapacity(); // Function that increases the capacity of the array . Different implement in other classes
};


#endif //WORD_COUNTER_DATA_STRUCTURES_ARRAY_H
