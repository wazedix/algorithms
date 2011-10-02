#include<stdio.h>

int main()
{
    char s[7];
    int l,r,i,j,t,n,ss[7]={0},a[1000]={0},c[1000]={0};
    ss[0]=5;
    while (scanf("%s%d",s,&n)!=EOF)
          {
            int t=1;
            j=1;
            for (i=5;i>=0;i=i-1)
                {
                  if (s[i]=='.')
                        t=5-i;
                  else
                      {
                        ss[j]=s[i]-'0';
                        j=j+1;
                      }
                }
            for (i=0;i<=999;i++)
              a[i]=0;
            a[0]=1; a[1]=1;
            for (i=1;i<=n;i++)
                {  
                  for (j=0;j<=999;j++)
                    c[j]=0;
                  for (l=1;l<=ss[0];l++)
                  for (r=1;r<=a[0];r++)
                      {
                        c[l+r-1]=c[l+r-1]+a[r]*ss[l];
                        c[l+r]=c[l+r]+c[l+r-1]/10;
                        c[l+r-1]=c[l+r-1]%10;
                      }
                  if (c[a[0]+ss[0]]!=0) c[0]=a[0]+ss[0]; else c[0]=a[0]+ss[0]-1; 
                  for (j=0;j<=c[0];j++)
                    a[j]=c[j];                               
                }
            int m=0;
            for (i=1;i<=t*n;i++)
              if (c[i]==0) m=i; else break;
            m=m+1;
            if (c[c[0]]==0) c[0]=c[0]-1;
            for (i=c[0];i>=m;i=i-1)
              {
                if (i==t*n) printf(".");
                printf("%d",c[i]);
              }
            printf("\n");
          }
    return 0;
}    
               
               
