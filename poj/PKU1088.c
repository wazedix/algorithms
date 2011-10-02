# include<stdio.h>

const int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int a[102][102],f[102][102];

int max(int a,int b)
{
	if (a>b) return a; else return b;
}

int DP(i,j)
{
	int k;
	if (f[i][j]>0) return f[i][j];
	for (k=0;k<=3;k++)
		if (a[i][j]<a[i+dir[k][1]][j+dir[k][0]])
			f[i][j]=max(f[i][j],DP(i+dir[k][1],j+dir[k][0
			])+1);
	return f[i][j];
}

int main()
{
	int r,c,i,j,ans=0;
	scanf("%d%d",&r,&c);
	for (i=0;i<=r+1;i++)
		for (j=0;j<=c+1;j++)
		{
			a[i][j]=0;
			f[i][j]=0;
		}
	for (i=1;i<=r;i++)
		for (j=1;j<=c;j++)
			scanf("%d",&a[i][j]);
	for (i=1;i<=r;i++)
		for (j=1;j<=c;j++)
		{
			f[i][j]=DP(i,j);
			if (f[i][j]>ans) ans=f[i][j];
		}
	printf("%d",ans+1);
	return 0;
}
