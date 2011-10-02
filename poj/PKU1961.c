#include<stdio.h>

int main(void)
{
    char a[1000001];
    int t,n,i,j,f[1000001];
    int g=0;
    while (scanf("%d",&n))
    {
        g++;
        if (n==0) return 0;
        scanf("\n");
        if (g!=1) printf("\n");
        printf("Test case #%d\n",g);
        for (i=1;i<=n;i++)
        {
            scanf("%c",&a[i]);
            f[i]=0;
        }
        t=0;
        for (i=2;i<=n;i++)
        {   
            while (t>0 && a[i]!=a[t+1]) t=f[t];
            if (a[i]==a[t+1]) t++;
            f[i]=t;
            if (f[i]>0)
                if (f[i]%(i-f[i])==0)
                    printf("%d %d\n",i,f[i]/(i-f[i])+1);
        }
    }
    return 0;
}
        

