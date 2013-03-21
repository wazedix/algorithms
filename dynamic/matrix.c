#include <stdio.h>
#include <string.h>
#include <limits.h>

enum {
    MAXN = 7,
};

int n;

void output(int s[][MAXN], int i, int j)
{
    if( i == j)  
        printf("A%d", i);  
    else  
    {  
        printf("(");  
        output(s, i, s[i][j]);  
        output(s, s[i][j] + 1, j);  
        printf(")");  
    }  
}

int matrix(int *list)
{
    int result[MAXN][MAXN], record[MAXN][MAXN];
    memset(result, 0, MAXN * MAXN * sizeof(int));
    memset(record, 0, MAXN * MAXN * sizeof(int));
    int i, j, k, q, temp;
    for (q = 2; q <= n; q ++)
        for (i = 1; i <= n - q + 1; i ++)
        {
            j = i + q - 1;
            result[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k ++)
            {
                temp = result[i][k] + result[k+1][j] + 
                    list[i-1] * list[k] * list[j];
                if (temp < result[i][j])
                {
                    result[i][j] = temp;
                    record[i][j] = k;
                }
            }
        }
    output(record, 1, n);
    return result[1][n];
}


int main(void)
{
    int list[MAXN];
    int i;
    scanf("%d", &n);
    for (i = 0; i <= n; i ++)
        scanf("%d", &list[i]);
    int ans = matrix(list);
    printf("\nans:%d\n", ans);
    return 0;
}
