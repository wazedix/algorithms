# include<stdio.h>

int main(void)
{
	int a[15];
	int k,i,j,h,ans,b,v;
	for (i=1;i<=13;i++) a[i]=0;
	do
	{
		scanf("%d",&k);
		if (k==0) break;
		if (a[k]!=0)
		{
			printf("%d\n",a[k]);
			continue;	
		}
		for (ans=k+1;ans<=3000000;ans++)
		{
			h=1;
			b=0;
			for (i=0;i<k;i++)
			{
				h=h+ans;
				h=(h-1)%(2*k-i);
				if (h==0) h=2*k-i;
				if (h>k) continue;
				b=1;
				break;	
			}	
			if (b==0)
			{
				a[k]=ans;
				printf("%d\n",ans);
				break;
			}
		}	
	}	
	while (k!=0);	
}
