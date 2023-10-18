#include <stdio.h>

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    towerOfHanoi(n - 1, source, destination, auxiliary);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n;
    printf("Welcome to the Tower of Hanoi solver!\n");
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    
    printf("\nSolving the Tower of Hanoi problem for %d disks:\n\n", n);
    towerOfHanoi(n, 'A', 'B', 'C');
    
    printf("\nTower of Hanoi problem solved for %d disks!\n", n);
    
    return 0;
}

