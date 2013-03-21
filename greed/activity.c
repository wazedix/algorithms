#include <stdio.h>

enum {
    MAXN = 10,
};


void sort(int *begin, int *end, int n)
{
    int i, j, temp;
    for (i = 0; i < n; i ++)
        for (j = i+1; j < n; j ++)
            if (end[j] < end[i])
            {
                temp = end[j];
                end[j] = end[i];
                end[i] = temp;
                temp = begin[j];
                begin[j] = begin[i];
                begin[i] = temp;
            }
}


void select(int *begin, int *end, int n)
{
    int index = 0;
    int ans[MAXN], length = 0;
    int last_time = 0;
    while (index < n)
    {
        if (begin[index] > last_time)
        {
            ans[length ++] = index;
            last_time = end[index];
        }
        index ++;
    }
    for (index = 0; index < length; index ++)
        printf("%d ", ans[index] + 1);
    printf("\n");
}


int main(void)
{
    int begin[MAXN], end[MAXN];
    int n, i;
    scanf("%d\n", &n);
    for (i = 0; i < n; i ++)
        scanf("%d %d\n", &begin[i], &end[i]);
    sort(begin, end, n);
    select(begin, end, n);
    return 0;
}
