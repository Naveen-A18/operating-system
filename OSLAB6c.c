 #include <stdio.h>

#define MAX_BLOCKS 100

// Structure to represent memory blocks
struct MemoryBlock {
    int block_id;
    int size;
    int allocated;
};

// Function to perform first-fit memory allocation
void firstFit(struct MemoryBlock blocks[], int m, int processSize) {
    for (int i = 0; i < m; i++) {
        if (blocks[i].allocated == 0 && blocks[i].size >= processSize) {
            // Allocate the memory block
            blocks[i].allocated = 1;
            printf("Process of size %d allocated to block %d\n",
                   processSize, i + 1);
            return;
        }
    }
    printf("Cannot allocate process of size %d\n", processSize);
}

int main() {
    int m, n;

    // Number of memory blocks
    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);

    struct MemoryBlock blocks[MAX_BLOCKS];

    for (int i = 0; i < m; i++) {
        blocks[i].block_id = i + 1;
        printf("Enter the size of memory block %d: ", i + 1);
        scanf("%d", &blocks[i].size);
        blocks[i].allocated = 0; // Initialize as unallocated
    }

    // Number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int processSize;
        printf("Enter the size of process %d: ", i + 1);
        scanf("%d", &processSize);
        firstFit(blocks, m, processSize);
    }

    
}