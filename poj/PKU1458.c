#include <stdio.h>
#include <string.h>

#define MAX(x, y) ((x) > (y) ? (x) : (y))

enum {
    MAX_N = 10000,
};

int main()
{
    int i, j;
    char str_a[MAX_N], str_b[MAX_N];
    int result1[MAX_N], result2[MAX_N];
    while (scanf("%s %s\n", str_a + 1, str_b + 1) == 2)
    {
        memset(result1, 0, MAX_N*sizeof(int));
        memset(result2, 0, MAX_N*sizeof(int));
        for (i = 1; str_b[i] != '\0'; i ++)
        {
            for (j = 1; str_a[j] != '\0'; j ++)
            {
                result2[j] = MAX(result2[j-1], result1[j]);
                if (str_a[j] == str_b[i])
                    result2[j] = MAX(result2[j], result1[j-1] + 1);
            }
            for (j = 1; str_a[j] != '\0'; j ++)
                result1[j] = result2[j];
        }
        printf("%d\n", result1[strlen(str_a+1)]);
        }
        return 0;
}
