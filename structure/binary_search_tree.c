#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "output.h"

enum {
    DEBUG = 1,              /* debug开关，0则为关闭 */
    TESTN = 5,              /* 测试数据的大小，0则为从外部读入 */
    MAX_N = 100,            /* 生成随机数据的最大值 */
    MAX_LENGTH = 102        /* 初始化测试数组的长度 */
};

typedef struct Node{
    int value;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
}Node;

Node *ROOT;

int LIST[MAX_LENGTH];    /* 输入的数据 */


Node* init_node(int value)
{
    Node *node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->left = 0;
    node->right = 0;
    node->parent = 0;
    return node;
}


Node* tree_search(int value)
{
    Node *node = ROOT;
    while (node && node->value != value)        //定位到查找的节点
        if (value < node->value) 
            node = node->left;
        else
            node = node->right;
    return node;
}


void tree_insert(int value)
{
    if (!ROOT)
    {
        ROOT = init_node(value);
        return;
    }
    Node *node = ROOT, *parent;
    while (node)
    {
        parent = node;
        if (value <= node->value)
            node = node->left;
        else
            node = node->right;
    }
    node = init_node(value);
    node->parent = parent;
    if (value <= parent->value)
        parent->left = node;
    else 
        parent->right = node;
}


void tree_delete(Node *node)
{
    Node *temp;
    if ((!node->left) && (!node->right) && (node != ROOT))      //为叶子节点且不为根时
    {
        if (node->parent->left == node)
            node->parent->left = 0;
        else
            node->parent->right = 0;
    }
    else if (node->left && node->right)                         //有左儿子和右儿子时
    {
        Node *temp = node->right;                               //找出右子树中最小的节点
        while (temp->left)                                      
            temp = temp->left;
        node->value = temp->value;
        if (temp == temp->parent->right)                        //交换两点的值并嫁接
            temp->parent->right = temp->right;
        else if (temp == temp->parent->left)
            temp->parent->left = temp->right;
        if (temp->right)
            temp->right->parent = temp->parent;
        node = temp;
    }
    else                                                        //只有一个儿子时
    {
        if (node->left)                                         //判断是左儿子还是右儿子
            temp = node->left;
        else 
            temp = node->right;
        if (node == ROOT)                                       //判断是否为ROOT进行不同的嫁接
            ROOT = temp;
        else
        {
            temp->parent = node->parent;            
            if (node->parent->left == node)
                node->parent->left = temp;
            else
                node->parent->right = temp;
        }
    }
    free(node);
}


void tree_walk(Node *node)
{
    if (node)
    {
        tree_walk(node->left);
        printf("%d ", node->value);
        tree_walk(node->right);
    }
}


int main(void)
{
    /* 初始化测试数据 */
    int i, n;
    srand((unsigned)time(NULL));
    if (TESTN)              
        n = TESTN;
    else
        scanf("%d\n", &n);
    for (i = 0; i < n; i++)
    {
        if (TESTN)
            LIST[i] = rand() % MAX_N;
        else
            scanf("%d", &LIST[i]);
    }

    if (DEBUG) output(LIST, n); //debug output

    for (i = 0; i < n; i ++)
        tree_insert(LIST[i]);

    tree_walk(ROOT);
    printf("\n");

    if (DEBUG)  //debug test
    { 
        for (i = 0; i <= 2; i ++)
        {
            Node *node = tree_search(LIST[i]);
            if (node)
                tree_delete(node);
            tree_walk(ROOT);
            printf("\n");
        }
    }

    return 0;
}
