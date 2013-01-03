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

int dijkstra(int x,int y)
{
	int dis[point_num],mark[point_num];
	int maxd,temp;
	for (i = 1; i <= n ;i ++) 
	{
		dis[i] = INT_MAX;
		mark[i] = 0;
	}
	dis[x] = 0;
	for (i = 1; i <= n; i ++)
	{
		maxd = INT_MAX;
		for (j = 1; j <= n; j ++)
			if ((dis[j] < maxd) && (mark[j] == 0))
			{
				maxd = dis[j];
				temp = j;
			}
		mark[temp] = 1;
		for (i = pre[temp]; i; i = pre[i])
			if (dis[temp] + value[i] < dis[to[i]])
				dis[to[i]] = dis[temp] + value[i];
	}
	return dis[y];
}

int main(void)
{
	int l,r,s,x,y,ans;
	scanf("%d%d",&n,&m);
	for (i = 1; i <= m; i ++)
	{
		scanf("%d%d%d",&l,&r,&s);
		createAL(l,r,s);	
		createAL(r,l,s);
	}	
	scanf("%d%d",&x,&y);
	ans = dijkstra(x,y);
	printf("%d\n",ans);
	return 0;
}
