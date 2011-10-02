# include<stdio.h>

int main(void)
{
	int a,b,c,d,e,f,i,j,ans,aa,bb,cc[5];
    while (scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f))
    {
        if (a==0 && b==0 && c==0 && d==0 && e==0 && f==0) break;
		ans=f+e+d+(c+3)/4;
		cc[0]=0; cc[1]=5; cc[2]=3; cc[3]=1;
		bb=b-d*5-cc[c%4];
		if (bb>0) ans+=(bb+8)/9;
		aa=a-(ans*36-f*36-e*25-d*16-c*9-b*4);
		if (aa>0) ans+=(aa+35)/36;
		printf("%d\n",ans);
	}
	return 0;
}
