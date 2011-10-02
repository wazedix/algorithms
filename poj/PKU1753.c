#include<stdio.h>
#include<stdlib.h>

const dir[5][2] = {{0,0},{-1,0},{1,0},{0,-1},{0,1}};
char map[5][5];
int ans;

void change(int x,int y)
{
    int i,xx,yy;
    for (i = 0; i < 5; i ++)
    {
        xx = x + dir[i][0];
        yy = y + dir[i][1];
        if (xx >= 0 && xx <= 3 && yy >= 0 && yy <= 3)
        {
            if (map[xx][yy] == 'b')
                map[xx][yy] = 'w';
            else
                map[xx][yy] = 'b';
        }
    }          
}

void result(int z)
{
    int i,j,l = 0,r = 0;
    for (i = 0; i < 4; i ++)
        for (j = 0; j < 4; j ++)
        {
            if (map[i][j] != 'b') 
                l = 1;
            if (map[i][j] != 'w')
                r = 1;
            if (l*r > 0) return;   
        }
    if (z < ans) ans = z;
}

void search()
{
    int k[16],i,z = 0;
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
        for (i = 0; i < 16; i ++)
            if (k[i] == 1)
            {
                z ++;
                change(i / 4,i % 4);
            }
        result(z);
        for (i = 0; i < 16; i ++)
            if (k[i] == 1)
            {
                z --;
                change(i / 4,i % 4);
            }
    }
}

int main(void)
{
    int i,j;
    ans = 20;
    for (i = 0; i < 4; i ++)
        scanf("%s",map[i]);
    search();
    if (ans == 20)
        printf("Impossible\n");
    else 
        printf("%d\n",ans);
    return 0;
}
