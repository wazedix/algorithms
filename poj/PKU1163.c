#include<stdio.h>

int max(int x,int y)
{
    if (x>y) return x; else return y;
}

int main(void)
{
    int n,a[101][101],f[101][101],i,j;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
        for (j=1;j<=i;j++)
            scanf("%d",&a[i][j]);
    for (i=n;i>=1;i--)
        for (j=1;j<=i;j++)
            f[i][j]=max(f[i+1][j],f[i+1][j+1])+a[i][j];
    printf("%d\n",f[1][1]);
    return 0;
}
