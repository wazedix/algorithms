#include<stdio.h>
#include<stdlib.h>

int n,m,v,ans,a[102];
char s[102][102],ss[102][102],c[102];

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
			while ((s[v][i]<=s[v][j])&&(i<=d))
				{
					c[t]=s[v][i];
					t++;
					i++;
				}
			while ((s[v][i]>s[v][j])&&(j<=r))
				{
					c[t]=s[v][j];
					t++;
					j++;
					ans=ans+d-i+1;
				}
		}
	int h;
	if (i<=d) 
		for (h=i;h<=d;h++)
			{
				c[t]=s[v][h];
				t++;
			}
	if (j<=r)
		for (h=j;h<=r;h++)
			{
				c[t]=s[v][h];
				t++;
			}		
	for (h=l;h<=r;h++)
		s[v][h]=c[h];
}

int main()
{
	scanf("%d%d\n",&n,&m);
	int i,j;
	for (i=1;i<=m;i++)
		{
			for (j=1;j<=n;j++)
				{
					scanf("%c",&s[i][j]);
					ss[i][j]=s[i][j];
				}
			if (i<m) scanf("\n");
		}
	for (v=1;v<=m;v++)
		{
			ans=0;
			guibing(1,n);
			a[v]=ans;	
		}
	for (i=1;i<=m-1;i++)
		for (j=i+1;j<=m;j++)
			if (a[i]>a[j])
				{
					for (v=1;v<=n;v++) c[v]=ss[i][v];
					for (v=1;v<=n;v++) ss[i][v]=ss[j][v];
					for (v=1;v<=n;v++) ss[j][v]=c[v];
					int y=a[i];
					a[i]=a[j];
					a[j]=y;
				}
	for (i=1;i<=m;i++)
		{
			for (j=1;j<=n;j++)
				printf("%c",ss[i][j]);
			printf(" %d",a[i]);
			printf("\n");
		}
    system("pause");
    return(0);
}
			
