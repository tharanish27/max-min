#include <stdio.h>
#include <stdlib.h>
#include <limits.h>  // For INT_MAX and INT_MIN

// Define the structure for a tree node
typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function to create a new tree node
TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to find the minimum value in the binary tree
int findMin(TreeNode* root) {
    if (root == NULL) {
        return INT_MAX;  // Return a large number if the tree is empty
    }

    // Find the minimum value in the left and right subtrees
    int minLeft = findMin(root->left);
    int minRight = findMin(root->right);

    // Return the minimum of the current node's value, left subtree, and right subtree
    return (root->value < minLeft) ? ((root->value < minRight) ? root->value : minRight) : ((minLeft < minRight) ? minLeft : minRight);
}

// Function to find the maximum value in the binary tree
int findMax(TreeNode* root) {
    if (root == NULL) {
        return INT_MIN;  // Return a small number if the tree is empty
    }

    // Find the maximum value in the left and right subtrees
    int maxLeft = findMax(root->left);
    int maxRight = findMax(root->right);

    // Return the maximum of the current node's value, left subtree, and right subtree
    return (root->value > maxLeft) ? ((root->value > maxRight) ? root->value : maxRight) : ((maxLeft > maxRight) ? maxLeft : maxRight);
}

// Main function to demonstrate finding min and max values
int main() {
    // Create a simple binary tree
    TreeNode* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(20);
    root->left->left = createNode(1);
    root->left->right = createNode(8);
    root->right->left = createNode(15);
    root->right->right = createNode(25);

    // Find and print the minimum and maximum values
    int minValue = findMin(root);
    int maxValue = findMax(root);
    
    printf("Minimum value in the binary tree: %d\n", minValue);
    printf("Maximum value in the binary tree: %d\n", maxValue);
    
    // Free allocated memory (not shown here for simplicity)
    // Implement proper cleanup in real code

    return 0;
}
