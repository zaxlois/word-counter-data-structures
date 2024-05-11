#ifndef WORD_COUNTER_DATA_STRUCTURES_STRUCTUREFUNCTIONS_H
#define WORD_COUNTER_DATA_STRUCTURES_STRUCTUREFUNCTIONS_H

#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

// Include the necessary headet files
#include "HelpFunctions.h"
#include "Array.h"
#include "UnsortedArray.h"
#include "SortedArray.h"
#include "BST.h"
#include "AVL.h"
#include "HashTable.h"


// Function that creates the array with the random pairs for the search
Array CreateRandomTable(const string &filename) {
    // Creates an array with all the pairs of the file and opens the file to read all the pairs
    Array pairs;

    ifstream in;
    in.open(filename,ios::in);

    if (in.is_open()) {
        string previous,current;
        in >> previous;
        while (!in.eof() && in >> current) {
            string pair = createPair(previous,current); // creates the pair
            pairs.AddPair(pair); // adds the pair to the array
            previous = current;
        }
    }
    pairs.fixTable();

    Array random(PAIRS); // creates the array of random pairs

    //random gereates an index
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < PAIRS; i++) {
        int randomIndex = rand() % pairs.getElements();
        random.insertPair(pairs.getObject(randomIndex)); // inserts the pair
    }
    in.close();

    return random; //retruns the random array
}

//Function that creates the unsorted array
UnsortedArray CreateUnsortedTable(const string & in_filename,const string & out_filename) {
    //opens the file and creates the array
    ifstream  in;
    UnsortedArray table;
    in.open(in_filename,ios::in);
    if (in.is_open()) {
        clock_t start,finish;
        string previous,current;

        start = clock();

        in >> previous;
        while (!in.eof() && in >> current) {
            string pair = createPair(previous,current);
            if (!table.isPairIn(pair)) {
                table.AddPair(pair);
            }
            previous = current;
        }
        table.fixTable();

        finish = clock();

        in.close();

        double elapsed = double (finish - start) / CLOCKS_PER_SEC;

        ofstream out;
        out.open(out_filename,ios::out);
        if (out.is_open()) {
            out << "Unsorted Table created in : " << elapsed << " seconds" << endl; // prints the time for the creation of the array
            out.close();
        }
    }
    return table; // returns the unsorted array
}

//Function that saerches the random pairs in unsorted array
void UnsortedSearch(UnsortedArray &table,Array pairs,const string & filename) {
    //opens the file and searches the pairs
    ofstream out;
    out.open(filename, ios::app);
    if (out.is_open()) {
        clock_t start, finish;

        start = clock();
        //prints the results for the pairs
        for (int i = 0; i < PAIRS; i++) {
            out << "Pair { " << pairs.getObject(i).getPair() << " } was found "
                << table.SequentialSearch(pairs.getObject(i)) << " times" << endl;
        }
        finish = clock();

        double elapsed = double(finish - start) / CLOCKS_PER_SEC;
        out << endl << "Random pairs in Unsorted Array found in : " << elapsed << " seconds" << endl << endl;

        out.close();
    }
}

//function that creates the sorted array
SortedArray CreateSortedArray(const string & in_filename,const string & out_filename) {
    //opens the file and creates the array
    SortedArray table;
    ifstream in;
    in.open(in_filename,ios::in);
    if (in.is_open()) {
        clock_t start,finish;
        string previous,current;

        start = clock();

        in >> previous;
        while (!in.eof() && in >> current) {
            string pair = createPair(previous,current);
            if (!table.isPairIn(pair)) {
                table.AddPair(pair);
            }
            previous = current;
        }
        table.fixTable();
        table.QuickSort(0,table.getElements() - 1); // sorting the array

        finish = clock();

        in.close();

        double elapsed = double (finish - start) / CLOCKS_PER_SEC;

        ofstream out;
        out.open(out_filename,ios::app);
        if (out.is_open()) {
            out << "Sorted Table created in : " << elapsed << " seconds" << endl; // prints the time for the creation of the array
            out.close();
        }
    }
    return table;
}

//function that searches the random pairs in sorted array
void SortedSearch(SortedArray &table,Array &pairs,const string &filename) {
    // opens the file and searches the pairs
    ofstream out;
    out.open(filename,ios::app);
    if (out.is_open()) {
        clock_t start,finish;

        start = clock();
        //prints the results of the pairs
        for (int i = 0; i < PAIRS; i++) {
            out << "Pair { " << pairs.getObject(i).getPair() << " } was found " << table.BinarySearch(pairs.getObject(i)) << " times" << endl;
        }
        finish = clock();

        double elapsed = double (finish - start) / CLOCKS_PER_SEC;
        out << endl << "Random pairs in Sorted Array found in : " << elapsed << " seconds" << endl;

        out.close();
    }
}

