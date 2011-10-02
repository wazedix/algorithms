# include<stdio.h>

int total(int x1,int x2,int x3,int x4)
{
	int s=4;
	if (x1==x2 || x1==0) s--;
	if (x2==x3 || x2==0) s--;
	if (x3==x4 || x3==0) s--;	
	return s;
}

int sum(int x1,int x2,int x3,int x4)
{
	int s=0;
	if (x1!=0) s++;
	if (x2!=0) s++;
	if (x3!=0) s++;
	if (x4!=0) s++;
	return s;
}

int main(void)
{
	int a[300],num,t,i,j,n1,n2,n3,n4,ans1,ans2,ans3,ans4,s,tot,yes,tie,mn;
	a[0]=0;
	while (scanf("%d",&t)==1)
	{
		num=0;
		while (t!=0)
		{
			num++;
			a[num]=t;	
			scanf("%d",&t);
		}	
		for (i=1;i<=num;i++)
			for (j=i+1;j<=num;j++)
				if (a[i]>a[j])
				{
					t=a[i];
					a[i]=a[j];
					a[j]=t;
				}
		while (scanf("%d",&t))
		{
			yes=0;
			tot=0; s=5; mn=0;	
			if (t==0) break;
			for (n1=0;n1<=num;n1++)
				for (n2=n1;n2<=num;n2++)
					for (n3=n2;n3<=num;n3++)
						for (n4=n3;n4<=num;n4++)
							if (a[n1]+a[n2]+a[n3]+a[n4]==t)
								if (total(n1,n2,n3,n4)>tot ||
									(total(n1,n2,n3,n4)==tot && sum(n1,n2,n3,n4)<s) ||
									(total(n1,n2,n3,n4)==tot && sum(n1,n2,n3,n4)==s && n4>mn))
								{
									tot=total(n1,n2,n3,n4);
									s=sum(n1,n2,n3,n4);
									mn=n4;
									ans1=n1;
									ans2=n2;
									ans3=n3;
									ans4=n4;
									yes=1;
									tie=0;
								}
								else if (total(n1,n2,n3,n4)==tot && sum(n1,n2,n3,n4)==s && n4==mn)
									tie=1;
			printf("%d ",t);
			if (yes==0) printf("---- none\n");
			else
				if (tie==1) printf("(%d): tie\n",tot);
				else 
				{
					printf("(%d):",tot);
					if (ans1!=0) printf(" %d",a[ans1]);	
					if (ans2!=0) printf(" %d",a[ans2]);	
					if (ans3!=0) printf(" %d",a[ans3]);	
					if (ans4!=0) printf(" %d",a[ans4]);
					printf("\n");	
				}
		}
	}
	return 0;
}
