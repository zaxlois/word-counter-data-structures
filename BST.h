#ifndef WORD_COUNTER_DATA_STRUCTURES_BST_H
#define WORD_COUNTER_DATA_STRUCTURES_BST_H

#include "TreeNode.h" // Include the necessary header file

// Class that creates a Binary Search Tree and its basic functions
class BST {
protected:
    TreeNode* root; // The root of the tree
    virtual TreeNode* insertNode(TreeNode *,WordPair *); // Function that inserts the WordPair object in the right place. Different implementation in other class
public:
    BST(); // Empty constructor that creates the tree
    void insertPair(const string &); // Function that uses insertNode to add a pair
    int search(TreeNode *,WordPair); // Searching function
    TreeNode *getRoot(); // Getter for the root
};

#endif //WORD_COUNTER_DATA_STRUCTURES_BST_H
