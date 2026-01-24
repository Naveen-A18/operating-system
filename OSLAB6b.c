#include <stdio.h>

#define MAX_BLOCKS 100

// Structure to represent memory blocks
struct MemoryBlock {
    int block_id;
    int size;
    int allocated;
};

// Function to perform best-fit memory allocation
void bestFit(struct MemoryBlock blocks[], int m, int processSize) {
    int bestIdx = -1;

    for (int i = 0; i < m; i++) {
        if (blocks[i].allocated == 0 && blocks[i].size >= processSize) {
            if (bestIdx == -1 || blocks[i].size < blocks[bestIdx].size) {
                bestIdx = i;
            }
        }
    }

    if (bestIdx != -1) {
        blocks[bestIdx].allocated = 1;
        printf("Process of size %d allocated to block %d\n",
               processSize, bestIdx + 1);
    } else {
        printf("Cannot allocate process of size %d\n", processSize);
    }
}

int main() {
    int m, n;

    printf("Enter number of memory blocks: ");
    scanf("%d", &m);

    struct MemoryBlock blocks[MAX_BLOCKS];

    for (int i = 0; i < m; i++) {
        blocks[i].block_id = i + 1;
        printf("Enter size of memory block %d: ", i + 1);
        scanf("%d", &blocks[i].size);
        blocks[i].allocated = 0;
    }

  
}
