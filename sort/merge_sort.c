#include <stdio.h>
#include <stdlib.h>


void merge_sort(int *list, int l, int r)
{
    int mid = (r + l + 1) / 2;
    if ((r-l) > 1)
    {
        merge_sort(list, l, mid-1);
        merge_sort(list, mid, r);
    }
    int *temp_list = (int*)malloc((r-l+1)*sizeof(int));
    int v=0, k, i = l, j = mid;
    while ((i <= mid-1) && (j <= r))
    {
        if (list[i] <= list[j])
        {
            temp_list[v] = list[i];
            i ++;
            v ++;
        }
        else
        {
            temp_list[v] = list[j];
            j ++;
            v ++;
        }
    }
    while (i <= mid-1)
    {
        temp_list[v] = list[i];
        i ++;
        v ++;
    }
    while (j <= r)
    {
        temp_list[v] = list[j];
        j ++;
        v ++;
    }
    for (k = 0; k < r-l+1; k ++)
        list[l+k] = temp_list[k]; 
    free(temp_list);
}
