#include <stdio.h>
#include <string.h>

enum {
    MAX_N = 100000,
};

int list[MAX_N];
int length = 0;

void binary_search(int value)
{
    int l = 1;
    int r = length;
    while (r >= l)
    {
        int mid = (l + (r - l) / 2);
        if (value > list[mid])
            l = mid + 1;
        else
            r = mid - 1;
    }
    list[l] = value;
}


int main()
{
    int i, value, n;
    memset(list, 0, MAX_N * sizeof(int));
    list[0] = -1;
    scanf("%d\n", &n);
    for (i = 0; i < n; i ++)
    {
        scanf("%d", &value);
        if (value > list[length])
            list[++length] = value;
        else
            binary_search(value);
    }
    printf("%d\n", length);
    return 0;
}
