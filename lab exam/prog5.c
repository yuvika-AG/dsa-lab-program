
#include <stdio.h>
#include <stdlib.h>

// Structure of a BST node
struct Node {
    int imageID;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(int id) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->imageID = id;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Function to insert an image ID into BST
struct Node* insert(struct Node* root, int id) {

    if (root == NULL) {
        return createNode(id);
    }

    if (id < root->imageID) {
        root->left = insert(root->left, id);
    }
    else if (id > root->imageID) {
        root->right = insert(root->right, id);
    }
    else {
        printf("Duplicate ID not allowed!\n");
    }

    return root;
}

// Preorder traversal: Root -> Left -> Right
void preorder(struct Node* root) {

    if (root == NULL) {
        return;
    }

    printf("%d ", root->imageID);

    preorder(root->left);

    preorder(root->right);
}

// Main function
int main() {
    struct Node* root = NULL;
    int n, id, i;

    printf("Enter number of CT images: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter image ID: ");
        scanf("%d", &id);

        root = insert(root, id);
    }

    printf("\nPreorder traversal of BST:\n");
    preorder(root);

    return 0;
}
