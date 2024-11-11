#include <stdio.h>
#include <stdlib.h>
/*
Exercise 4: Binary Search Tree
description:
    Implement a binary search tree with the following functions:
        1. insert
        2. inorder traversal
        3. main function to test the implementation

Tips:
    "->" is used to access the members of a struct through a pointer.
    "malloc" is used to allocate a single block of memory of a given size.
    "sizeof" is used to get the size of a variable or a type in bytes.
    "free" is used to release the memory allocated by malloc.
    "NULL" is a constant macro that represents a null pointer.
    "int" is a data type that represents an integer.
*/

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

/*TODO: Implement a function to insert a node into the BST*/
struct Node* insert(struct Node* root, int data) {
    /*TODO*/
    if (root == NULL) {
        root = (struct Node*)malloc(sizeof(struct Node));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

/*TODO: Implement a function to perform inorder traversal*/
void inorder(struct Node* root) {
    /*TODO*/
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 5);
    inorder(root); // Should print in sorted order: 5 10 20
    return 0;
}
