#ifndef WORD_COUNTER_DATA_STRUCTURES_TREENODE_H
#define WORD_COUNTER_DATA_STRUCTURES_TREENODE_H

#include "WordPair.h" // Include the necessary header file

// Helping class that creates a node for the binary search tree
class TreeNode {
public:
    WordPair *data; // Pointer of a WorPair object
    TreeNode *left; // Pointer of a TreeNode object
    TreeNode *right; // Pointer of a TreeNode object

    TreeNode(WordPair*); // Single argument Constructor that creates a node and inserts the Wordpair object in it
};


#endif //WORD_COUNTER_DATA_STRUCTURES_TREENODE_H
