#include<stdio.h>
#include<math.h>

int main(void)
{
    double n,p;
    double k;
    while (scanf("%lf%lf",&n,&p)!=EOF) 
    {
        k = pow(p,1/n);
        printf("%.0lf\n",k);
    }
    return 0;
}
