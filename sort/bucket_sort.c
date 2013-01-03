#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int value;
    struct node *next;
}node;

node **bucket;

void init_bucket(int size)
{
    int i;
    bucket = (node **)malloc((size+1)*sizeof(node *));
    for (i = 0; i <= size; i ++)
    {
        bucket[i] = (node *)malloc(sizeof(node));
        bucket[i]->value = 0;
        bucket[i]->next = 0;
    }
}

void del_bucket(int size)
{
    int i;
    for (i = 0; i <= size; i ++)
        free((void *)bucket[i]);
    free((void **)bucket);
}

void insert_bucket(int *list, int l, int r)
{
    int i, index;
    node *n;
    for (i = l; i <= r; i ++)
    {
        index = list[i] / 10;
        if (bucket[index]->value == 0 && bucket[index]->next == 0)
            bucket[index]->value = list[i];
        else
        {
            n = bucket[index];
            while (n->next) 
                n = n-> next;
            n->next = (node*)malloc(sizeof(node));
            n = n->next;
            n->next = 0;
            n->value = list[i];
        }
    }
}

void sort_bucket(int *list, int size)
{
    node *node1, *node2;
    int i, j=0, temp;
    for (i = 0; i <= size; i ++)
    {
        if (bucket[i]->next == 0 && bucket[i]->value == 0)
            continue;
        if (bucket[i]->next)
        {
            node1 = bucket[i];
            while (node1)
            {
                node2 = node1->next;
                while (node2)
                {
                    if (node1->value > node2->value)
                    {
                        temp = node1->value;
                        node1->value = node2->value;
                        node2->value = temp;
                    }
                    node2 = node2->next;
                }
                node1 = node1->next;
            }
        }
        node1 = bucket[i];
        while (node1)
        {
            list[j++] = node1->value;
            node2 = node1;
            node1 = node1->next;
            free(node2);
        }
    }
}

void bucket_sort(int *list, int l, int r)
{
    int i, size, max=0;
    for (i = l; i <= r; i ++)
        if (list[i]>max)
            max = list[i];
    size = max/10;
    init_bucket(size);
    insert_bucket(list, l, r);
    sort_bucket(list, size);
    del_bucket(size);
}
