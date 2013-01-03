#include <stdlib.h>

struct Heap {
    int length;
    int *list;
} heap;

void max_heapify(int index)
{
    int lchild = index * 2;
    int rchild = index * 2 + 1;
    int max_key = index;
    int max = heap.list[index];
    if ((lchild <= heap.length) && (heap.list[lchild] > max))
    {
        max = heap.list[lchild];
        max_key = lchild;
    }
    if ((rchild <= heap.length) && (heap.list[rchild] > max))
    {
        max = heap.list[rchild];
        max_key = rchild;
    }
    if (max_key != index)
    {
        heap.list[max_key] = heap.list[index];
        heap.list[index] = max;
        max_heapify(max_key);
    }
}

void build_max_heapify()
{
    int i;
    for (i = heap.length/2; i >= 1; i --)
        max_heapify(i);
}

void insert(int value)
{
    heap.length ++;
    heap.list[heap.length] = value;
    max_heapify(heap.length / 2);

}

int pop()
{
    int max = heap.list[1];
    heap.list[1] = heap.list[heap.length];
    heap.length --;
    max_heapify(1);
    return max;
}

void sort()
{
    int i, length = heap.length;
    for (i = 1; i <= length; i ++)
        heap.list[length-i+1] = pop();
}

void init(int *list, int l, int r)
{
    heap.length = r-l+1;
    heap.list = (int*)malloc((r-l+2)*sizeof(int));
    int i;
    for (i = 1; i <= r-l+1; i ++)
        heap.list[i] = list[l+i-1];
}

void del()
{
    free(heap.list);
}

void heap_sort(int *list, int l, int r)
{
    init(list, l, r);
    build_max_heapify();
    sort();
    int i;
    for (i = l; i <= r; i ++)
        list[i] = heap.list[i-l+1];
    del();
}
