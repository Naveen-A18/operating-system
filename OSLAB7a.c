// Develop a C program to simulate page replacement algorithm using FIFO

#include <stdio.h>

int main()
{
    int incomingStream[] = {4, 1, 2, 4, 5, 4, 1, 2, 3, 6};
    int pageFaults = 0;
    int frames = 3;
    int m, n, s, pages;

    pages = sizeof(incomingStream) / sizeof(incomingStream[0]);

    printf("Incoming\tFrame 1\tFrame 2\tFrame 3");

    int temp[3];

    // Initialize frames with -1
    for (m = 0; m < frames; m++)
        temp[m] = -1;

    for (m = 0; m < pages; m++)
    {
        s = 0;

        // Check if page already exists
        for (n = 0; n < frames; n++)
        {
            if (incomingStream[m] == temp[n])
            {
                s++;
                pageFaults--;
            }
        }

        pageFaults++;

        // FIFO logic
        if ((pageFaults <= frames) && (s == 0))
        {
            temp[m] = incomingStream[m];
        }
        else if (s == 0)
        {
            temp[(pageFaults - 1) % frames] = incomingStream[m];
        }

        printf("\n%d\t\t", incomingStream[m]);

        for (n = 0; n < frames; n++)
        {
            if (temp[n] != -1)
                printf("%d\t\t", temp[n]);
            else
                printf("-\t\t");
        }
    }

    printf("\n\nTotal Page Faults:\t%d\n", pageFaults);

    return 0;
}
