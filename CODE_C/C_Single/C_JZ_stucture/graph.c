/**
 * @file graph.c
 * @author your name (you@domain.com)
 * @brief   对图的简单的思路,大致实现了指针数组挂载链表【有些像哈希表】，来进行存储稀疏图
 * @version 0.1
 * @date 2024-06-12
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct graph
{
    int data;
    struct graph *pnext;
} graph;
// 例如：图中的 元素为 1 2 3 4 5 6 7
void initgraph(graph *a[], int val);
void bianligraph(graph *a[], int val);
int main()
{
    graph *a[7];
    initgraph(a, 7);
    bianligraph(a, 7);
    system("pause");
    return 0;
}
void initgraph(graph *a[], int val)
{
    
    for (int i = 0; i < val; i++)
    {
        int zz;
        int c = 0;
        graph *x = malloc(sizeof(graph)); // 头节点
        a[i] = x;
        x->pnext = NULL;
        graph *ptail = x;
        printf("请输入要插入的个数：");
        scanf("%d", &zz);
        while (c < zz)
        {
           
            int bb;
            graph *temp = malloc(sizeof(graph));
            printf("此节点的data值：");
            scanf("%d", &bb);
            temp->data = bb;
            temp->pnext = NULL;
            ptail->pnext = temp;
            ptail = temp; // 尾插法
            c++;
        }
    }
}
void bianligraph(graph *a[], int val)
{
    for (int i = 0; i < val; i++)
    {
        while (a[i]->pnext!=NULL)
        {
            printf("-> %d", a[i]->pnext->data);
            a[i] = a[i]->pnext;
        }
        puts(" ");
    }
    
}
