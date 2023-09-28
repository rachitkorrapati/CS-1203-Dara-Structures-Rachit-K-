#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the queue
struct Node {
    int data;
    struct Node* next;
};

// Define the structure for the queue
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function prototypes
void initializeQueue(struct Queue* queue);
void insert(struct Queue* queue, int value);
int delete(struct Queue* queue);
void printQueue(struct Queue* queue);

int main() {
    struct Queue myQueue;
    initializeQueue(&myQueue);

    int choice, value;

    do {
        printf("\nQueue Operations Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Print Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to insert: ");
                scanf("%d", &value);
                insert(&myQueue, value);
                break;
            case 2:
                if (myQueue.front == NULL) {
                    printf("Queue is empty. Cannot delete.\n");
                } else {
                    int deletedValue = delete(&myQueue);
                    printf("Deleted value: %d\n", deletedValue);
                }
                break;
            case 3:
                printf("Queue contents: ");
                printQueue(&myQueue);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to initialize an empty queue
void initializeQueue(struct Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Function to insert a value into the queue
void insert(struct Queue* queue, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Queue is full.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        // If the queue is empty, set both front and rear to the new node
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        // Otherwise, update the rear and link the previous rear to the new node
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to delete a value from the front of the queue
int delete(struct Queue* queue) {
    struct Node* temp;
    int deletedValue;

    temp = queue->front;
    deletedValue = temp->data;

    if (queue->front == queue->rear) {
        // If there's only one element in the queue, reset both front and rear
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        // Otherwise, move front to the next node
        queue->front = queue->front->next;
    }

    free(temp);
    return deletedValue;
}

// Function to print the contents of the queue
void printQueue(struct Queue* queue) {
    struct Node* current = queue->front;

    if (current == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

