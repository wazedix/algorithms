#include<stdio.h>
#include<string.h>

int main(void)
{
    long i,j,k,n,m,f[21][8001],a[21],b[21];
    scanf("%ld%ld",&n,&m);
    for (i = 1; i <= n; i ++)
        scanf("%ld",&a[i]);
    for (i = 1; i <= m; i ++)
        scanf("%ld",&b[i]);
    memset(f,0,sizeof(f));
    f[0][4000] = 1;
    for (i = 1; i <= m; i ++)
        for (j = 1; j <= n; j ++)
            for (k = 0; k <= 8000; k ++)
                if (k + a[j] * b[i] <= 8000 && k + a[j] * b[i] >=0)
                    if (f[i - 1][k + a[j] * b[i]] >= 1)
                        f[i][k] += f[i-1][k + a[j] * b[i]];
    printf("%ld\n",f[m][4000]);
    return 0;
}

