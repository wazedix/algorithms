# include<stdio.h>

long n,m,a[2000],b[2000];

long abs(long x)
{
	if (x>0) return x; else return -1*x;
}

long what(long x,long y)
{
	if (x<=0 || x>b[m]) x=y;
	long l,r,d;
	l=1; r=m;
	while (r-l>1)
	{
		d=(l+r)/2;
		if (b[d]>=x) r=d;
		else l=d;
	}
	if (b[l]>=x) return a[l];
	else return a[r]; 
}

long end(long x)
{
	if (x<0) return 0; 
	if (x>b[m]) return x+n+1;
	long l,r,d;
	l=1; r=m;
	while (r-l>1)
	{
		d=(l+r)/2;
		if (b[d]>=x) r=d;
		else l=d;
	}
	if (b[l]>=x) return b[l];
	else return b[r]; 
}

long max(long x,long y)
{
	if (x>y) return x; else return y;
}

long min(long x,long y)
{
	if (x>y) return y; else return x;
}

int main(void)
{
	long i,j,l,r,x,y,ans,ans1,ans2,ll,lll,len;
	while (scanf("%d",&n))
	{
		printf("%d\n",n);
		if (n==0) break;
		m=0; b[0]=0;
		while (scanf("%d%d",&x,&y))
		{	
			if (x==0 && y==0) break;
			m++;
			a[m]=x;
			b[m]=y+b[m-1];
		}
		if (n==1) n=b[m];
		l=1;
		ans1=-1;
		while (l<=b[m])
		{
			ll=l-n-1;
			lll=l+n-1;
			if (what(l,l)==what(l-1,l) &&
				what(l,l)==what(l+1,l) && 
				end(ll)-ll-1>0 &&
				end(lll)-lll-1>0 &&
				(l-1)%n!=0 && l!=b[m])
			{
				len=min(end(l)-l,
					min(end(ll)-ll-1,
					   (end(lll)-lll-1)));
				ans=max(abs(what(l,l)-what(ll,l)),
						abs(what(l,l)-what(lll,l)));
				l+=len;
			}
			else
			{
				len=1;
				if ((l-1)%n==0) 
					ans=max(abs(what(l,l)-what(l+1,l)),
						max(abs(what(l,l)-what(l-n,l)),
						max(abs(what(l,l)-what(l-n+1,l)),
						max(abs(what(l,l)-what(l+n,l)),
							abs(what(l,l)-what(l+n+1,l))))));	
				else if (l%n==0)
					ans=max(abs(what(l,l)-what(l-1,l)),
						max(abs(what(l,l)-what(l-n,l)),
						max(abs(what(l,l)-what(l-n-1,l)),
						max(abs(what(l,l)-what(l+n,l)),
						   (abs(what(l,l)-what(l+n-1,l)))))));
				else
					ans=max(abs(what(l,l)-what(l-1,l)),
						max(abs(what(l,l)-what(l+1,l)),
						max(abs(what(l,l)-what(l-n,l)),
						max(abs(what(l,l)-what(l-n-1,l)),
						max(abs(what(l,l)-what(l-n+1,l)),
						max(abs(what(l,l)-what(l+n,l)),
						max(abs(what(l,l)-what(l+n-1,l)),
							abs(what(l,l)-what(l+n+1,l)))))))));
				l++;
			}
			if (ans==ans1) 
				ans2+=len;
			else 
			{
				if (ans1!=-1)
					printf("%d %d\n",ans1,ans2);	
				ans1=ans;
				ans2=len;
			}
		}	
		printf("%d %d\n",ans1,ans2);
		printf("0 0\n");
	}
	return 0;	
}
