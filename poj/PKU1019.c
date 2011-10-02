# include<stdio.h>

int main()
{
	long long n,s,v,vv,ans,vvv,vvvv;
	int i,j,t,ss[100];
	scanf("%d",&t);
	while (t>=1)
	{
		scanf("%lld",&n);
		s=0; v=1; vvvv=0;
		while (s+v+vvvv<n)
		{
			s=s+v+vvvv;
			v++;	
			vv=v;
			vvv=0;
			while (vv>=10)
			{
				vvv++;
				vv=vv/10;	
			}
			vvvv+=vvv;
		}
		ans=n-s;
		s=0; v=1; vvv=1; 
		while (s+vvv<ans)
		{
			s=s+vvv;
			v++;	
			vv=v;
			vvv=0;
			while (vv>0)
			{
				vvv++;
				vv=vv/10;
			}
		}
		ans=ans-s;
		vv=0;
		while (v>0)
		{
			vv++;
			ss[vv]=v%10;
			v=v/10;
		}
		printf("%d\n",ss[vv+1-ans]);
		t--;	
	}	
	return 0;
}
