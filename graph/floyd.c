#include <stdio.h>
#include <limits.h>

enum {
    MAX_N = 200,
};

int map[MAX_N][MAX_N];


void floyd(int n)
{
    int i, j, k;
    for (k = 1; k <= n; k ++)
        for (i = 1; i <= n; i ++)
            for (j = 1; j <= n; j ++)
                if (map[i][k] + map[k][j] < map[i][j])
                    map[i][j] = map[i][k] + map[k][j];
}


int main(void)
{
    int n, m, i, j, a, b, value;
    scanf("%d %d\n", &n, &m);
    for (i = 1; i <= n; i ++)
        for (j = 1; j <= n; j ++)
            map[i][j] = INT_MAX / 2;
    for (i = 0; i < m; i ++)
    {
        scanf("%d %d %d\n", &a, &b, &value);
        map[a][b] = value;
    }
    floyd(n);
    for (i = 1; i <= n; i ++)
    {
        for (j = 1; j <= n; j ++)
            if (map[i][j] == INT_MAX / 2)
                printf("- ");
            else
                printf("%d ", map[i][j]);
        printf("\n");
    }
    return 0;    
}
