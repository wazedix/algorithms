#include<stdio.h>

int n,m,ans[30],map[30][30];

int check1(const int aa[30],const int bb[30])
{
    int i,j,t,ans[30],a[30],b[30];
    for (i = 0 ; i < 30 ; i ++)
    {
        a[i] = aa[i];
        b[i] = bb[i];
    }
    do
    {
        t = 0;
        for (i = 0 ; i < n ; i ++)
            if (a[i] || b[i])
                if (b[i] == 0)
                {
                    t ++;
                    ans[t] = i;
                }
        for (i = 1 ; i <= t ; i ++)
        {
            for (j = 0 ; j < n ; j ++)
                if (map[ans[i]][j])
                {
                    a[ans[i]] --;
                    b[j] --;
                }
        }      
    }
    while (t > 0);
    for (i = 0 ; i < n ; i ++)
        if (a[i] && b[i])
            return 1;
    return 0;
}

int check2(const int aa[30],const int bb[30])
{
    int i,j,t,p,a[30],b[30],use[30];
    for (i = 0 ; i < 30 ; i ++)
    {
        a[i] = aa[i];
        b[i] = bb[i];
        use[i] = 0;
    }
    ans[0] = 0;
    do
    {
        t = 0;
        for (i = 0 ; i < n ; i ++)
            if (a[i] || b[i])
                if (b[i] == 0)
                {
                    t ++;
                    p = i;
                }
        if (t > 1) return 0;
        if (t == 1)
        {
            for (j = 0 ; j < n ; j ++)
                if (map[p][j])
                {
                    a[p] --;
                    b[j] --;
                }
            ans[0] ++;
            ans[ans[0]] = p;
        }
    }
    while (t > 0);
    if (ans[0] == n - 1)
    {
        for (i = 1 ; i <= ans[0] ; i ++)
            use[ans[i]] = 1;
        for (i = 1 ; i < n ; i ++)
            if (use[i] == 0) ans[n] = i;
        return 1;
    }
    else 
        return 0;
}

int main(void)
{
    int aa[30],bb[30],i,j,k;
    char cl,cr,s[10];
    while(scanf("%d%d",&n,&m))
    {
        if (n == 0 && m == 0) return 0;
        for (i = 0 ; i < n ; i ++)
        {
            aa[i] = 0; bb[i] = 0;
            for (j = 0 ; j < n ; j ++)
                map[i][j] = 0;
        }
        for (k = 1 ; k <= m ; k ++)
        {
            scanf("%s",s);
            cl = s[0];
            cr = s[2];
            aa[cl - 'A'] ++;
            bb[cr - 'A'] ++;
            map[cl - 'A'][cr - 'A'] = 1;
            if (check1(aa,bb)) 
            {
                printf("Inconsistency found after %d relations.\n",k);
                break;
            }
            if (check2(aa,bb))
            {
                printf("Sorted sequence determined after %d relations: ",k);
                for (i = 1 ; i <= n ; i ++)
                    printf("%c",'A'+ans[i]);
                printf(".\n");
                break;
            }
            if (k == m)
                printf("Sorted sequence cannot be determined.\n");
        }
        for (i = k + 1 ; i <= m ; i ++) scanf("%s",s);
    }
}
