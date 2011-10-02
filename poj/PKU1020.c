# include<stdio.h>

int ans,s,f[170],a[17],use[17],n,m;

void search(int x)
{
	if (x==n+1)
	{	
		ans=1;
		return;
	}
	int i,j,t,min,len;
	min=s;
	for (i=1;i<=s;i++) 
		if (f[i]<min)
		{
			min=f[i];
			t=i;
		}
	len=0;
	for (i=t;i<=s;i++)
		if (f[i]==f[t])
			len++;
		else break;
	for (i=1;i<=n;i++)
		if (use[i]==0 && a[i]<=len && a[i]+min<=s)
			{
				if (a[i]==a[i-1] && use[i-1]==0) continue;
				use[i]=1;
				for (j=t;j<=t+a[i]-1;j++)
					f[j]+=a[i];
				search(x+1);
				use[i]=0;
				for (j=t;j<=t+a[i]-1;j++)
					f[j]-=a[i];
			}	
}

int main(void)
{
	a[0]=0;
	int t,i,j,k;
	scanf("%d",&m);
	for (t=1;t<=m;t++)
	{
		n=0;
		scanf("%d%d",&s,&n);
		for (i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			use[i]=0;
		}
		ans=0;
		for (i=1;i<=s;i++) f[i]=0;
		for (i=1;i<=n;i++)
			for (j=i+1;j<=n;j++)
				if (a[i]<a[j])
				{
					k=a[i];
					a[i]=a[j];
					a[j]=k;	
				}
		search(1);
		if (ans==1) printf("KHOOOOB!\n");
		else printf("HUTUTU!\n");
	}
	return 0;	
}
