#include <stdio.h>

#define MAX_BLOCKS 100

struct MemoryBlock
{
    int block_id;
    int size;
    int allocated;   // 0 = free, 1 = allocated
};

void worstFit(struct MemoryBlock blocks[], int m, int processSize)
{
    int worstIdx = -1;

    // Find the WORST (largest) free block that can fit the process
    for (int i = 0; i < m; i++)
    {
        if (blocks[i].allocated == 0 && blocks[i].size >= processSize)
        {
            if (worstIdx == -1 || blocks[i].size > blocks[worstIdx].size)
            {
                worstIdx = i;
            }
        }
    }

    // Allocate if found
    if (worstIdx != -1)
    {
        blocks[worstIdx].allocated = 1;
        printf("Process with size %d allocated to block %d\n",
               processSize, worstIdx + 1);
    }
    else
    {
        printf("Cannot allocate the process with size %d\n", processSize);
    }
}
