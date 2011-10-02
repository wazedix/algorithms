# include<stdio.h>

char a[20],b[20],c[20];

void light(char x)
{
	int t,k,ans; 
	t=0,k=1,ans=0;
	while ((a[t]!='e') && (a[t]!='u') && (a[t]!='d'))
	{
		if (a[t]==' ') k++;
		if (a[t]==x) ans=k;t++;
	} 
	if ((a[t]=='e') && (ans!=0)) return;
	if ((a[t]=='u') && (ans!=2)) return;
	if ((a[t]=='d') && (ans!=1)) return;
	t=0,k=1,ans=0;
	while ((b[t]!='e') && (b[t]!='u') && (b[t]!='d'))
	{
		if (b[t]==' ') k++;
		if (b[t]==x) ans=k;t++;
	} 
	if ((b[t]=='e') && (ans!=0)) return;
	if ((b[t]=='u') && (ans!=2)) return;
	if ((b[t]=='d') && (ans!=1)) return;
	t=0,k=1,ans=0;
	while ((c[t]!='e') && (c[t]!='u') && (c[t]!='d'))
	{
		if (c[t]==' ') k++;
		if (c[t]==x) ans=k;t++;
	} 
	if ((c[t]=='e') && (ans!=0)) return;
	if ((c[t]=='u') && (ans!=2)) return;
	if ((c[t]=='d') && (ans!=1)) return;
	printf("%c is the counterfeit coin and it is light.\n",x);
}

void heavy(char x)
{
	int t,k,ans; 
	t=0,k=1,ans=0;
	while ((a[t]!='e') && (a[t]!='u') && (a[t]!='d'))
	{
		if (a[t]==' ') k++;
		if (a[t]==x) ans=k;t++;
	} 
	if ((a[t]=='e') && (ans!=0)) return;
	if ((a[t]=='u') && (ans!=1)) return;
	if ((a[t]=='d') && (ans!=2)) return;
	t=0,k=1,ans=0;
	while ((b[t]!='e') && (b[t]!='u') && (b[t]!='d'))
	{
		if (b[t]==' ') k++;
		if (b[t]==x) ans=k;t++;
	} 
	if ((b[t]=='e') && (ans!=0)) return;
	if ((b[t]=='u') && (ans!=1)) return;
	if ((b[t]=='d') && (ans!=2)) return;
	t=0,k=1,ans=0;
	while ((c[t]!='e') && (c[t]!='u') && (c[t]!='d'))
	{
		if (c[t]==' ') k++;
		if (c[t]==x) ans=k;t++;
	} 
	if ((c[t]=='e') && (ans!=0)) return;
	if ((c[t]=='u') && (ans!=1)) return;
	if ((c[t]=='d') && (ans!=2)) return;
	printf("%c is the counterfeit coin and it is heavy.\n",x);
}

int main()
{
	int i,t,n;
	scanf("%d\n",&n);
	for (t=1;t<=n;t++)
	{
		gets(a);
		gets(b);
		gets(c);
		for (i=0;i<=11;i++)
		{
			light('A'+i);
			heavy('A'+i);	
		}	
	}
	return 0;
}
