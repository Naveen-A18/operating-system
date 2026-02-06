#include <stdio.h>                                
#include <stdlib.h>

int main()                 
{
    int n, head, max;
    int queue[20], queue1[20], queue2[20];
    int temp, temp1 = 0, temp2 = 0;
    int i, j;
    int seek = 0, diff;
    float avg;

    printf("Enter maximum disk range: ");
    scanf("%d", &max);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter disk requests:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &queue[i]);
   for(i = 0; i < n; i++)
    {
        if(queue[i] >= head)
            queue1[temp1++] = queue[i];
        else
            queue2[temp2++] = queue[i];
    }

    for(i = 0; i < temp1-1; i++)
        for(j = i+1; j < temp1; j++)
            if(queue1[i] > queue1[j])
            {
                temp = queue1[i];
                queue1[i] = queue1[j];
                queue1[j] = temp;
            }
for(i = 0; i < temp2-1; i++)
        for(j = i+1; j < temp2; j++)
            if(queue2[i] < queue2[j])
            {
                temp = queue2[i];
                queue2[i] = queue2[j];
                queue2[j] = temp;
            }

    queue[0] = head;
    j = 1;

    for(i = 0; i < temp1; i++)
        queue[j++] = queue1[i];

    queue[j++] = max;
 for(i = 0; i < temp2; i++)
        queue[j++] = queue2[i];

    printf("\nSeek Sequence:\n");
    for(i = 0; i < j-1; i++)
    {
        diff = abs(queue[i+1] - queue[i]);
        seek += diff;
        printf("Move from %d to %d with seek %d\n", queue[i], queue[i+1], diff);
    }

    printf("\nTotal Seek Time = %d", seek);

    avg = (float)seek / n;
    printf("\nAverage Seek Time = %.2f\n", avg);

    return 0;
}

