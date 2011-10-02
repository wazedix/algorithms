# include<stdio.h>
# include<limits.h>

int n,m,a[101][101],b[101][101];

int search(int x)
{
	int i,j,p,sum=0;
	for (i=1;i<=n;i++)
	{
		p=INT_MAX;
		for (j=1;j<=a[i][0];j++)
			if (a[i][j]>=x && b[i][j]<p) p=b[i][j];
		if (p==INT_MAX) return -1;
		sum+=p; 	
	}
	return sum;
}

int main(void)
{
	int i,j,t;
	float ans,s;
	scanf("%d",&m);
	for (t=1;t<=m;t++)
	{
		ans=0;
		scanf("%d",&n);
		for (i=1;i<=n;i++)
		{
			scanf("%d",&a[i][0]);
			for (j=1;j<=a[i][0];j++)
				scanf("%d%d",&a[i][j],&b[i][j]);	
		}
		for (i=1;i<=n;i++)
			for (j=1;j<=a[i][0];j++)
			{
				s=search(a[i][j]);
				if (s!=-1)
					if (a[i][j]/s>ans) 
						ans=a[i][j]/s;
			}
		printf("%.3f\n",ans);
	}
	system("pause");
	return 0;
}
