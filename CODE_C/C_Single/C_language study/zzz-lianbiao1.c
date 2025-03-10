/*
   2023年2月10日17点12分
   链表
   
   
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
//定义了一个链表节点的数据类型
struct Node
{
    int data;
    struct Node * pNext;
  
};

int main()
{
    struct Node * pHead;  //pHead用来存放链表头结点的地址 
    pHead = CreateList();
    TraverseList(pHead);
    system("pause");
    return 0;
}
