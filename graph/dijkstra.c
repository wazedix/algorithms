#include <stdio.h>
#include <string.h>
#include <limits.h>

enum {
    TRUE = 1,
    FALSE = 0,
    MAX_E = 10000,      /* 最大的边数 */
    MAX_V = 1000,       /* 最大的点数 */
};

int value[MAX_E];
int end[MAX_E];
int next[MAX_E];
int first[MAX_V];
int num_E = 0;
int num_V;


void add_edge(int start_point, int end_point, int edge_value)        /*邻接表增加边*/
{
    num_E ++;
    end[num_E] = end_point;
    value[num_E] = edge_value;
    next[num_E] = first[start_point];
    first[start_point] = num_E;
}


int dijkstra(int start_point, int end_point)
{
    int i, j, min, point;
    int distance[MAX_V], mark[MAX_V];
    for (i = 1; i <= num_V; i ++)                   /* 初始化所有点的距离和集合 */
    {
        distance[i] = INT_MAX;
        mark[i] = FALSE;
    }
    distance[start_point] = 0;
    for (i = 1; i <= num_V; i ++)
    {
        min = INT_MAX;
        for (j = 1; j <= num_V; j ++)               /* 找出不在集合中的距离最近的点 */
            if (mark[j] == FALSE && distance[j] < min)
            {
                min = distance[j];
                point = j;
            }
        mark[point] = TRUE;                         /* 添加进集合 */
        for (j = first[point]; j > 0; j = next[j])          /* 更新此点与其它点的距离 */
            if (distance[point] + value[j] < distance[end[j]])
                distance[end[j]] = distance[point] + value[j];
    }
    return distance[end_point];
}


int main(void)
{
    int input_E, i, start, end, value, ans;
    memset(first, 0, MAX_V * sizeof(int));
    scanf("%d %d\n", &num_V, &input_E);
    for (i = 0; i < input_E; i ++)
    {
        scanf("%d %d %d\n", &start, &end, &value);
        add_edge(start, end, value);
        add_edge(end, start, value);
    }
    scanf("%d %d\n", &start, &end);
    ans = dijkstra(start, end);
    printf("%d\n", ans);
    return 0;
}
