#ifndef WORD_COUNTER_DATA_STRUCTURES_AVL_H
#define WORD_COUNTER_DATA_STRUCTURES_AVL_H


#include "BST.h" // Include the necessary header file

// Derived class that creates an AVL tree with the basic functions of the base class BST
class AVL : public BST {
private:
    TreeNode *insertNode(TreeNode *,WordPair *); // Function that inserts the object in the correct place of the tree. Different implementation from the base class
public:
    AVL(); // empty constructor for the creation of the tree. Same as base class BST()
    int height(TreeNode *); // Finds the height of the tree
    int difference(TreeNode *); // Finds the difference of the left and right subtrees heights
    TreeNode *RightRight_Rotate(TreeNode *); // Rotates the tree 2 times right
    TreeNode *LeftLeft_Rotate(TreeNode *); // Rotates the tree 2 times left
    TreeNode *RightLeft_Rotate(TreeNode *); // Rotates the tree first right then left
    TreeNode *LeftRight_Rotate(TreeNode *); // Rotates the tree first left then right
    TreeNode *balance(TreeNode *); // Function that balances the tree from the correct rotates
};

#endif //WORD_COUNTER_DATA_STRUCTURES_AVL_H
