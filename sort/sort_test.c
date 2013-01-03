#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "insertion_sort.h"
#include "merge_sort.h"
#include "heap_sort.h"
#include "quick_sort.h"
#include "counting_sort.h"
#include "radix_sort.h"
#include "bucket_sort.h"
#include "output.h"

enum {
    DEBUG = 0,              /* debug开关，0则为关闭 */
    TESTN = 1000,             /* 测试数据的大小，0则为从外部读入 */
    MAX_N = 10000,            /* 生成随机数据的最大值 */
    MAX_LENGTH = 1000002        /* 初始化测试数组的长度 */
};

int LIST[7][MAX_LENGTH];    /* 待排序的数据，有7组数据 */


/* 参数分别为待排序数组，起始点，结束点，调用的排序函数 
将输出函数执行时间*/ 
void sort_test(int *list, int l, int r, 
        void (*fsort)(int *list, int l, int r))
{
    clock_t before;
    before = clock();
    fsort(list, l, r);
    output(list, r-l+1);
    double elapsed = clock() - before;
    printf("time: %.3fs \n\n", elapsed/CLOCKS_PER_SEC);
}


int main(void)
{
    /* 初始化测试数据 */
    int i, j, n;
    srand((unsigned)time(NULL));
    if (TESTN)              
        n = TESTN;
    else
        scanf("%d\n", &n);
    for (i = 0; i < n; i++)
    {
        if (TESTN)
            LIST[0][i] = rand() % MAX_N;
        else
            scanf("%d", &LIST[0][i]);
        for (j = 1; j < 7; j ++)
            LIST[j][i] = LIST[0][i];
    }

    if (DEBUG) output(LIST[0], n); //debug output

    /* 开始测试排序算法 */
    sort_test(LIST[0], 0, n-1, insertion_sort);   /* O(n^2),比较大赛据时建议注释 */
    sort_test(LIST[1], 0, n-1, merge_sort);
    sort_test(LIST[2], 0, n-1, heap_sort);
    sort_test(LIST[3], 0, n-1, quick_sort);
    sort_test(LIST[4], 0, n-1, counting_sort);
    sort_test(LIST[5], 0, n-1, radix_sort);
    sort_test(LIST[6], 0, n-1, bucket_sort);      /* 数据量大的时候有问题 */
    return 0;
}

