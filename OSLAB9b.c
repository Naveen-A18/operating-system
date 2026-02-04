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
