#include<stdio.h>
int main()
{
    int i;
    float c=0;
    float a[12];
    for (i=0;i<12;i=i+1)
        {
         scanf("%f",&a[i]);
         c=c+a[i];
        }
    printf("$%.2f",c/12);
    return 0;
}
