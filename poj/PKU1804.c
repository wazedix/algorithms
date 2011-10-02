# include<stdio.h>

int ans,a[1001],c[1001];

void guibing(int l,int r)
{
	int d=(l+r)/2;
	if (r-l>=2)
		{
			guibing(l,d);
			guibing(d+1,r);
		}
	int i=l,j=d+1,t=l;
	while ((i<=d)&&(j<=r))
		{
			while ((a[i]<=a[j])&&(i<=d))
				{
					c[t]=a[i];
					t++;
					i++;
				}
			while ((a[i]>a[j])&&(j<=r))
				{
					c[t]=a[j];
					t++;
					j++;
					ans=ans+d-i+1;
				}
		}
	int h;
	if (i<=d) 
		for (h=i;h<=d;h++)
			{
				c[t]=a[h];
				t++;
			}
	if (j<=r)
		for (h=j;h<=r;h++)
			{
				c[t]=a[h];
				t++;
			}		
	for (h=l;h<=r;h++)
		a[h]=c[h];
}

int main(void)
{
	int i,j,k,n,m;
	scanf("%d",&n);
	for (k=1;k<=n;k++)
	{
		scanf("%d",&m);
		for (i=1;i<=m;i++)
			scanf("%d",&a[i]);	
		ans=0;
		guibing(1,m);
		printf("Scenario #%d:\n%d\n\n",k,ans);
	}
	return 0;
}
