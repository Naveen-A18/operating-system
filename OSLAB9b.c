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
