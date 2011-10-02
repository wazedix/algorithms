#include<stdio.h>
#include<limits.h>
#include<math.h>

int main(void)
{
    int v = 0,ans,i,j,n,d,x,y;
    double a[1005][3],delta,t;
    while (scanf("%d%d",&n,&d))
    {
        if (n == 0 && d == 0) return 0;
        ans = 0;
        for (i = 1; i <= n; i ++)
        {
            scanf("%d%d",&x,&y);
            if (y > d) ans = -1;
            if (d != y) 
                delta = sqrt(d * d - y * y);
            else
                delta = 0;
            a[i][1] = x - delta;
            a[i][2] = x + delta;
        }
        scanf("\n");
        printf("Case %d: ",++ v);
        if (ans == -1 || d < 0)
        {
            printf("-1\n");
            continue;
        }
        for (i = 1; i <= n; i ++)
            for (j = i + 1; j <= n; j ++)
                if (a[i][2] > a[j][2])
                {
                    t = a[i][2];
                    a[i][2] = a[j][2];
                    a[j][2] = t;
                    t = a[i][1];
                    a[i][1] = a[j][1];
                    a[j][1] = t;
                }
        t = - INT_MAX;
        for (i = 1; i <= n; i ++)
        {
            if (a[i][1] > t)
            {
                t = a[i][2];
                ans ++;
            }
        }
        printf("%d\n",ans);
    }
}
