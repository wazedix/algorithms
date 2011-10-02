#include<stdio.h>
#include<string.h>

struct node
{
    int child[26];
    int fail;
    int id;
    int len;
}trie[500000];
int root,tot;
int queue[500000],head,tail;
int ans[1005][4];
char sss[1005];

char *un(const char *str)
{
    int len = strlen(str);
    int i,j = 0;
    for (i = len-1 ; i >= 0 ; i --)
    {
        sss[j] = str[i];
        j ++;
    }
    sss[j] = '\0';
    return sss;
}

void init()
{
    int i,j;
    root = 0; tot = 0;
    for (i = 0 ; i < 500000 ; i++)
    {
        trie[i].fail = 0;
        trie[i].id = 0;
        trie[i].len = 0;
        for (j = 0 ; j < 26 ; j++)
            trie[i].child[j] = 0;
    }
}

void insert(const char *s,int id)
{
    int temp,index;
    temp = root;
    while (*s)
    {
        index = *s - 'A';
        if (!trie[temp].child[index])
            trie[temp].child[index] = ++ tot;
        temp = trie[temp].child[index];
        s ++;
    }
    trie[temp].id = id;
}

void ac_auto()
{
    int temp,index,i,p,son;
    head = 0; tail = 0;
    queue[++ tail] = root;
    while (head < tail)
    {
        temp = queue[++ head];
        p = trie[temp].fail;
        for (i = 0 ; i < 26 ; i ++)
        {
            son = trie[temp].child[i];
            if (son)
            {
                queue[++ tail] = son;
                trie[son].len = trie[temp].len + 1;
                trie[son].fail = (temp == root)?root:trie[p].child[i];
            }
            else
                trie[temp].child[i] = (temp == root)?root:trie[p].child[i];
        }
    }
}

void match(const char *s,int x,int y,int z)
{
    int temp,index,p = root,len = 0,id;
    int xx,yy;
    while (*s)
    {
        index = *s - 'A';
        while (p > 0 && !trie[p].child[index]) p = trie[p].fail;
        p = trie[p].child[index];
        temp = p;
        while (trie[temp].id > 0)
        {
            xx = x; yy = y;
            if (z == 'A' ||
                z == 'B' ||
                z == 'H')  xx -= len - trie[temp].len + 1;
            if (z == 'D' ||
                z == 'E' ||
                z == 'F')  xx += len - trie[temp].len + 1;
            if (z == 'F' ||
                z == 'G' ||
                z == 'H')  yy -= len - trie[temp].len + 1;
            if (z == 'B' ||
                z == 'C' ||
                z == 'D')  yy += len - trie[temp].len + 1;
            id = trie[temp].id;
            ans[id][1] = xx; 
            ans[id][2] = yy;
            ans[id][3] = z;
            temp = trie[temp].fail;
        }
        s ++;
        len ++;
    }
}


int main(void)
{
    int n,m,i,l,r,w;
    char s[1005],ss[1005];
    char a[1005][1005];
    init();
    scanf("%d%d%d",&n,&m,&w);
    for (i = 0 ; i < n ; i ++)
        scanf("%s",a[i]);
    for (i = 1 ; i <= w ; i ++)
    {
        scanf("%s",s);
        insert(s,i);
    }
    ac_auto();
    for (i = 0 ; i < m ; i ++)
    {
        l = 1;
        ss[0] = a[0][i];
        while (l < n)
        {
            ss[l] = a[l][i];
            l ++;
        }
        ss[l] = '\0';
        match(ss,0,i,'E');
        match(un(ss),l - 1,i,'A');

        l = 1; r = 1; 
        ss[0] = a[0][i];
        while (l < n && i + r < m)
        {
            ss[l] = a[l][i + r];
            l ++; r ++;
        }
        ss[l] = '\0';
        match(ss,0,i,'D');
        match(un(ss),l - 1,i + r - 1,'H');

        l = 1; r = 1;
        ss[0] = a[0][i];
        while (l < n && i - r >=0)
        {
            ss[l] = a[l][i - r];
            l ++; r ++;
        }
        ss[l] = '\0';
        match(ss,0,i,'F');
        match(un(ss),l - 1,i - r + 1,'B');
    }
    for (i = 0 ; i < n ; i ++)
    {
        match(a[i],i,0,'C');
        match(un(a[i]),i,m-1,'G');

        l = 1; r = 1;
        ss[0] = a[i][0];
        while (i + l < n && r < m)
        {
            ss[l] = a[i + l][r];
            l ++; r ++;
        }
        ss[l] = '\0';
        match(ss,i,0,'D');
        match(un(ss),i + l - 1,r - 1,'H');

        l = 1; r = 1;
        ss[0] = a[i][m - 1];
        while (i + l < n && m - 1 - r >= 0)
        {
            ss[l] = a[i + l][m - 1 - r];
            l ++; r ++;
        }
        ss[l] = '\0';
        match(ss,i,m - 1,'F');
        match(un(ss),i + l - 1,m - 1 - r + 1,'B');
    }
    for (i = 1 ; i <= w ; i ++)
        printf("%d %d %c\n",ans[i][1],ans[i][2],ans[i][3]);
    return 0;
}
