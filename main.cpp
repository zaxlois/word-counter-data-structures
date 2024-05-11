#include "StructureFunctions.h" //include the necessary header file

int main() {
    Array random = CreateRandomTable("input.txt"); // random array

    UnsortedArray unsorted_table = CreateUnsortedTable("input.txt","output.txt"); //unsorted array
    UnsortedSearch(unsorted_table,random,"output.txt"); // search unsorted array

    SortedArray sorted_table = CreateSortedArray("input.txt","output.txt"); // sorted array
    SortedSearch(sorted_table,random,"output.txt"); // search sorted array

    BST bst_tree = CreateBST("input.txt","output.txt"); // binary search tree
    BSTsearch(bst_tree,random,"output.txt"); // search bst

    AVL avl_tree = CreateAVL("input.txt","output.txt"); // avl tree
    AVLsearch(avl_tree,random,"output.txt"); //search avl tree

    HashTable array = CreateHashTable("input.txt","output.txt"); // hashtable array
    HashTableSearch(array,random,"output.txt"); // search hashtable array

}