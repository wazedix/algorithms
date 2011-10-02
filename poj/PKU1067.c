# include<stdio.h>
# include<math.h>

int main(void)
{
	int a,b,t,d;
	while (scanf("%d%d",&a,&b)==2)
	{
		if (a>b)
		{
			t=a;
			a=b;
			b=t;	
		}
		d=b-a;
		if ((floor)(d*((1.0+sqrt(5.0))/2.0))==a) 
			printf("0\n");
		else printf("1\n");
	}
	return 0;	
}
