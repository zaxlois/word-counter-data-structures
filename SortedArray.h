#ifndef WORD_COUNTER_DATA_STRUCTURES_SORTEDARRAY_H
#define WORD_COUNTER_DATA_STRUCTURES_SORTEDARRAY_H

#include "Array.h" // Include the necessary header files

// Derived class that creates a sorted array with the functions of the base class
class SortedArray : public Array {
public:
    SortedArray(); // Empty constructor for the creation of the array
    int BinarySearch(WordPair); // Function that searches the pair in the array
    void AddPair(const string &) override; // Function that creates and adds the pair in the correct place of the array. Different implementation from the base class
    void swap(WordPair &,WordPair &); // Helping function that swaps the place of 2 objects in the array
    int partition(int,int); // Helping function that swap the places of the objects so the array is sorted
    void QuickSort(int,int); // Sorting function of the array
};


#endif //WORD_COUNTER_DATA_STRUCTURES_SORTEDARRAY_H
