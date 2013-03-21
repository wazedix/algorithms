#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "output.h"

enum {
    RED = 1,
    BLACK = 2,
    DEBUG = 3,              /* debug开关，0则为关闭 */
    TESTN = 5,              /* 测试数据的大小，0则为从外部读入 */
    MAX_N = 100,            /* 生成随机数据的最大值 */
    MAX_LENGTH = 102        /* 初始化测试数组的长度 */
};

typedef struct Node{        /* 定义节点类型Node */
    int value;
    int color;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
}Node;

Node *ROOT;                         /* 根节点 */
Node NIL = { 0, BLACK, 0, 0, 0};    /* 定义的空节点 */

int LIST[MAX_LENGTH];               /* 输入的数据 */


Node* init_node(int value)          /* 生成新节点的函数 */
{
    Node *node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->left = &NIL;
    node->right = &NIL;
    node->parent = &NIL;
    node->color = RED;
    return node;
}


void tree_walk(Node *node)          /* 遍历按顺输出 */
{
    if (node != &NIL)
    {
        tree_walk(node->left);
        printf("value:%d color:%d left:%d right:%d add:%d parent:%d\n", node->value, node->color, node->left->value, node->right->value, node, node->parent->value);
        tree_walk(node->right);
    }
} 


void left_rotate(Node *node)        /* 左旋,有改动别忘了改右旋 */
{
    Node *temp = node->right;
    node->right = temp->left;
    if (temp->left != &NIL)
        temp->left->parent = node;
    temp->parent = node->parent;
    if (node == ROOT)
        ROOT = temp;
    else 
    {
        if (node->parent->left == node)
            node->parent->left = temp;
        else
            node->parent->right = temp;
    }
    temp->left = node;
    node->parent = temp;
}


void right_rotate(Node *node)       /* 右旋,有改动别忘了改左旋 */
{
    Node *temp = node->left;
    node->left = temp->right;
    if (temp->right != &NIL)
        temp->right->parent = node;
    temp->parent = node->parent;
    if (node == ROOT)
        ROOT = temp;
    else 
    {
        if (node->parent->left == node)
            node->parent->left = temp;
        else
            node->parent->right = temp;
    }
    temp->right = node;
    node->parent = temp;
}


Node* tree_search(int value)        /* 根据节点的值返回节点地址 */
{
    Node *node = ROOT;
    while (node != &NIL && node->value != value)        //定位到查找的节点
        if (value < node->value) 
            node = node->left;
        else
            node = node->right;
    return node;
}


void tree_insert_fixup(Node *node)      /* 插入后的修复函数 */
{
    Node *temp;
    while (node->parent->color == RED)
    {
        if (node->parent == node->parent->parent->left)
        {
            temp = node->parent->parent->right;
            if (temp->color == RED)         /* CASE1,具体见《算法导论》 */
            {
                temp->color = BLACK;
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            }
            else
            {
                if (node == node->parent->right)        /* CASE2 */
                {
                    node = node->parent;
                    left_rotate(node);
                }
                node->parent->color = BLACK;            /* CASE3 */
                node->parent->parent->color = RED;
                right_rotate(node->parent->parent);
            }
        }
        else                                            /* 此处else与前面左右对称 */
        {
            temp = node->parent->parent->left;
            if (temp->color == RED)
            {
                temp->color = BLACK;
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            }
            else
            {
                if (node == node->parent->left)
                {
                    node = node->parent;
                    right_rotate(node);
                }
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                left_rotate(node->parent->parent);
            }
        }
    }
    ROOT->color = BLACK;
}


