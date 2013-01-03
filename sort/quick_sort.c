#include <stdio.h>
#include <stdlib.h>


void quick_sort(int *list, int l, int r)
{
    int i = l, j = r, temp;
    int key = l + (rand() % (r-l));
    int value = list[key];
    while (i < j)
    {
        while (list[i] < value) i ++;
        while (list[j] > value) j --;
        if (i <= j)
        {
            temp = list[i];
            list[i] = list[j];
            list[j] = temp;
            i ++;
            j --;
        }
    }
    if (i < r) quick_sort(list, i, r);
    if (l < j) quick_sort(list, l, j);
}
     
