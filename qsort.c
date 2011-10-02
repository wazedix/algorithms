# include<stdio.h>

int a[1000000];

void qsort(int i,int j)
{
	int l,r,t,d;
	l = i; r = j;
	d = a[(i + j) / 2];
	while (l <= r)
	{
		while (a[l] < d) l ++;
		while (a[r] > d) r --;
		if (l <= r)
		{
			t = a[l];
			a[l] = a[r];
			a[r] = t;
			l ++;
			r --;
		}
	}
	if (i < r) qsort(i,r);
	if (l < j) qsort(l,j);
}

int main(void)
{
	int n,i;
	scanf("%d",&n);
	for (i = 1; i <= n; i ++)
		scanf("%d",&a[i]);
	qsort(1,n);
	for (i = 1; i <= n; i ++)
		printf("%d\n",a[i]);
	return 0;
}
