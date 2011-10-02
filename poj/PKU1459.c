#include<stdio.h>
#include<string.h>
#include<limits.h>

int f[105],w[105][105],n,nc,np,z,m;

int min(int x, int y)
{
    if (x < y) return x; else return y;
}

int bfs()
{
    int queue[105];
    int i,j,head = 0,fail = 0,x;
    memset(f,0,sizeof(f));
    queue[++ fail] = 0;
    f[0] = 1;
    while (head < fail)
    {
        x = queue[++ head];
        for (i = 1; i <= n + 1; i ++)
            if (w[x][i] > 0 && !f[i])
            {
                queue[++ fail] = i;
                f[i] = f[x] + 1;
                if (i == n + 1) 
                    return 1;
            }
    }
    return 0;
}

int max_flow(int x,int flow)
{
    int i,delta;
    if (x == n + 1) return flow;
    for (i = 1; i <= n + 1; i ++)
        if (w[x][i] > 0 && f[x] + 1 == f[i])
            if (delta = max_flow(i,min(w[x][i],flow)))
            {
                w[x][i] -= delta;
                w[i][x] += delta;
                return delta;
            }
    return 0;
}

int main(void)
{
    int i,j,l,r,ans; char ch;
    while (scanf("%d%d%d%d",&n,&np,&nc,&m) != EOF)
    {
        memset(w,0,sizeof(w));
        for (i = 1; i <= m; i ++)
        {
            ch = '.';
            while (ch != '(')
                ch = getchar();
            scanf("%d,%d)%d",&l,&r,&z);
            w[l + 1][r + 1] = z;
        }
        for (i = 1; i <= np; i ++)
        {
            ch = '.';
            while (ch != '(')
                ch = getchar();
            scanf("%d)%d",&l,&z);
            w[0][l + 1] = z;
        }
        for (i = 1; i <= nc; i ++)
        {
            ch = '.';
            while (ch != '(')
                ch = getchar();
            scanf("%d)%d",&l,&z);
            w[l + 1][n + 1] = z;
        }
        ans = 0;
        while (bfs())
            ans += max_flow(0,INT_MAX);
        printf("%d\n",ans);
    }
    return 0;
}
