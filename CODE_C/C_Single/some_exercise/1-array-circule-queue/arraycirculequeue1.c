#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
/**
 * 以rear + 1 == front 为界限的循环队列
 * rear 和 front之间永远有一个格子不用，即 q->capacity - 1为我的循环链表的容量
 * 
 */
typedef struct arraycirculequeue
{
    int capacity;
    int Front; // 队头
    int Rear;  // 队尾
    int *queue;
} queue;
void init(queue *);
void enqueue(queue *, int);
int dequeue(queue *q);
bool is_empty(queue *q);
bool is_fulled(queue *q);
void bianli(queue *q);
int main()
{
    queue *q = malloc(sizeof(queue));
    if (q == NULL)
    {
        printf("分配内存失败");
        exit(-1);
    }

    init(q);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 6);
    enqueue(q, 7);
    enqueue(q, 8);
    enqueue(q, 9);
    bianli(q);
    printf("出队：%d\n", dequeue(q));
    printf("出队：%d\n", dequeue(q));
    printf("出队：%d\n", dequeue(q));
    printf("出队：%d\n", dequeue(q));
    printf("出队：%d\n", dequeue(q));
    printf("出队：%d\n", dequeue(q));
    printf("出队：%d\n", dequeue(q));
    printf("出队：%d\n", dequeue(q));
    return 0;
}
void init(queue *q)
{
    q->capacity = 6;

    q->Front = 0;
    q->Rear = 0;
    q->queue = malloc(sizeof(int) * q->capacity);
    if (q->queue == NULL)
    {
        printf("分配内存失败");
        return;
    }
}

void enqueue(queue *q, int val)
{
    if (is_fulled(q))
    {
        printf("满了\n");
        return;
    }

    q->queue[q->Rear] = val;
    q->Rear = (q->Rear + 1) % q->capacity;
}

int dequeue(queue *q)
{
    if (is_empty(q))
    {
        printf("空的\n");
        return -999;
    }
    int val = q->queue[q->Front];
    q->Front = (q->Front + 1) % q->capacity;
    return val;
}
bool is_empty(queue *q)
{
    if (q->Front == q->Rear)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool is_fulled(queue *q)
{
    if ((q->Rear + 1) % q->capacity == q->Front)
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
    int i = Q->Front;
    while (i != Q->Rear)
    {
        printf("%d ", Q->queue[i]);
        i = (i + 1) % 6;
    }
}