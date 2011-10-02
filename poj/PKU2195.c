#include<stdio.h>
#include<string.h>
#include<limits.h>

const dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
char map[105][105];
int end[105],num[105][2],usex[105],usey[105],ly[105],lx[105],result[105];
int sum,to[10005],pre[10005],w[105][105];

int max(int x, int y)
{
    if (x>y) return x; else return y;
}

int min(int x, int y)
{
    if (x<y) return x; else return y;
}

int abs(int x)
{
    if (x<0) return -x; else return x;
}

void init()
{
    sum = 0;
    memset(w,0,sizeof(w));
    memset(to,0,sizeof(to));
    memset(pre,0,sizeof(pre));
    memset(end,0,sizeof(end));
    memset(result,0,sizeof(result));
}

void setlj(int l, int r, int c)
{
    sum ++;
    to[sum] = r;
    pre[sum] = end[l];
    end[l] = sum;
    w[l][r] = - c;
}

int find(int x)
{
    int i,y;
    usex[x] = 1;
    for (i = end[x]; i; i = pre[i])
    {
        y = to[i];
        if ((!usey[y]) && (lx[x] + ly[y] == w[x][y]))
        {
            usey[y] = 1;
            if (!result[y] || find(result[y]))
            {
                result[y] = x;
                return 1;
            }
        }
    }
    return 0;
}

int main(void)
{
    int tot,totm,i,j,l,r,n,m,delta,ans,k;
    while(scanf("%d%d",&n,&m))
    {
        tot = 0; totm = 0;
        if (n == 0 && m == 0) return 0;
        for (i = 1; i <= n; i ++)
        {
            scanf("\n");
            for (j = 1; j <= m; j ++)
            {
                scanf("%c",&map[i][j]);
                if (map[i][j] == 'H')
                {
                    tot ++;
                    num[tot][1] = i;
                    num[tot][2] = j;
                }
            }
        }
        init();
        for (i = 1; i <= n; i ++)
            for (j = 1; j <= m; j ++)
                if (map[i][j] == 'm')
                {
                    totm ++;
                    for (k = 1; k <= tot; k ++)
                        setlj(totm,k,abs(num[k][1] - i)+abs(num[k][2] - j));
                }
        memset(ly,0,sizeof(ly));
        for (i = 1; i <= tot; i ++)
        {
            lx[i] = - INT_MAX;
            for (j = end[i]; j; j = pre[j])
                lx[i] = max(lx[i],w[i][to[j]]);
        }
        for (i = 1; i <= tot; i ++)
            while(1)
            {
                memset(usex,0,sizeof(usex));
                memset(usey,0,sizeof(usey));
                if (find(i)) break;
                delta = INT_MAX;
                for (l = 1; l <= tot; l ++)
                    if (usex[l])
                        for (r = end[l]; r; r = pre[r])
                            if (!usey[to[r]])
                                delta = min(delta,lx[l] + ly[to[r]] - w[l][to[r]]);
                for (j = 1; j <= tot; j ++)
                {
                    if (usex[j]) lx[j] -= delta;
                    if (usey[j]) ly[j] += delta;
                }
            }
        ans = 0;
        for (i = 1; i <= tot; i ++)
            ans += lx[i] + ly[i];
        printf("%d\n",-ans);
    }
}
