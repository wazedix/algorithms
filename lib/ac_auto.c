#include<stdio.h>
#define MAXN 500005
#define kind 26

struct node 
{
    int child[kind];
    int fail;
    int id;
    int tot;
}trie[MAXN];
int root,tot;
char s[55],ss[1000005];

void init()
{
    int i,j;
    root = 0; tot = 0;
    for (i = 0 ; i <= MAXN ; i ++)
    {
        trie[i].fail = -1;
        trie[i].id = 0;
        trie[i].tot = 0;
        for (j = 0 ; j <= kind ; j ++)
            trie[i].child[j] = 0;
    }
}

void insert(const char *s,int id)
{
    int index;
    int temp = root;
    while (*s)
    {
        index = *s - 'a';
        if (!trie[temp].child[index])
            trie[temp].child[index] = ++ tot;
        temp = trie[temp].child[index];
        s ++;
    }
    trie[temp].id = id;
    trie[temp].tot ++;
}

void ac_auto()
{
    int temp,i,son,p;
    int queue[MAXN],head = 0,tail = 0;
    queue[++ tail] = root;
    while (head < tail)
    {
        temp = queue[++ head];
        for (i = 0 ; i < kind ; i ++)
        {
            p = trie[temp].fail;
            son = trie[temp].child[i];
            if (son)
            {
                queue[++ tail] = son;   
                trie[son].fail = (temp == root)?root:trie[p].child[i]; 
            }
            else
                trie[temp].child[i] = (temp == root)?root:trie[p].child[i];
        }
    }
}

void check(const char *s)
{
    int ans = 0;
    int index,p = root,temp;
    while (*s)
    {
        index = *s - 'a';
        while (p > 0 && !trie[p].child[index]) p = trie[p].fail;
        p = trie[p].child[index];
        temp = p;
        while (temp > 0 && trie[temp].tot > 0)
        {
            ans += trie[temp].tot;
            trie[temp].tot = 0;
            temp = trie[temp].fail;
        }
        s ++;
    }
    printf("%d\n",ans);
}

int main(void)
{
    int n,i;
    init();
    scanf("%d",&n);
    for (i = 1 ;i <= n ;i ++)
    {
        scanf("%s",s);
        insert(s,i);
    }
    ac_auto();
    scanf("%s",ss);
    check(ss);
    return 0;
}
