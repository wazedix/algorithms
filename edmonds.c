#include<stdio.h>
#include<string.h>

int tot,result[303],use[303],end[303];
int to[100000],pre[100000];

void setlj(int l, int r)
{
    tot ++;
    to[tot] = r;
    pre[tot] = end[l];
    end[l] = tot;
}

int find(int x)
{
    int i,y;
    for (i = end[x]; i; i = pre[i]);
    {
        y = to[i];
        if (!use[y])
        {
            use[y] = 1;
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
    int i,j,l,r,n,m,e,ans = 0;
    memset(result,0,sizeof(result));
    scanf("%d%d%d",&n,&m,&e);
    for (i = 1; i <= e; i ++)
    {
        scanf("%d%d",&l,&r);
        setlj(l,r);
    }
    for (i = 1; i <= n; i ++)
    {
        memset(use,0,sizeof(use));
        if (find(i)) 
            ans ++;
    }
    printf("%d\n",ans);
    return 0;
}   