//function that creates a binary search tree
BST CreateBST(const string & in_filename,const string & out_filename) {
    //opens thefile and creates the tree
    BST tree;
    ifstream in;
    in.open(in_filename,ios::in);
    if (in.is_open()) {
        clock_t start,finish;
        string previous,current;

        start = clock();

        in >> previous;
        while (!in.eof() && in >> current) {
            string pair = createPair(previous,current);
            tree.insertPair(pair);
            previous = current;
        }

        finish = clock();

        in.close();

        double elapsed = double (finish - start) / CLOCKS_PER_SEC;

        ofstream out;
        out.open(out_filename,ios::app);
        if (out.is_open()) {
            out << "Binary Search Tree created in : " << elapsed << " seconds" << endl << endl; // prints the time for the creation of the tree
            out.close();
        }
    }
    return tree;
}

//function that searches the random pairs in the binary search tree
void BSTsearch(BST &tree,Array &pairs,const string & filename) {
    //opens the file and searches the pais
    ofstream out;
    out.open(filename,ios::app);
    if (out.is_open()) {
        clock_t start,finish;

        start = clock();
        //prints the result of the pairs
        for (int i = 0; i < PAIRS; i++) {
            out << "Pair { " << pairs.getObject(i).getPair() << " } was found " << tree.search(tree.getRoot(),pairs.getObject(i)) << " times" << endl;
        }
        finish = clock();
        out << endl;
        double elapsed = double (finish - start) / CLOCKS_PER_SEC;
        out << endl << "Random pairs in Binary Search Tree found in : " << elapsed << " seconds" << endl;

        out.close();
    }
}

//function that creates an avl tree
AVL CreateAVL(const string & in_filename,const string & out_filename) {
    //opens the file and creates the tree
    AVL tree;
    ifstream in;
    in.open(in_filename,ios::in);
    if (in.is_open()) {
        clock_t start,finish;
        string previous,current;

        start = clock();

        in >> previous;
        while (!in.eof() && in >> current) {
            string pair = createPair(previous,current);
            tree.insertPair(pair);
            previous = current;
        }

        finish = clock();

        in.close();

        double elapsed = double (finish - start) / CLOCKS_PER_SEC;

        ofstream out;
        out.open(out_filename,ios::app);
        if (out.is_open()) {
            out << "AVL Tree created in : " << elapsed << " seconds" << endl; // prints the time of the creation of the tree
            out.close();
        }
    }
    return tree;
}

//function that searches the random pairs in avl tree
void AVLsearch(AVL &tree,Array &pairs,const string & filename) {
    //opens the file and searches the pairs
    ofstream out;
    out.open(filename,ios::app);
    if (out.is_open()) {
        clock_t start,finish;

        start = clock();
        //prints the results of the pairs
        for (int i = 0; i < PAIRS; i++) {
            out << "Pair { " << pairs.getObject(i).getPair() << " } was found " << tree.search(tree.getRoot(),pairs.getObject(i)) << " times" << endl;
        }
        finish = clock();
        out << endl;
        double elapsed = double (finish - start) / CLOCKS_PER_SEC;
        out << endl << "Random pairs in AVL tree found in : " << elapsed << " seconds" << endl;

        out.close();
    }
}

//function that creates a hashtable array
HashTable CreateHashTable(const string & in_filename, const string & out_filename) {
    //opens the file and creates the array
    HashTable table;
    ifstream in;
    in.open(in_filename,ios::in);
    if (in.is_open()) {
        clock_t start,finish;
        string previous,current;

        start = clock();

        in >> previous;
        while(!in.eof() && in >> current) {
            string pair = createPair(previous, current);
            if (!table.isPairIn(pair)) {
                table.AddPair(pair);
            }
            previous = current;
        }

        finish = clock();

        in.close();

        double elapsed = double (finish - start) / CLOCKS_PER_SEC;

        ofstream out;
        out.open(out_filename,ios::app);
        if (out.is_open()) {
            out << "Hash Table created in : " << elapsed << " seconds" << endl; // prints the time for the creation of the array
            out.close();
        }
    }
    return table;
}

//function that saerches the randmon pairs in the hashtable
void HashTableSearch(HashTable &table,Array &pairs,const string & filename) {
    //opens the file and searches the pairs
    ofstream out;
    out.open(filename,ios::app);
    if (out.is_open()) {
        clock_t start,finish;

        start = clock();
        //prints the results of the pairs
        for (int i = 0; i < PAIRS; i++) {
            out << "Pair { " << pairs.getObject(i).getPair() << " } was found " << table.search(pairs.getObject(i)) << " times" << endl;
        }
        finish = clock();

        double elapsed = double (finish - start) / CLOCKS_PER_SEC;
        out << endl << "Random pairs in Hsh Table found in : " << elapsed << " seconds" << endl;

        out.close();
    }
}
#endif //WORD_COUNTER_DATA_STRUCTURES_STRUCTUREFUNCTIONS_H
