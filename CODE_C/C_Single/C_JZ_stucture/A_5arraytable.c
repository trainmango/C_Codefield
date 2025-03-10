/**
 * @file A_5arraytable.c
 * @author your name (you@domain.com)
 * @brief 数组实现链表这些功能
 * @version 0.1
 * @date 2024-03-28
 *
 * @copyright Copyright (c) 2024
 * @todo 实现一个表的数据结构，可以进行插入，查询，删除，判空，获取大小等操作
 */
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
typedef struct A_5arraytable
{
    int element[SIZE];
    int length; // 记录是第几个数据,即标记有效元素个数
} NODE, *PNODE;
PNODE creaat_list();
void bianli(PNODE);
void insert_in_last(PNODE, int);
void insert_in_first(PNODE, int);
void findoutpos(PNODE, int pos);//找pos位置对应的元素
void findoutnum(PNODE, int val);//找对应的数值
void delete_num(PNODE, int val);//类似的，可以运用到找到元素为止的思想来确定元素位置后在其后插入元素
void insert_in_anywhere(PNODE, int pos, int val);
//尾插 头删 即可实现队列
int main()
{
    PNODE p = creaat_list();
    insert_in_first(p, 3);
    insert_in_first(p, 4);
    insert_in_first(p, 5);
    insert_in_first(p, 6);
    insert_in_last(p, 44);
    insert_in_last(p, 33);
    insert_in_last(p, 22);
    insert_in_last(p, 11);
    bianli(p);
    printf("共有%d个数组元素\n", p->length);
    
    findoutnum(p, 44);
    findoutpos(p, 3);
    delete_num(p, 33);
    printf("删除后此时length为%d\n",p->length);
    bianli(p);
    printf("\n");
    insert_in_anywhere(p, 5, 69);
    printf("插入元素后length为:%d\n",p->length);
    printf("\n");
    bianli(p);
    printf("\n");
    system("pause");
    return 0;
}

PNODE creaat_list()
{
    PNODE pp = (PNODE)malloc(sizeof(NODE));
    pp->length = 0;
    return pp;
}

void bianli(PNODE p)
{
    for (int i = 0; i < p->length; i++)
    {
        printf("%d  ", p->element[i]);
    }
    
}

void insert_in_first(PNODE p, int x)
{
    if (p->length >= SIZE)
    {
        printf("表满了");
        exit(-1);
    }
    for (int i = p->length; i > 0; i--)
    {
        p->element[i] = p->element[i-1];
    }
    p->element[0] = x;  //头插，依次把元素往后移动，头部空出来再插入
    p->length++;
}

void insert_in_last(PNODE p, int x) // 因为数组角标比个数少1， 所以
{
    
    if (p->length >= SIZE)
    {
        printf("表满了");
        exit(-1);
    }
    p->element[p->length] = x; //不用给p->length加1，直接用即可
    p->length++; 
    
}

void findoutpos(PNODE p, int pos)
{   
  if( printf("要找的值为%d的元素", p->element[pos-1]))
     { 
        puts("找到");
     }
     else
     {
        puts("未找到");
        return;
     }
}

void findoutnum(PNODE p, int val)
{
    for (int i = 0; i < p->length ; i++) //从0~3
    {
        if (p->element[i] == val)
    {
        printf("找到%d这个元素\n", p->element[i]);
    }
    
    
    }
    
    
}

void delete_num(PNODE p, int val)//类似的，可以运用到找到元素为止的思想来指定位置插入
{
    for (int i = 0; i < p->length; i++)
    {
        if (p->element[i] == val)
        {
            for ( ; i < p->length - 1; i++)
            {
                p->element[i] = p->element[i+1];//到找到的元素为止，所有元素往前移动
            }
            p->length--;
            break;
        }
        
    }
    
}

void insert_in_anywhere(PNODE p, int pos, int val)
{
    
     if (p->length >= SIZE)
    {
        printf("表满了");
        exit(-1);
    }
    p->length++;
    for (int i = p->length -1  ; i >= pos - 1; i--) //i >= pos - 1这里是一个坑，因为i=4这次也要往后移动
    {
       // p->element[i] = p->element[i-1];  //到找到的元素为止，所有元素往后移动 这样写错的，
       //因为循环赋值往后都是一样的数了，要么倒过来写循环，要么用第三个杯子t
       p->element[i+1] = p->element[i];
        
    }
    
    p->element[pos - 1] = val;  
    
}