#ifndef WORD_COUNTER_DATA_STRUCTURES_HASHTABLE_H
#define WORD_COUNTER_DATA_STRUCTURES_HASHTABLE_H

#include "Array.h"//Include the neccesary header files

class HashTable : public Array {
private:
    void IncreaseCapacity() override;//Function that increases the capacity of the hash table
    int Hash(const string&);//Hash Funtion

public:
    HashTable();//Default Constructor
    int search(WordPair);//Funtion that search for the WordPair in the hash table
    void AddPair(const string &) override;//Function that adds a pair to the hash table
    bool isPairIn(const string &) override;//function that checks if a pair is already in the hash table
};


#endif //WORD_COUNTER_DATA_STRUCTURES_HASHTABLE_H
