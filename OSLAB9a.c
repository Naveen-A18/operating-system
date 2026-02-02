#include <stdio.h>
#include <stdlib.h>

int main() {
    int f[50], i, st, len, j, c, k, a;

    // Initialize all blocks as free (0)
    for (i = 0; i < 50; i++)
        f[i] = 0;

    // Already allocated blocks
    printf("Enter how many blocks already allocated: ");
    scanf("%d", &p);

    printf("Enter blocks already allocated: ");
    for (i = 0; i < p; i++) {
        scanf("%d", &a);
        f[a] = 1;
    }
