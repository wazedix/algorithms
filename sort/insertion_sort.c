#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertion_sort(int *list, int l, int r)
{
    int i, j, k, temp_length = 1;
    int *temp_list = (int*)malloc((r-l+1)*sizeof(int));
    memset(temp_list, 0, (r-l+1)*sizeof(int));
    temp_list[l] = list[l];
    for (i = l+1; i <= r; i++)
    {   
        for (j = 0; j < temp_length; j ++)
            if (list[i] < temp_list[j])
                break;
        for (k = temp_length; k > j; k--)
            temp_list[k] = temp_list[k-1];
        temp_list[j] = list[i];
        temp_length ++;
    }
    for (i = l; i <= r; i++)
        list[i] = temp_list[i];
    free(temp_list);
}
