#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// insertion sort function
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// bubblesort function
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

 //printing the array 
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr_insertion[n], arr_bubble[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr_insertion[i]);
        arr_bubble[i] = arr_insertion[i];
    }

    printf("\nOriginal Array: ");
    printArray(arr_insertion, n);

    clock_t start, end;
    double cpu_time_used;

    // Insertion Sort
    start = clock();
    insertionSort(arr_insertion, n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nSorted Array (Insertion Sort): ");
    printArray(arr_insertion, n);
    printf("Time taken for Insertion Sort: %f seconds\n", cpu_time_used);

    // Bubble Sort
    start = clock();
    bubbleSort(arr_bubble, n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nSorted Array (Bubble Sort): ");
    printArray(arr_bubble, n);
    printf("Time taken for Bubble Sort: %f seconds\n", cpu_time_used);

    // Time Complexity Analysis
    printf("\nTime Complexity Analysis:\n");
    printf("Insertion Sort has an average time complexity of O(n^2).\n");
    printf("Bubble Sort also has an average time complexity of O(n^2).\n");

    return 0;
}
