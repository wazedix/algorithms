#include<stdio.h>

int n,v,t,a[65],b[65];

void qsort(int i, int j)
{
	int l,r,d,t;
	l=i; r=j;
	d=a[(l+r)/2];
	do
	{
		while (a[l]>d) l++;
		while (a[r]<d) r--;
		if (l<=r)
		{
			t=a[l];
			a[l]=a[r];
			a[r]=t;
			l++;
			r--;
		}
	}
	while (l<=r);
	if (l<j) qsort(l,j);
	if (i<r) qsort(i,r);
}

int search(int x, int y, int z)
{
	int v;
	if (y==0) 
		return 1;
	int i;
	for (i=z;i<=n;i++)
		if ((b[i]>0) && (a[i]<=x))
		{
			b[i]=b[i]-1;
			if (a[i]==x) 
				v=search(t,y-1,1);
			else v=search(x-a[i],y,z);
			if (v==1) return 1;
			b[i]++;
			if (x==t) return 0;
		}
	return 0;
}
			

int main()
{
	scanf("%d",&n);
	while (n!=0)
	{
		int i,j,s=0,max=0;
		for (i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			b[i]=1;
			s=s+a[i];
			if (a[i]>max) max=a[i];
		}
		qsort(1,n);
		for (i=1;i<=n;i++)
			if (a[i]==a[i-1])
			{
				b[i-1]=b[i-1]+1;
				n--;
				i--;
				for (j=i;j<=n;j++)
					a[j]=a[j+1];
			}
		for (t=max;t<=s;t++)
		{
			if (s%t==0)			
			{	if (search(t,s/t,1)==1) 
		  		{
					printf("%d\n",t);
					break;
				}
			}
		}
		scanf("%d",&n);
	}
	return 0;
}
