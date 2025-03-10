/**
 * @file C_arrayqueue.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-05-25
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
typedef struct C_arrayqueue
{
    int front;
    int rear;
    int *pBase; // 也可以写为：pBase[];但是下边动态分配内存可以更好的选择数组大小
} queue;
void init(queue *);
void enqueue(queue *, int);
void dequeue(queue *);
bool is_empty(queue *);
bool is_fulled(queue *);
void bianli(queue *);
int main()
{
/** queue *Q = malloc(sizeof(queue));  //也可以
    init(Q);
    enqueue(Q, 3);
    enqueue(Q, 4);
    enqueue(Q, 5);
    enqueue(Q, 6);
    enqueue(Q, 7);
    enqueue(Q, 99);
    enqueue(Q, 88);
    bianli(Q);
    dequeue(Q);
    bianli(Q);*/
    queue Q;
    init(&Q);
    enqueue(&Q, 3);
    enqueue(&Q, 4);
    enqueue(&Q, 5);
    enqueue(&Q, 6);
    enqueue(&Q, 7);
    enqueue(&Q, 99);
    enqueue(&Q, 88);
    bianli(&Q);
    dequeue(&Q);
    bianli(&Q);
    system("pause");
    return 0;
}
void init(queue *Q)
{
    Q->pBase = malloc(sizeof(int) * 6); // Q中的pBase指向了一块含有6个的int类型的数组
    Q->front = 0;
    Q->rear = 0;
}
void enqueue(queue *Q, int val)
{
    if (is_fulled(Q))
    {
        puts("队列已满，不能入队");
        printf("不能插入的值为：%d\n", val);
        return;
    }
    else
    {
        Q->pBase[Q->rear] = val;
        Q->rear = (Q->rear + 1) % 6;
    }
}
void dequeue(queue *Q)
{
    if (is_empty(Q))
    {
        puts("队列为空，不能出队");
        return;
    }
    else
    {
        Q->front = (Q->front + 1) % 6;
    }
    
    
}
bool is_fulled(queue *Q)
{
    if ((Q->rear + 1) % 6 == Q->front)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool is_empty(queue *Q)
{
    if (Q->front == Q->rear)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void bianli(queue *Q)
{
    printf("队列中的元素为：");
    int i = Q->front;
    while (i != Q->rear)
    {
        printf("%d ", Q->pBase[i]);
        i = (i+1)%6;
    }
}