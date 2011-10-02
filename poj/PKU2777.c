#include<stdio.h>
#include<string.h>

struct node
{
    int l,r,c;
}tree[1000005];
int use[50];

void swap(int l, int r)
{
    int temp = l;
    l = r;
    r = temp;
}

init(int x, int l, int r)
{
    tree[x].l = l;
    tree[x].r = r;
    if (r - l)
    {
        init(2 * x,l,(l + r) / 2);
        init(2 * x + 1,(l + r) / 2 + 1,r);
    }
}

void insert(int x,int l, int r, int c)
{
    if (tree[x].l == l && tree[x].r == r)
    {
        tree[x].c = c;
        return;
    }
    if (tree[x].c > 0)
    {
        tree[2 * x].c = tree[x].c;
        tree[2 * x + 1].c = tree[x].c;
        tree[x].c = -1;
    }
    int d = (tree[x].l + tree[x].r) / 2;
    if (r <= d) 
        insert(2 * x,l,r,c);
    else if (l > d) 
        insert(2 * x + 1,l,r,c);
    else 
    {
        insert(2 * x,l,d,c);
        insert(2 * x + 1,d + 1,r,c);
    }
}

void search(int x,int l,int r)
{
    if (tree[x].c > 0)
    {
        use[tree[x].c] = 1;
        return;
    }
    int d = (tree[x].l + tree[x].r) / 2;
    if (r <= d) search(2 * x,l,r);
    else if (l > d) search(2 * x + 1,l,r);
    else
    {
        search(2 * x,l,d);
        search(2 * x + 1,d+1,r);
    }
}

int main(void)
{
    int i,j,len,t,o,l,r,c;
    char ch;
    scanf("%d%d%d",&len,&t,&o);
    init(1,1,len);
    tree[1].c = 1;
    for (i = 1; i <= o; i ++)
    {
        scanf(" %c",&ch);
        if (ch == 'C')
        {
            scanf("%d%d%d",&l,&r,&c);
            if (l > r) swap(l,r);
            insert(1,l,r,c);
        }
        else
        {
            scanf("%d%d",&l,&r);
            if (l > r) swap(l,r);
            memset(use,0,sizeof(use));
            search(1,l,r);
            int ans = 0;
            for (j = 1; j <= t; j ++)
                if (use[j]) ans ++;
            printf("%d\n",ans);
        }
    }
    return 0;
}
