#include<stdio.h>
#include<string.h>

int main(void)
{
    char s[400002];
    int i,g,len,t,ans[400002],f[400002];
    while(scanf("%s",&s[1])!=EOF)
    {
        f[0]=0; f[1]=0; 
        t=0;
        len=strlen(&s[1]);
        for (i=2;i<=len;i++)
        {
            while (t>0 && s[i]!=s[t+1]) t=f[t];
            if (s[i]==s[t+1]) t++;
            f[i]=t;
        }
        g=0;
        while (t>0)
        {
            g++;
            ans[g]=t;
            t=f[t];
        }
        for (i=g;i>0;i--)
            printf("%d ",ans[i]);
        printf("%d\n",len);
    }
    return 0;
}
