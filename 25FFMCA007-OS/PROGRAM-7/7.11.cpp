#include <stdio.h>

int main() {
    int f[50], i, start, len;

    // Initialize all blocks to 0 (free)
    for(i = 0; i < 50; i++) {
        f[i] = 0;
    }

    printf("Enter starting block: ");
    scanf("%d", &start);
    printf("Enter length of file: ");
    scanf("%d", &len);

    // Check if blocks are already allocated
    // Using 'j' here so we don't mess up 'i'
    for(int j = start; j < start + len; j++) {
        if(f[j] == 1 || j >= 50) { // Also check for array bounds
            printf("Allocation not possible\n");
            return 0;
        }
    }

    // If we got here, allocation is possible
    printf("\nFile allocated successfully\n");
    printf("Allocated blocks are: ");
    for(int j = start; j < start + len; j++) {
        f[j] = 1;
        printf("%d ", j);
    }

    return 0;
}

