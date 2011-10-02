# include<stdio.h>

long long ans;
int queue[500005],temp[500005];

void mergesort(int l,int r)
{
	int d = (l + r) / 2;
	if (r - l >= 2)
	{
		mergesort(l,d);
		mergesort(d + 1,r);
	}
	int i = l,j = d + 1,t = l;
	while ((i <= d) && (j <= r))
	{
		while ((queue[i] <= queue[j]) && (i <= d))
		{
			temp[t] = queue[i];
			t ++;
			i ++;
		}
		while ((queue[i] > queue[j]) && (j <= r))
		{
			temp[t] = queue[j];
			t ++;
			j ++;
			ans = ans + d - i + 1;
		}
	}
	int k;
	if (i <= d) 
		for (k = i ; k <= d ; k ++)
		{
			temp[t]=queue[k];
			t++;
		}
	if ( j<= r)
		for (k = j ; k <= r ; k ++)
	    {
			temp[t] = queue[k];
			t ++;
		}	
	for (k = l ; k <= r ; k ++)
		queue[k] = temp[k];
}

int main(void)
{
	int i,j,k,n,m;
	while(scanf("%d",&n))
    {
        if (n == 0) return 0;
	    for (i = 1 ; i <= n ; i ++)
			scanf("%d",&queue[i]);	
		ans = 0;
		mergesort(1,n);
		printf("%lld\n",ans);
    }
}
