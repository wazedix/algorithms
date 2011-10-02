# include<stdio.h>
# include<limits.h>

long p(int v)
{
	return v*v;
}

int main()
{
	int i,x,y,z,mx,my,mz,a[20][3];
	long f,min;
	for (i=1;i<=16;i++)
		scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
	scanf("%d%d%d",&x,&y,&z);
	while (x!=-1)
	{
		min=LONG_MAX;
		for (i=1;i<=16;i++)
		{
			f=p(a[i][1]-x)+p(a[i][2]-y)+p(a[i][3]-z);
			if (f<min) 
			{
				min=f;
				mx=a[i][1];
				my=a[i][2];
				mz=a[i][3];
			}	
		}
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n",x,y,z,mx,my,mz);
		scanf("%d%d%d",&x,&y,&z);	
	}
	return 0;
}
