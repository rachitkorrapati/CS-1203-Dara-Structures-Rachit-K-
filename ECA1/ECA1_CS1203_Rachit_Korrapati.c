#include <stdio.h>

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("%d\n", arr[i]);
        } else {
            printf("%d, ", arr[i]);
        }
    }
}

void generatePermutations(int n) {
    int arr[n];
    int indexes[n];
    
    // Initialize the array with values 1 to n
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
        indexes[i] = 0;
    }
    
    printArray(arr, n); // Print the initial permutation
    
    int i = 0;
    while (i < n) {
        if (indexes[i] < i) {
            // Swap elements at indexes[i] and i
            int temp = arr[indexes[i]];
            arr[indexes[i]] = arr[i];
            arr[i] = temp;
            
            printArray(arr, n); // Print the new permutation
            
            indexes[i]++;
            i = 0; // Reset i to 0 to start from the first element
        } else {
            indexes[i] = 0;
            i++;
        }
    }
}

int main() {
    int n;
    
    printf("Enter a value for n (1 <= n <= 8): ");
    scanf("%d", &n);
    
    if (n >= 1 && n <= 8) {
        generatePermutations(n);
    } else {
        printf("Invalid input. Please enter a value between 1 and 8.\n");
    }
    
    return 0;
}
