#include <stdio.h>

// Number of memory blocks
#define NUM_BLOCKS 5

// Number of processes
#define NUM_PROCESSES 5

// Sizes of memory blocks
int memory_blocks[NUM_BLOCKS] = {100, 500, 200, 300, 600};

// Sizes of processes
int process_sizes[NUM_PROCESSES] = {212, 417, 112, 426, 112};

// Array to keep track of allocated blocks
int allocated[NUM_BLOCKS] = {0};

// Function to perform Best Fit allocation
void bestFit() {
    for (int i = 0; i < NUM_PROCESSES; i++) {
        int best_fit_index = -1;

        for (int j = 0; j < NUM_BLOCKS; j++) {
            if (!allocated[j] && memory_blocks[j] >= process_sizes[i]) {
                if (best_fit_index == -1 || 
                    memory_blocks[j] < memory_blocks[best_fit_index]) {
                    best_fit_index = j;
                }
            }
        }

        if (best_fit_index != -1) {
            allocated[best_fit_index] = 1;
            printf("Process %d (size %d) is allocated to Block %d (size %d)\n",
                   i + 1, process_sizes[i], best_fit_index + 1, memory_blocks[best_fit_index]);
        } else {
            printf("Process %d (size %d) cannot be allocated\n",
                   i + 1, process_sizes[i]);
        }
    }
}

