#include "AVL.h" // Include the header file of the class

TreeNode * AVL::insertNode(TreeNode *node, WordPair *pair) {
    // if the node is empty insert the pair
    if (node == nullptr)
        return new TreeNode(pair);

    if (pair -> getPair() < node -> data -> getPair()) {
        // if the pair in the node is greater than the pair in the parameter go to the left subtree
        node -> left = insertNode(node -> left,pair);
        // Then balance the tree
        node = balance(node);
    }
    else if (pair -> getPair() > node -> data -> getPair()) {
        // if the pair in the parameter is greater than the pair in the node go to the right subtree
        node -> right = insertNode(node -> right,pair);
        // Then balance the tree
        node = balance(node);
    }
    else {
        // If the pair is equal increase the counter
        node -> data -> IncreaseCounter();
    }
    return node;
}

AVL::AVL() : BST() {} // Sets the root to null. ame as the base class BST()

int AVL::height(TreeNode *node) {
    // Finds the height of the right and left subtrees
    int h = 0;
    if (node != nullptr) {
        int LeftHeight = height(node -> left);
        int RightHeight = height(node -> right);
        int MaxHeight = max(LeftHeight,RightHeight);
        h = MaxHeight + 1;
    }
    return h; // Returns the max height of left and right subtrees plus 1
}

int AVL::difference(TreeNode *node) {
    // Finds the height of the left and right subtrees
    int LeftHeight = height(node -> left);
    int RightHeight = height(node -> right);
    return LeftHeight - RightHeight; // returns the difference of the heights
}

TreeNode * AVL::RightRight_Rotate(TreeNode *node) {
    // Rotates the tree 2 times right
    TreeNode * temp;
    temp = node -> right;
    node -> right = temp -> left;
    temp -> left = node;
    return temp;
}

TreeNode * AVL::LeftLeft_Rotate(TreeNode *node) {
    // Rotates the tree 2 times left
    TreeNode * temp;
    temp = node  -> left;
    node -> left = temp -> right;
    temp -> right = node;
    return  temp;
}

TreeNode * AVL::RightLeft_Rotate(TreeNode *node) {
    // Rotates the tree first right then left
    TreeNode * temp;
    temp = node -> right;
    node -> right = LeftLeft_Rotate(temp);
    return RightRight_Rotate(node);
}

TreeNode * AVL::LeftRight_Rotate(TreeNode *node) {
    // Rotates the tree first left then right
    TreeNode * temp;
    temp = node-> left;
    node -> left = RightRight_Rotate(temp);
    return LeftLeft_Rotate(node);
}

TreeNode * AVL::balance(TreeNode *node) {
    //Balances the tree by making the correct rotates
    int BalanceFactor = difference(node);
    if (BalanceFactor > 1) {
        if (difference(node -> left) > 0)
            node = LeftLeft_Rotate(node);
        else
            node = LeftRight_Rotate(node);
    }
    else if (BalanceFactor < -1) {
        if (difference(node -> right) > 0)
            node = RightLeft_Rotate(node);
        else
            node = RightRight_Rotate(node);
    }
    return node; // returns the balanced tree
}