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
                if (map[i][k] == 1 && map[k][j] == 1)
                    map[i][j] = 1;
                //if (map[i][k] + map[k][j] < map[i][j])
                //    map[i][j] = map[i][k] + map[k][j];
}


int main(void)
{
    int n, m, i, j, a, b;
    scanf("%d %d\n", &n, &m);
    for (i = 1; i <= n; i ++)
        for (j = 1; j <= n; j ++)
            map[i][j] = INT_MAX / 2;
    for (i = 0; i < m; i ++)
    {
        scanf("%d %d\n", &a, &b);
        map[a][b] = 1;
    }
    floyd(n);
    int ans = 0, temp;
    for (i = 1; i <= n; i ++)
    {
        temp = 0;
        for (j = 1; j <= n; j ++)
            if ((i != j) && (map[i][j] == 1 || map[j][i] == 1))
                temp ++;
        if (temp == n-1)
            ans ++;
    }
    printf("%d", ans);
    return 0;    
}
