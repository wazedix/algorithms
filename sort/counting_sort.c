#include <stdlib.h>
#include <limits.h>
#include <string.h>

void counting_sort(int *list, int l, int r)
{
    int i, max=INT_MIN;
    for (i = l; i <= r; i ++)
        if (list[i] > max)
            max = list[i];
    int *temp_list = (int*)malloc((r-l+1)*sizeof(int));
    int *count_list = (int*)malloc((max+1)*sizeof(int));
    memset(count_list, 0, (max+1));
    for (i = l; i <= r; i ++)
        count_list[list[i]] += 1;
    for (i = 1; i <= max; i ++)
        count_list[i] += count_list[i-1];
    for (i = l; i <= r; i ++)
    {
        temp_list[count_list[list[i]]-l-1] = list[i];
        count_list[list[i]] -= 1;
    }
    for (i = l; i <= r; i ++)
    {
        list[i] = temp_list[i-l];
    }
    free(count_list);
    free(temp_list);
}
