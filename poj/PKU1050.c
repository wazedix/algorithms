# include<stdio.h>

int main()
{
	int n,i,j,k,ans=0;
	int a[102][102],s[102][102],f[102];
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		s[i][0]=0;
		for (j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			s[i][j]=s[i][j-1]+a[i][j];
		}
	}
	for (i=1;i<=n;i++)
		for (j=i;j<=n;j++)
		{
			f[0]=0;
			for (k=1;k<=n;k++)
			{
				if (f[k-1]>0)
					f[k]=f[k-1]+s[k][j]-s[k][i-1];
				else f[k]=s[k][j]-s[k][i-1];
				if (f[k]>ans) ans=f[k];
			}
		}
	printf("%d",ans);
	return 0;
}
