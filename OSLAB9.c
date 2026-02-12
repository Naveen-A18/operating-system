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

x:
    printf("Enter index starting block and length: ");
    scanf("%d %d", &st, &len);

    k = len;

    if (f[st] == 0) {

        for (j = st; j < (st + k); j++) {

            if (f[j] == 0) {
                f[j] = 1;
                printf("%d --> ", j);
            }
            else {
                printf("\n%d Block is already allocated\n", j);
                k++;   // Move to next free block
            }
        }
        printf("NULL\n");
    }
    else {
        printf("%d starting block is already allocated\n", st);
    }

    printf("Do you want to enter more file (Yes - 1 / No - 0): ");
    scanf("%d", &c);

    if (c == 1)
        goto x;
    else
        exit(0);

    return 0;
}
