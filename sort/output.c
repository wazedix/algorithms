#include <stdio.h>

void output(int *list, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", list[i]);
    printf("\n");
}
