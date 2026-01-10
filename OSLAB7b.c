#include <stdio.h>
#include <limits.h>

int checkHit(int incomingPage, int queue[], int occupied)
{
    for (int i = 0; i < occupied; i++)
    {
        if (incomingPage == queue[i])
            return 1;
    }
    return 0;
}

void printFrame(int queue[], int occupied)
{
    for (int i = 0; i < occupied; i++)
        printf("%d\t\t", queue[i]);
}

int main()
{
    // You can change the incoming stream if needed
    // int incomingStream[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1};
    int incomingStream[] = {1, 2, 3, 2, 1, 5, 2, 1, 6, 2, 5, 6, 3, 1, 3};

    int n = sizeof(incomingStream) / sizeof(incomingStream[0]);
    int frames = 3;

    int queue[frames];
    int distance[frames];

    int occupied = 0;
    int pagefault = 0;

    printf("Page\tFrame 1\t\tFrame 2\t\tFrame 3\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d:\t\t", incomingStream[i]);

        // HIT condition
        if (checkHit(incomingStream[i], queue, occupied))
        {
            printFrame(queue, occupied);
        }
        // If frames are not full (empty frame exists)
        else if (occupied < frames)
        {
            queue[occupied] = incomingStream[i];
            pagefault++;
            occupied++;
            printFrame(queue, occupied);
        }
        // If frames are full -> Replace LRU
        else
        {
            int max = INT_MIN;
            int index = 0;

            // find LRU using distance method
            for (int j = 0; j < frames; j++)
            {
                distance[j] = 0;

                // traverse backward to find last occurrence
                for (int k = i - 1; k >= 0; k--)
                {
                    distance[j]++;
                    if (queue[j] == incomingStream[k])
                        break;
                }

                // find max distance -> least recently used
                if (distance[j] > max)
                {
                    max = distance[j];
                    index = j;
                }
            }

            queue[index] = incomingStream[i];
            pagefault++;
            printFrame(queue, occupied);
        }

        printf("\n");
    }

    printf("\nPage Fault: %d\n", pagefault);

    return 0;
}
