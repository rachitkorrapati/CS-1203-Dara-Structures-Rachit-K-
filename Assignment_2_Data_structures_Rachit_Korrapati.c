#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Stack structure for holding tree nodes
struct Stack {
    struct TreeNode **nodes;
    int capacity;
    int size;
};

// Initialize a stack
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->size = 0;
    stack->nodes = (struct TreeNode**)malloc(capacity * sizeof(struct TreeNode*));
    return stack;
}

// Push a node onto the stack
void push(struct Stack* stack, struct TreeNode* node) {
    if (stack->size < stack->capacity) {
        stack->nodes[stack->size++] = node;
    }
}

// Pop a node from the stack
struct TreeNode* pop(struct Stack* stack) {
    if (stack->size > 0) {
        return stack->nodes[--stack->size];
    }
    return NULL;
}

// Check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->size == 0;
}

// Inorder traversal without recursion
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int* result = (int*)malloc(sizeof(int) * 1000); // Assuming a maximum of 1000 nodes
    int index = 0;
    struct Stack* stack = createStack(1000);

    struct TreeNode* current = root;

    while (current != NULL || !isEmpty(stack)) {
        while (current != NULL) {
            push(stack, current);
            current = current->left;
        }

        current = pop(stack);
        result[index++] = current->val;
        current = current->right;
    }

    *returnSize = index;
    return result;
}

// Helper function to create a new TreeNode
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    int returnSize;
    int* result = inorderTraversal(root, &returnSize);

    printf("Inorder Traversal: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}
