# include<stdio.h>

int main(void)
{
	int num,a[7],i,j,s,t,f[130000];
	num=0;
	while (scanf("%d%d%d%d%d%d",&a[1],&a[2],&a[3],&a[4],&a[5],&a[6]))
	{
		if (a[1]==0 && a[2]==0 && a[3]==0 && a[4]==0 && a[5]==0 && a[6]==0) break;
		num++;
		s=0;
		for (i=1;i<=6;i++) s+=a[i]*i;
		if (s%2!=0)
		{
			printf("Collection #%d:\nCan't be divided.\n\n",num);
			continue;
		}
		s=s/2;
		for (i=0;i<=s;i++) f[i]=0; f[0]=1;
		for (i=1;i<=6;i++)
		{
			t=1;
			while (t*2<=a[i])
			{
				for (j=s;j>=t*i;j--) f[j]=f[j-t*i] | f[j];
				t=t*2;
			}	
			t=a[i]-t+1;
			for (j=s;j>=t*i;j--) f[j]=f[j-t*i] | f[j];
		}		
		if (f[s]==1)
			printf("Collection #%d:\nCan be divided.\n\n",num);
		else
			printf("Collection #%d:\nCan't be divided.\n\n",num);
	}
	system("pause");
	return 0;	
}
