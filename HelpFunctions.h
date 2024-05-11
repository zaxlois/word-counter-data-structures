#ifndef WORD_COUNTER_DATA_STRUCTURES_HELPFUNCTIONS_H
#define WORD_COUNTER_DATA_STRUCTURES_HELPFUNCTIONS_H


#include <iostream>
#include <cctype>
using namespace std;



bool isPunctuation(char c) {
    return ispunct(static_cast<unsigned char>(c));//returns if a character is punctuation
}

string convert(string pair) {
    pair.erase(remove_if(pair.begin(), pair.end(), isPunctuation), pair.end());

    for (char& c : pair)
        c = tolower(c);//Converting the Upper case to lower case

    return pair;
}

string createPair(const string &first,const string &second) {
    string pair = first + " " + second;//creating the pair
    pair = convert(pair);//converting the pair to lower case
    return pair;
}

#endif //WORD_COUNTER_DATA_STRUCTURES_HELPFUNCTIONS_H
