#include<stdio.h>
#include<string.h>

int main(void)
{
    char s[1000002];
    int t,i,len,f[1000002];
    while (scanf("%s",&s[1]))
    {
        if (s[1]=='.') return 0;
        len=strlen(&s[1]);
        t=0;
        f[0]=0; f[1]=0;
        for (i=2;i<=len;i++)
        {
            while (t>0 && s[i]!=s[t+1]) t=f[t];
            if (s[i]==s[t+1]) t++;
            f[i]=t;
        }
        if (f[len]%(len-f[len])==0)
            printf("%d\n",f[len]/(len-f[len])+1);
        else 
            printf("1\n");
    }
    return 0;
}


