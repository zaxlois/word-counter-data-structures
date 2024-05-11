#include "BST.h" // Include the header file of the class

BST::BST() {root = nullptr;} // Sets the root to null

TreeNode* BST::insertNode(TreeNode *node, WordPair *pair) {
    // if the node is empty insert the pair
    if (node == nullptr) {
        return new TreeNode(pair);
    }

    if (pair -> getPair() < node -> data -> getPair()) {
        // if the pair in the node is greater than the pair in the parameter go to the left subtree
        node -> left = insertNode(node -> left,pair);
    }
    else if (pair -> getPair() > node -> data -> getPair()) {
        // if the pair in the parameter is greater than the pair in the node go to the right subtree
        node -> right = insertNode(node -> right,pair);
    }
    else {
        //if the pair is equal then increase the counter
        node -> data -> IncreaseCounter();
    }

    return node;
}

int BST::search(TreeNode *node, WordPair pair) {
    if (node == nullptr) {
        return false;
    }

    if (node -> data -> getPair() == pair.getPair()) {
        // if the pair is equal return the counter
        return node -> data -> getCounter();
    }
    else if (node -> data -> getPair() < pair.getPair()) {
        // if the pair in the parameter is greater than the pair in the node go to the right subtree
        return search(node -> right,pair);
    }
    else {
        // if the pair in the node is greater than the pair in the parameter go to the left subtree
        return search(node -> left,pair);
    }
}

void BST::insertPair(const std::string &pair) {
    //Create the object and pass it in insertNode
    WordPair *np = new WordPair(pair);
    root = insertNode(root,np);
}

TreeNode * BST::getRoot() {return root;} // return the root of the tree