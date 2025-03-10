/**
 * @file A_arrayqueue.c
 * @author your name (you@domain.com)
 * @brief 运用循环数组实现队列，从队尾进入，队头出去（即队尾进入rear+1，队头出去front-1）
 * @version 0.1
 * @date 2024-04-01
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct A_arrayqueue
{
    int Capacity; // 定义数组容量
    int Front;    // 队头
    int Rear;     // 队尾
    int Size;     // 实际存在于数列中的元素个数（可以比数组容量小）
    int *Array;   // 操纵数组的指针
} Queue, *P_Queue;
void dequeue(P_Queue);        // 出队
void enqueue(P_Queue, int x); // 入队
bool is_empty(P_Queue);
bool is_full(P_Queue);
void make_empty(P_Queue);
void disposequeue(P_Queue);//释放队列
int succ(int index, P_Queue); // 循环数组的角标计算
int front(P_Queue);
int frontAndQueue(P_Queue);
P_Queue CreatQueue(void);
void printqueue(P_Queue);

int main()
{
    P_Queue p = CreatQueue();
    enqueue(p, 1);
    enqueue(p, 2);
    enqueue(p, 3);
    enqueue(p, 4);
    enqueue(p, 5);
    printqueue(p);
    puts("=======================================");
    dequeue(p);
    dequeue(p);
    printqueue(p);
    puts("+++++++++++++++++++++++++++++++++++++++");
    enqueue(p, 666);
    printqueue(p);
    puts("++++++++++++++++++释放队列内存++++++++++");
    disposequeue(p);
    dequeue(p);
    printqueue(p);
    system("pause");
    return 0;
}

P_Queue CreatQueue(void)
{
    puts("请输入想要创建的数组的大小：");
    int x;
    scanf("%d", &x);

    P_Queue q = (P_Queue)malloc(sizeof(Queue)); // 为结构体分配的内存
    q->Array = (int *)malloc(sizeof(int) * x);  // 为结构体中数组分配的内存

    if (q == NULL)
    {
        puts("申请空间失败");
        return NULL;
    }

    if (q->Array == NULL)
    {
        puts("申请空间失败");
        return NULL;
    }
    q->Capacity = x; // 最终数组的大小有x
    make_empty(q);
    return q;
}

void make_empty(P_Queue q)
{
    q->Size = 0;  // 开始size大小为0
    q->Front = 1; //
    q->Rear = 0;  //
    // ▭    ▭    ▭    ▭    ▭   如果Capacity为5，执行完make_empty后应为：
    // rear  front
}
bool is_empty(P_Queue q)
{
    return q->Size == 0;
}

bool is_full(P_Queue q)
{
    return q->Capacity == q->Size; // 即判断数组满了没有
}

void enqueue(P_Queue q, int z)//插入rear指向的下一个角标
{
    if (is_full(q))
    {
        puts("队列已经满了！");
        return;
    }
    else
    {
        q->Size++;                  // 第一个数字1进来时，Size == 1
        q->Rear = succ(q->Rear, q); // 第一个数字1进来时，q->Rear == 1
        q->Array[q->Rear] = z;      // array[1] = z,即第一次为z == 1
                                    /*   第一次执行完毕，rear == front 都为1
                                       ▭    ▭    ▭    ▭    ▭   如果Capacity为5，执行完make_empty后应为：
                                            front
                                            rear
                                        .................................................................
                                        .................................................................
                                        第五次时
                                       ▭    ▭    ▭    ▭    ▭   
                                       rear  front
                                       此时数组中 1，2，3，4，5入队后的情况为
                                       ▭    ▭    ▭    ▭    ▭   
                                       5     1     2     3    4    
                                     */
    }
}

int succ(int index, P_Queue q) // 获取数组角标  也即把角标往右挪一位
{
    index++;  
    return index % q->Capacity; //  //此index时rear+1的值  例：第一次rear为0，传进succ函数后index++后为1 当Size值为5是 1%5 == 1
}

void printqueue(P_Queue q)
{
    int front = q->Front;
    int rear = q->Rear;
    int size = q->Size;
    int capacity = q->Capacity;
    for (int i = front; i < front + size; i++)
    {
        printf("queue中角标为%d的元素为：%d\n", i%capacity, q->Array[i%capacity]);
    }
    
}

void dequeue(P_Queue q)
{
    if (is_empty(q))
    {
        puts("队列为空，不能出队");
        return;
    }
    else
    {
        q->Size--;//例：有5个元素，出队一个后Size为4
        q->Front = succ(q->Front, q);
    }
    
}

void disposequeue(P_Queue q)
{
    if (q != NULL)
    {
        free(q->Array);
        free(q);
    }
    
}