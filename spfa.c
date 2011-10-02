# include<stdio.h>
# include<limits.h>
# define point_num 1000
# define line_num 10000

int sum = 0,i,j,n,m;
int	pre[line_num],to[line_num],value[line_num];
int	end[point_num];

void createAL(int l,int r,int s)
{
	sum ++;
	pre[sum] = end[l];
	to[sum] = r;
	end[l] = sum;
	value[sum] = s;
}

int spfa(int x,int y)
{
	int dis[point_num],mark[point_num],queue[point_num];
	int head = 0,tail = 0,temp;
	for (i = 1; i <= n; i ++)
	{
		dis[i] = INT_MAX;
		mark[i] = 0;
	}
	dis[x] = 0;
	mark[x] = 1;
	queue[++ tail] = x;
	while (head != tail)
	{
		head = head % n + 1;
		temp = queue[head];
        for (i = end[temp]; i; i = pre[i])
			if (dis[temp] + value[i] < dis[to[i]])
			{
				dis[to[i]] = dis[temp] + value[i];
				if (mark[to[i]] == 0)
				{
					tail = tail % n + 1;
					queue[tail] = to[i];
					mark[to[i]] = 1;
				}
			}
		mark[temp] = 0;
	}
	return dis[y];
}

int main(void)
{
	int l,r,s,x,y,ans;
	scanf("%d%d",&n,&m);
	for (i = 1 ;i <= m; i ++)
	{
		scanf("%d%d%d",&l,&r,&s);
		createAL(l,r,s);	
		createAL(r,l,s);
	}	
	scanf("%d%d",&x,&y);
	ans = spfa(x,y);
	printf("%d\n",ans);
	return 0;
}
