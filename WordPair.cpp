#include "WordPair.h" // Include the header file of the class

WordPair::WordPair() {}

WordPair::WordPair(const std::string &newPair) {
    // Sets the new pair
    pair = newPair;
    counter = 1;
}

string WordPair::getPair() {return pair;} // Returns the pair

int WordPair::getCounter() {return counter;} // Returns the counter

void WordPair::IncreaseCounter() {counter++;} // Increases the counter

void WordPair::setPair() {pair = "";} // Sets the pair as empty