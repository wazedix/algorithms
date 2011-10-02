#include<stdio.h>
#include<stdlib.h>

char map[5][5],a[5][5];
int que[20];
int ans;

void change(int x,int y)
{
    int i,j;
    for (i = 0; i < 5; i ++)
    {
        if (map[x][i] == '-')
            map[x][i] = '+';
        else
            map[x][i] = '-';
        if (i != x)
        {
            if (map[i][y] == '-')
                map[i][y] = '+';
            else
                map[i][y] = '-';
        }
    }
}

void result(int z)
{
    int i,j,l = 0,r = 0;
    for (i = 0; i < 4; i ++)
        for (j = 0; j < 4; j ++)
        {
            if (map[i][j] != '-') 
                return;   
        }
    if (z < ans) 
    {
        ans = z;
        printf("%d\n",ans);
        for (i = 1; i <= ans; i ++)
            printf("%d %d\n",que[i] / 4 + 1,que[i] % 4 + 1);
        exit(0);
    }
}

void search()
{
    int k[16],i,j,z;
    for (k[0] = 0; k[0] <=1; k[0] ++)
    for (k[1] = 0; k[1] <=1; k[1] ++)
    for (k[2] = 0; k[2] <=1; k[2] ++)
    for (k[3] = 0; k[3] <=1; k[3] ++)
    for (k[4] = 0; k[4] <=1; k[4] ++)
    for (k[5] = 0; k[5] <=1; k[5] ++)
    for (k[6] = 0; k[6] <=1; k[6] ++)
    for (k[7] = 0; k[7] <=1; k[7] ++)
    for (k[8] = 0; k[8] <=1; k[8] ++)
    for (k[9] = 0; k[9] <=1; k[9] ++)
    for (k[10] = 0; k[10] <=1; k[10] ++)
    for (k[11] = 0; k[11] <=1; k[11] ++)
    for (k[12] = 0; k[12] <=1; k[12] ++)
    for (k[13] = 0; k[13] <=1; k[13] ++)
    for (k[14] = 0; k[14] <=1; k[14] ++)
    for (k[15] = 0; k[15] <=1; k[15] ++)
    {
        z = 0;
        for (i = 0; i < 16; i ++)
            if (k[i] == 1)
            {
                z ++;
                que[z] = i;
                change(i / 4,i % 4);
            }
        result(z);
        for (i = 0; i < 4; i ++)
            for (j = 0; j < 4; j ++)
                map[i][j] = a[i][j]; 
    }
}

int main(void)
{
    int i,j;
    ans = 20;
    for (i = 0; i < 4; i ++)
        scanf("%s",a[i]);
    search();
    return 0;
}
