#ifndef WORD_COUNTER_DATA_STRUCTURES_UNSORTEDARRAY_H
#define WORD_COUNTER_DATA_STRUCTURES_UNSORTEDARRAY_H

#include "Array.h" // Includes the necessary header files

// Derived class of the base class Array the creates an unsorted array
class UnsortedArray : public Array {
public:
    UnsortedArray(); // Empty Constructor that creates the array
    int SequentialSearch(WordPair); // Function that searches the pairs in the array
    void AddPair(const string &) override; // Function that creates and adds a pair in the array. Different implementation from the base class
};


#endif //WORD_COUNTER_DATA_STRUCTURES_UNSORTEDARRAY_H
