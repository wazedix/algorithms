#include <stdio.h>

int hash(int x)
{
    return (17 * x + 78941) % 31247 % 19891;
}

int main(void)
{
    int x;
    scanf("%d", &x);
    int y = hash(x);
    printf("%d\n", y);
    return 0;
}
