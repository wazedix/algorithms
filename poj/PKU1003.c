#include<stdio.h>
int main()
{
    float a;
    scanf("%f",&a);
    while 
    (a!=0)
      {
          float s=0;
          float t=1;
          while (s<a)
            {
                t=t+1;
                s=s+1/t;
            }
          int ans=t-1;
          printf("%d card(s)\n",ans);
          scanf("%f",&a);
      }
    return 0;
}
