/**
 * @file realizedhash.c
 * @author your name (you@domain.com)
 * @brief  相当于【用哈希函数】数组挂载链表 完美实现
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
#define MinTableSize 5

struct linked_list
{
    int data;
    struct linked_list *next;
};

struct realizedhash
{                                     //注：struct linked_list* TheLists[]是一个指针数组，数组中存放的是指针变量！！！！！！！！！！
    int TableSize;                     //即指针变量即头节点
    struct linked_list **TheLists; // 即struct linked_list* TheLists[]  []中的一会在malloc中的sizeof()*num定义数组大小
}; // 然后在数组的某些节点上挂载经过哈希函数处理的新节点
struct realizedhash *HashTable_initialize(int); // 初始化
int Nextprime(int);                             // 若不是素数，找它下一个素数
bool is_prime(int);                             // 判断是否为素数
int Hashfunction(int, int);                     // 哈希函数
void insert(struct realizedhash *, int);
struct linked_list *find(int, struct realizedhash *); // 查找
void bianli(struct linked_list*);
int main()
{
    int key = 6;
    struct realizedhash *H = HashTable_initialize(10);
    insert(H, key);
    insert(H, 33);
    insert(H, 17);
    insert(H, 28);
    insert(H, 39);
    insert(H, 50);
    printf("%d\n", find(key, H)->data);
    printf("%d\n", find(33, H)->data);
    printf("%d\n", find(17, H)->data);
    bianli(H->TheLists[6]);
      bianli(H->TheLists[0]);
     

    system("pause");
    return 0;
}
int Nextprime(int val)
{
    while ((is_prime(val)) != true)
    {
        val++;
    }
    return val;
}
bool is_prime(int val)
{
    for (int i = 2; i < val / 2; i++)
    {
        if (val % i == 0)
        {
            break;
        }
        if (i < val)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
struct realizedhash *HashTable_initialize(int TableSize)
{
    struct realizedhash *H;
    int i;

    if (TableSize < MinTableSize)
    {
        puts("error,spiece is too small");
        return NULL;
    }

    H = malloc(sizeof(struct realizedhash)); // 先让H指向这块结构体
    if (H == NULL)
    {
        puts("out of space");
        return NULL;
    }
    H->TableSize = Nextprime(TableSize); // 选取TableSize之后的一个素数例：TableSize为10则会选出11

    H->TheLists = malloc(sizeof(struct linked_list *) * H->TableSize); // 表大小乘指针变量大小 数组大小不固定，即struct ListNode* TheLists[H->TableSize];
    if (H->TheLists == NULL)
    {
        puts("error,out of space");
        return NULL;
    }
    for (i = 0; i < H->TableSize; i++)
    { // 注： 不是struct linked_list** TheLists = malloc(sizeof(struct linked_list));
      //      而是struct linked_list** TheLists; *TheLists = malloc(sizeof(struct linked_list));
        H->TheLists[i] = malloc(sizeof(struct linked_list));
        if (H->TheLists[i] == NULL) // struct linked_list **TheLists; // 即struct linked_list* TheLists[]  []中的一会在malloc中的sizeof()*num定义数组大小
        {
            puts("out of space");
        }
        else
        {
            H->TheLists[i]->next = NULL; // 未用到时，让数组中的next域均指空 //TheLists[i]中存放的是地址
        }
        // *(*TheLists + i) == *TheLists[i]
        // TheLists是struct linked_list**类型的 即TheLists[i]是struct linked_list*类型的
    }
    return H;
}
int Hashfunction(int val, int TableSize)
{
    return val % TableSize;
}
struct linked_list *find(int key, struct realizedhash *H)
{
    struct linked_list *P;
    struct linked_list *L;

    L = H->TheLists[Hashfunction(key, H->TableSize)]; // 再次通过哈希函数找到这张表中的数据
    P = L->next;
    while (P != NULL && P->data != key)
    {
        P = P->next;
    }
    return P;
}
void insert(struct realizedhash *H, int key)
{
    struct linked_list* Pos,*NewCell,*L;
    Pos = find(key, H);//看要插入的是否已存在
    if (Pos == NULL)//未找到
    {
        NewCell = malloc(sizeof(struct linked_list));
        if (NewCell == NULL)
        {
            puts("out of space");
            return;
        }
        else
        {
            L = H->TheLists[Hashfunction(key, H->TableSize)];//用哈希函数获取角标
            NewCell->next = L->next;
            NewCell->data = key;
            L->next = NewCell;
            //头插法

        }
        
        
    }
    
    
}
void bianli(struct linked_list* Phead)
{
    if (Phead == NULL)
    {
        puts("失败分配");
        return;
    }
    struct linked_list* pp = Phead->next; // 让p指向第一个有效的节点
    puts("链表中元素分别为：");
    int i = 1;
    while (pp != NULL)
    {
        printf("第%d个元素为:%d\n", i, pp->data); //
        pp = pp->next;
        i++;
    }
}