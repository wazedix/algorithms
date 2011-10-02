#include<stdio.h>
#include<math.h>
#define PI 3.14
int main()
{
    int n,i,j;
    float x,y;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
      {
        scanf("%f%f",&x,&y);
        int s=0,ans=0;
        while ((s*2/PI)<(x*x+y*y))
          {
              ans=ans+1;
              s=s+50;
          }
        printf("Property %d: This property will begin eroding in year %d.\n",i,ans);
      }
    printf("END OF OUTPUT.\n");
    return 0;
}
        
