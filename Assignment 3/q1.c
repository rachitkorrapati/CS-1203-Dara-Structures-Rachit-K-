#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left;
    struct node *right;
    int height;
};

int getHeight(struct node *n) {
    if (n == NULL)
        return 0;
    return n->height;
}

struct node *createNode(int key) {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int getBalanceFactor(struct node *n) {
    if (n == NULL) {
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

struct node *rightRotate(struct node *y) {
    struct node *x = y->left;
    struct node *T2 = x->right;
    x->right = y;
    y->left = T2;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    return x;
}

struct node *leftRotate(struct node *x) {
    struct node *y = x->right;
    struct node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    return y;
}

struct node *insert(struct node *node, int key) {
    if (node == NULL)
        return createNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int bf = getBalanceFactor(node);

    if (bf > 1 && key < node->left->key) {
        return rightRotate(node);
    }
    if (bf < -1 && key > node->right->key) {
        return leftRotate(node);
    }
    if (bf > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (bf < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

struct node *minValueNode(struct node *node) {
    struct node *current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

struct node *deleteNode(struct node *root, int key) {
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            struct node *temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;

            free(temp);
        } else {
            struct node *temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int bf = getBalanceFactor(root);

    if (bf > 1 && getBalanceFactor(root->left) >= 0)
        return rightRotate(root);

    if (bf < -1 && getBalanceFactor(root->right) <= 0)
        return leftRotate(root);

    if (bf > 1 && getBalanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (bf < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void preOrder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(struct node *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

void displayTree(struct node *root, int space) {
    if (root == NULL)
        return;
    space += 10;

    displayTree(root->right, space);
    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);
    displayTree(root->left, space);
}

int main() {
    struct node *root = NULL;
    int choice, data;

    while (1) {
        printf("AVL Tree Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Pre-order Traversal\n");
        printf("4. In-order Traversal\n");
        printf("5. Display Tree\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
            case 3:
                printf("Pre-order Traversal: ");
                preOrder(root);
                printf("\n");
                break;
            case 4:
                printf("In-order Traversal: ");
                inOrder(root);
                printf("\n");
                break;
            case 5:
                printf("Display Tree:\n");
                displayTree(root, 10);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
