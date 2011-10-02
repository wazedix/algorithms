#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int i,j,n;
char s[200];
long long a[100002];
	
void qsortt(int i,int j)
{
	int l,r,t,d;
	l=i; r=j;
	d=a[(i+j)/2];
	while (l<=r)
		{
			while (a[l]<d) l++;
			while (a[r]>d) r--;
			if (l<=r)
				{
					t=a[l];
					a[l]=a[r];
					a[r]=t;
					l++;
					r--;
				}
		}
	if (i<r) qsortt(i,r);
	if (l<j) qsortt(l,j);
}

int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		{
			scanf("%s",s);
			for (j=0;j<strlen(s);j++)
		    	{
					if ((s[j]<='9') && (s[j]>='0')) 
						a[i]=a[i]*10+s[j]-'0';
					if ((s[j]>='a') && (s[j]<='z'))
					    s[j]=s[j]-32;
					if ((s[j]=='A')||(s[j]=='B')||(s[j]=='C'))
						a[i]=a[i]*10+2 ;
					if ((s[j]=='D')||(s[j]=='E')||(s[j]=='F'))
						a[i]=a[i]*10+3 ;
					if ((s[j]=='G')||(s[j]=='H')||(s[j]=='I'))
						a[i]=a[i]*10+4 ;
					if ((s[j]=='J')||(s[j]=='K')||(s[j]=='L'))
						a[i]=a[i]*10+5 ;
					if ((s[j]=='M')||(s[j]=='N')||(s[j]=='O'))
						a[i]=a[i]*10+6 ;
					if ((s[j]=='P')||(s[j]=='R')||(s[j]=='S'))
						a[i]=a[i]*10+7 ;
					if ((s[j]=='T')||(s[j]=='U')||(s[j]=='V'))
						a[i]=a[i]*10+8 ;
					if ((s[j]=='W')||(s[j]=='X')||(s[j]=='Y'))
						a[i]=a[i]*10+9 ;
				}
		}
	qsortt(1,n);
	a[0]=-1;
	a[n+1]=-1;
	int m=1,v=0;
	for (i=2;i<=n+1;i++)
		if (a[i]!=a[i-1])
			{
			    if (m>1)
					{
						if (a[i-1]<1000000) printf("0");
						if (a[i-1]<100000) printf("0");
						printf("%d-",a[i-1]/10000);
						if (a[i-1]%10000<1000) printf("0");
						if (a[i-1]%10000<100) printf("0");
						if (a[i-1]%10000<10) printf("0");
						printf("%d ",a[i-1]%10000);
						printf("%d\n",m);
						v=1;
					}
				m=1; 
			}
		else m++;
	if (v==0) printf("No duplicates.\n");
	system("pause");
	return(0);
}
	
