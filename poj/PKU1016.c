# include<stdio.h>
# include<string.h>

char s[20][100],ss[100];
int f[10],len[20];

int check(int x,int y)
{
	int i,j;
	if (len[x]!=len[y]) return 0;
	for (i=0;i<len[x];i++)
		if (s[x][i]!=s[y][i]) return 0;
	return 1;
}

int main(void)
{
	int i,j,t,tt,v,yes;
	while (gets(s[0]))
	{
		if (s[0][0]=='-') break;
		len[0]=strlen(s[0]);
		for (v=1;v<=16;v++)
		{
			if (v==16)
			{
				printf("%s can not be classified after 15 iterations\n",s[0]);	
				break;
			}
			for (i=0;i<10;i++) f[i]=0;
			for (i=0;i<=len[v-1];i++) f[(int)(s[v-1][i]-'0')]++;	
			t=0;	
			for (i=9;i>=0;i--)
				if (f[i]>0)
				{
					t++; 
					ss[t]='0'+i;
					while (f[i]>0)
					{
						t++;
						ss[t]=f[i]%10+'0';
						f[i]=f[i]/10;	
					}
				}
			len[v]=t;
			for (i=0;i<=t;i++) s[v][i]=ss[t-i];
			yes=0;
			for (i=0;i<v;i++)
				if (check(i,v)==1) 
					if (v==1)
					{
						printf("%s is self-inventorying\n",s[0]);	
						yes=1;
						break;
					}
					else if (i==v-1)
					{
						printf("%s is self-inventorying after %d steps\n",s[0],v-1);
						yes=1;
						break;	
					}
					else
					{
						printf("%s enters an inventory loop of length %d\n",s[0],v-i);
						yes=1;
						break;	
					}
			if (yes==1) break;
		}	
	}
	return 0;	
}

