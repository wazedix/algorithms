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
int input_E;


void add_edge(int start_point, int end_point, int edge_value)        /*邻接表增加边*/
{
    num_E ++;
    end[num_E] = end_point;
    value[num_E] = edge_value;
    next[num_E] = first[start_point];
    first[start_point] = num_E;
}


int spfa(int start_point, int end_point)
{
    int i, head = 0, tail = 0, point;
    int list[MAX_V], distance[MAX_V], mark[MAX_V];
    for (i = 1; i <= num_V; i ++)                   /* 初始化所有点的距离和集合 */
    {
        distance[i] = INT_MAX;
        mark[i] = FALSE;
    }
    list[++tail] = start_point;
    mark[start_point] = TRUE;
    distance[start_point] = 0;
    while (head != tail)
    {
        head = head % num_V + 1;
        point = list[head];
        for (i = first[point]; i > 0; i = next[i])
            if (distance[point] + value[i] < distance[end[i]])
            {
                distance[end[i]] = distance[point] + value[i];
                if (mark[end[i]] == FALSE)
                {
                    tail = tail % num_V + 1;
                    list[tail] = end[i];
                    mark[end[i]] = TRUE;
                }
            }
        mark[point] = FALSE;
    }
    return distance[end_point];
}


int main(void)
{
    int i, start, end, value, ans;
    memset(first, 0, MAX_V * sizeof(int));
    scanf("%d %d\n", &num_V, &input_E);
    for (i = 0; i < input_E; i ++)
    {
        scanf("%d %d %d\n", &start, &end, &value);
        add_edge(start, end, value);
        add_edge(end, start, value);
    }
    scanf("%d %d\n", &start, &end);
    ans = spfa(start, end);
    printf("%d\n", ans);
    return 0;
}
