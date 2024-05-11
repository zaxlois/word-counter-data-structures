#ifndef WORD_COUNTER_DATA_STRUCTURES_WORDPAIR_H
#define WORD_COUNTER_DATA_STRUCTURES_WORDPAIR_H


#include <iostream>
using namespace std;

//Class that creates a pair and stores how many times is found in the text
class WordPair {
private:
    string pair; // The pair that is stored in the object
    int counter; // Value of how many times the pair is in the text
public:
    WordPair(); // Empty constructor for creation of an array
    WordPair(const string &); // Single Argument constructor that creates an object
    string getPair(); // Getter for the pair
    int getCounter(); // Getter for the counter
    void IncreaseCounter(); // Function that increases counter
    void setPair(); // Setter for the pair
};

#endif //WORD_COUNTER_DATA_STRUCTURES_WORDPAIR_H
