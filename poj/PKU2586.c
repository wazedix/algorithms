#include<stdio.h>

int main(void)
{
    long n,m;
    while (scanf("%ld%ld",&n,&m) != EOF)
    {
        if (4*n < m)
            if (10 * n - 2 * m > 0)
                printf("%ld\n",10 * n - 2 * m);
            else 
                printf("Deficit\n");
        else if (3 * n < 2 * m)
            if (8 * n - 4 * m > 0)
                printf("%ld\n",8 * n - 4 * m);
            else
                printf("Deficit\n");
        else if (2 * n < 3 * m)
            if (6 * n - 6 * m > 0)
                printf("%ld\n",6 * n - 6 * m);
            else 
                printf("Deficit\n");
        else if (n < 4 * m)
            if (3 * n - 9 * m > 0)
                printf("%ld\n",3 * n - 9 * m);
            else 
                printf("Deficit\n");
        else
            printf("Deficit\n");
    }
    return 0;
}
