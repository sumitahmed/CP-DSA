#include <stdio.h>
#include <stdlib.h>

// Structure for the BST node
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node* newNode(int val) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// ALGO: Inorder Traversal (Left, Root, Right)
void inorder(struct node* tree) {
    if (tree != NULL) {
        inorder(tree->left);       // Step 2: Visit Left Subtree
        printf("%d ", tree->data); // Step 3: Print Data (Root)
        inorder(tree->right);      // Step 4: Visit Right Subtree
    }
}

int main() {
    /* Creating a sample BST:
          50
         /  \
        30   70
    */
    struct node* root = newNode(50);
    root->left = newNode(30);
    root->right = newNode(70);

    printf("Inorder Traversal Result: ");
    inorder(root);

    return 0;
}