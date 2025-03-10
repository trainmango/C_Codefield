/**
 * @file C_hashtable_thinking_test.c
 * @author your name (you@domain.com)
 * @brief 注：不是真的是先哈希，因为没有使用散列函数在数组中乱序，只是实现了数组挂载链表  
 * 我自己的想法：数组后边挂载链表，实测可行
 * @version 0.1
 * @date 2024-05-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct C_hashtable
{
    int data;
    struct C_hashtable* next;
}HASH, *PHASH;
PHASH a[9];
PHASH createlinkedlist(void);
void bianli(PHASH);
int main() 
{
    a[0] = createlinkedlist(); // a数组是int*类型的，存放int*类型的数据，此例中存放了指向链表的头节点phead
    a[1] = createlinkedlist();
    puts("a[0]中挂载的：");
    bianli(a[0]);
    puts("a[1]中挂载的：");
    bianli(a[1]);
    system("pause");
    return 0;
}
PHASH createlinkedlist(void)
{
    puts("插入元素的尾插法createlinkedlist():【使用temp指针版本】");//注：使用temp指针是指插入的新节点用不用指针指它，而不是有没有pTail
    PHASH Phead = (PHASH)malloc(sizeof(HASH)); // 分配了一个不存放有效数据的头节点
    PHASH PTail = Phead;                       // 只是好操作了定义这个
    PTail->next = NULL;                        // 定义ptail可以不牵扯phead来定义尾节点。因为后面的操作如果用phead直接进行操作，则会找不到phead
    /*然后挂载其余节点*/
    if (Phead == NULL)
    {
        printf("分配失败");
        return NULL;
    }
    int val; // 用来存放 temp->element的值
    puts("输入想要插入的节点个数：");
    int x;
    scanf("%d", &x);
    for (int i = 1; i <= x; i++)
    {
        PHASH temp = (PHASH)malloc(sizeof(HASH)); // 用一个临时指针指向 想插入的新节点
        if (temp == NULL)
        {
            printf("分配失败");
            return NULL;
        }
        printf("请输入第%d个结点的element值：", i);
        scanf("%d", &val);

        temp->data = val;
        temp->next = NULL;
        PTail->next = temp;
        PTail = temp; // 尾插法
    }

    return Phead;
}
void bianli(PHASH Phead)
{
    if (Phead == NULL)
    {
        puts("失败分配");
        return;
    }
    PHASH pp = Phead->next; // 让p指向第一个有效的节点
    puts("链表中元素分别为：");
    int i = 1;
    while (pp != NULL)
    {
        printf("第%d个元素为:%d\n", i, pp->data); //
        pp = pp->next;
        i++;
    }
}