void tree_insert(int value)             /* 插入函数 */
{
    if (!ROOT)                          /* 如果ROOT为空就建立ROOT,直接返回 */
    {
        ROOT = init_node(value);
        ROOT->color = BLACK;
        ROOT->parent = &NIL;
        return;
    }
    Node *node = ROOT, *parent;
    while (node != &NIL)                /* 循环寻找插入点 */
    {
        parent = node;
        if (value <= node->value)
            node = node->left;
        else
            node = node->right;
    }
    node = init_node(value);            /* 创建节点并建立双向连接 */
    node->parent = parent;
    if (value <= parent->value)
        parent->left = node;
    else 
        parent->right = node;
    tree_insert_fixup(node);
}


void tree_delete_fixup(Node *node)              /* 删除后的修复函数 */
{
    Node *temp;
    while (node != ROOT && node->color == BLACK)
    {
        if (node == node->parent->left)
        {
            temp = node->parent->right;
            if (temp->color == RED)             /* CASE1 */
            {
                temp->color = BLACK;
                node->parent->color = RED;
                left_rotate(node->parent);
                temp = node->parent->right;
            }
            if (temp->left->color == BLACK && temp->right->color == BLACK)      /* CASE2 */
            {
                temp->color = RED;
                node = node->parent;
            }
            else
            {
                if (temp->right->color == BLACK)        /* CASE3 */
                {
                    temp->left->color = BLACK;
                    temp->color = RED;
                    right_rotate(temp);
                    temp = node->parent->right;
                }
                temp->color = node->parent->color;      /* CASE4 */
                node->parent->color = BLACK;
                temp->right->color = BLACK;
                left_rotate(node->parent);
                node = ROOT;
            }
        }
        else                                            /* 此处else与上方左右对称 */
        {
            temp = node->parent->left;
            if (temp->color == RED)
            {
                temp->color = BLACK;
                node->parent->color = RED;
                left_rotate(node->parent);
                temp = node->parent->left;
            }
            if (temp->left->color == BLACK && temp->right->color == BLACK)
            {
                temp->color = RED;
                node = node->parent;
            }
            else
            {
                if (temp->left->color == BLACK)
                {
                    temp->right->color = BLACK;
                    temp->color = RED;
                    left_rotate(temp);
                    temp = node->parent->left;
                }
                temp->color = node->parent->color;
                node->parent->color = BLACK;
                temp->left->color = BLACK;
                right_rotate(node->parent);
                node = ROOT;
            }
        }
    }
    node->color = BLACK;
}


void tree_delete(Node *node)                                        /* 删除节点函数 */
{
    Node *temp;
    if ((node->left == &NIL) && (node->right == &NIL) && (node != ROOT))        /* 为叶子节点且不为根时 */
    {
        temp = &NIL;
        temp->parent = node->parent;
        if (node->parent->left == node)
            node->parent->left = &NIL;
        else
            node->parent->right = &NIL;
    }
    else if (node->left != &NIL && node->right != &NIL)                         /* 有左儿子和右儿子时 */
    {
        temp = node->right;                                                 /* 找出右子树中最小的节点 */
        while (temp->left != &NIL)                                      
            temp = temp->left;
        node->value = temp->value;                                          /* 交换两点的值并嫁接 */
        if (temp == temp->parent->right)                        
            temp->parent->right = temp->right;
        else if (temp == temp->parent->left)
            temp->parent->left = temp->right;
        if (temp->right != &NIL)
        temp->right->parent = temp->parent;
        node = temp;
        temp = temp->right;
        temp->parent = node->parent;
    }
    else                                                                        /* 只有一个儿子时 */
    {
        if (node->left != &NIL)                                             /* 判断是左儿子还是右儿子 */
            temp = node->left;
        else 
            temp = node->right;
        if (node == ROOT)                                                   /* 判断是否为ROOT进行不同的嫁接 */
        {
            ROOT = temp;
            ROOT->parent = &NIL;
        }
        else
        {
            temp->parent = node->parent;            
            if (node->parent->left == node)
                node->parent->left = temp;
            else
                node->parent->right = temp;
        }
    }
    if (node->color == BLACK)
        tree_delete_fixup(temp);
    free(node);
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
