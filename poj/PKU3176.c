# include<stdio.h>

int max(int x,int y)
{
	if (x>y) return x; else return y;
}

int main(void)
{
	int n,i,j,ans=0;
	int a[351][351],f[351][351];
	scanf("%d",&n);
	for (i=0;i<=n+1;i++)
		for (j=0;j<=n+1;j++)
			f[i][j]=0;
	for (i=1;i<=n;i++)
		for (j=1;j<=i;j++)
		{
			scanf("%d",&a[i][j]);
			f[i][j]=max(f[i-1][j],f[i-1][j-1])+a[i][j];
			if (f[i][j]>ans) ans=f[i][j];
		}
	printf("%d",ans);
	return 0;
}
