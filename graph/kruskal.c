#include <stdio.h>
#include <stdlib.h>

enum {
    MAXN = 600,
};

typedef struct {
    int x;
    int y;
    int value;
}Edge;

Edge edge[MAXN * MAXN];
int father[MAXN];


int cmp(const void *x, const void *y)
{
    return (*(Edge *)x).value - (*(Edge *)y).value;
}


int get_father(int x)
{
    if (father[x] != x)
        father[x] = get_father(father[x]);
    return father[x];
}


void set_union(int x, int y)
{
    x = get_father(x);
    y = get_father(y);
    if (x != y)
        father[x] = y;
}


int main(void)
{
    int n, i, j, value;
    int length = 0;
    int max = 0;
    int num_E = 0;
    scanf("%d", &n);
    for (i = 1; i <= n; i ++)
    {
        father[i] = i;
        for (j = 1; j <=n; j ++)
        {
            scanf("%d", &value);
            edge[length].x = i;
            edge[length].y = j;
            edge[length].value = value;
            length ++;
        }
    }
    qsort(edge, length, sizeof(Edge), cmp);
    for (i = 0; i < length; i ++)
    {
        if (get_father(edge[i].x) != get_father(edge[i].y))
        {
            set_union(edge[i].x, edge[i].y);
            num_E ++;
        }
        if (num_E >= n-1)
            break;
    }
    return 0;
}
