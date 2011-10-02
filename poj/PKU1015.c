# include<stdio.h>
# include<limits.h>
# define MAXV 900
# define MINV 100
# define ZERO 500

int abs(int x)
{
	if (x<0) return -1*x; else return x;	
}

int main(void)
{
	int v=0,i,j,k,ans1,ans2,ans,n,m,min,max,mm,t,yes;
	int q[21],a[201][2],c[201],f[21][1000],g[21][1000];
	while (scanf("%d%d",&n,&m))
	{
		if (n==0 && m==0) break;
		for (i=1;i<=n;i++)
		{
			scanf("%d%d",&a[i][1],&a[i][2]);
			c[i]=a[i][1]-a[i][2];
		}
		for (i=0;i<=m;i++)
			for (j=0;j<=MAXV+MINV;j++)
				f[i][j]=-1;
		f[0][ZERO]=0;
		for (i=1;i<=m;i++)
			for (k=1;k<=n;k++)
				for (j=MINV;j<=MAXV;j++)	
					if (f[i-1][j-c[k]]>=0 &&
						f[i-1][j-c[k]]+a[k][1]+a[k][2]>f[i][j])
					{
						yes=1;
						mm=i-1;
						ans=j-c[k];
						while (mm>0)
						{
							t=g[mm][ans];
							ans=ans-c[t];
							if (t==k) yes=0;
							mm--;
						}
						if (yes==1)
						{
							f[i][j]=f[i-1][j-c[k]]+a[k][1]+a[k][2];
							g[i][j]=k;
						}	
					}
		min=INT_MAX;
		max=INT_MIN;
		for (i=MINV;i<=MAXV;i++)
			if (f[m][i]>=0)
				if (abs(i-ZERO)<min ||
					(abs(i-ZERO)==min && f[m][i]>max))
				{
					min=abs(i-ZERO);
					max=f[m][i];
					ans=i;
				}
		ans1=0; ans2=0;
		mm=m;
		while (mm>0)
		{
			q[mm]=g[mm][ans];
			ans1+=a[q[mm]][1];
			ans2+=a[q[mm]][2];
			ans=ans-c[q[mm]];
			mm--;
		}	
		for (i=1;i<=m;i++)
			for (j=1;j<i;j++)
				if (q[i]<q[j])
				{
					k=q[i];
					q[i]=q[j];
					q[j]=k;
				}
		v++;
		printf("Jury #%d\n",v);
		printf("Best jury has value %d for prosecution and value %d for defence:\n",ans1,ans2);
		for (i=1;i<=m;i++)
			printf(" %d",q[i]);
		printf("\n\n");	
	}
	return 0;	
}
