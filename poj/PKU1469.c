#include<stdio.h>
#include<string.h>

int ans,tot,result[303],use[303],end[303];
int to[100000],pre[100000];

void init()
{
    ans = 0;
    memset(result,0,sizeof(result));
    tot = 0;
    memset(to,0,sizeof(to));
    memset(pre,0,sizeof(pre));
    memset(end,0,sizeof(end));
}

void setlj(int l, int r)
{
    tot ++;
    to[tot] = r;
    pre[tot] = end[l];
    end[l] = tot;
}

int find(int x)
{
    int t,y;
    t = end[x];
    while (t)
    {
        y = to[t];
        if (!use[y])
        {
            use[y] = 1;
            if (!result[y] || find(result[y]))
            {
                result[y] = x;
                return 1;
            }
        }
        t = pre[t];
    }
    return 0;
}

int main(void)
{
    int v,k,i,j,r,p,n,m;
    scanf("%d",&v);
    for (k = 1; k <= v; k ++)
    {
        init();
        scanf("%d%d",&p,&n);
        for (i = 1; i <= p; i ++)
        {
            scanf("%d",&m);
            for (j = 1; j <= m; j ++)
            {
                scanf("%d",&r);
                setlj(i,r);
            }
        }
        for (i = 1; i <= p; i ++)
        {
            memset(use,0,sizeof(use));
            if (find(i)) ans ++;
        }
        if (ans == p)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
