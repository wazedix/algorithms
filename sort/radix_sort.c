#include <limits.h>
#include <stdlib.h>
#include <string.h>

void radix_sort(int *list, int l, int r)
{
    int i, max=INT_MIN, radix = 1, index, length, temp;
    int *temp_list = (int*)malloc((r-l+1)*sizeof(int));
    int *result_list = (int*)malloc((r-l+1)*sizeof(int));
    int *count_list[10];
    for (i = 0; i <= 9; i ++)
        count_list[i] = (int*)malloc((r-l+1)*sizeof(int));
    int count_list_length[10];
    int count_sum_length[10];
    for (i = l; i <= r; i ++)
        if (list[i] > max)
            max = list[i];
    while ((max / radix) > 0)
    {
        memset(count_list_length, 0, 10*sizeof(int));
        for (i = l; i <= r; i ++)
            temp_list[i] = (list[i] / radix) % 10;
        for (i = l; i <= r; i ++)
        {
            index = temp_list[i];
            count_list_length[index] ++;
            length = count_list_length[index];
            count_list[index][length] = list[i];
        }
        count_sum_length[0] = count_list_length[0];
        for (i = 1; i <= 9; i ++)
        {
            count_sum_length[i] = count_list_length[i];
            count_sum_length[i] += count_sum_length[i-1];
        }
        for (i = l; i <= r; i ++)
        {
            temp = temp_list[i];
            int sum = (temp-1 >= 0) ? count_sum_length[temp-1] : 0;
            length = count_list_length[temp];
            index = sum + length;
            result_list[index-l-1] = count_list[temp][length];
            count_list_length[temp] --;
        }
        for (i = l; i <= r; i++)
        {
            list[i] = result_list[i-l];
        }
        radix *= 10;
    }
    for (i = 0; i <= 9; i ++)
        free(count_list[i]);
    free(result_list);
    free(temp_list);   
}
