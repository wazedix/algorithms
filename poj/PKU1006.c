#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a,b,c,d,t=0,i;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	while (a!=-1)
		{
			t=t+1;
			for (i=d+1;i<=d+21252;i++)
				{
					if ((i%23==a%23)&&
						(i%28==b%28)&&
						(i%33==c%33))
						break;
			    }
			printf("Case %d: the next triple peak occurs in %d days.\n",t,i-d);
			scanf("%d%d%d%d",&a,&b,&c,&d);
		}
	return 0;
}
					
