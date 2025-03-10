/*
   2023年11月23日18点31分
   链表练习   创建 与  遍历

 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct linked_list
{
    int data;
    struct linked_list *PNext;
} *PNODE, NODE;
PNODE create_linked_list(void);
void bianli(PNODE HEAD);
int main()
{
    PNODE HEAD = create_linked_list(); // phead指向了创建好的链表
    bianli(HEAD);
    system("pause");
    return 0;
}
PNODE create_linked_list(void)
{
    int val;                                  // 节点 值
    int len;                                  // 节点 长度
    PNODE HEAD = (PNODE)malloc(sizeof(NODE)); // 头指针分配一块空间,即指向头节点
    if (HEAD == NULL)
    {
        printf("分配失败！终止！");
        exit(-1);
    }
    PNODE PTAIL = HEAD; // 尾指针指向头指针 （在还未分配节点的时候）
    PTAIL->PNext = NULL;
    printf("请输入链表的长度：");
    scanf("%d", &len);
    for (int i = 1; i <= len; i++)
    {
        printf("请输入第%d个节点的值：", i);
        scanf("%d", &val);

        PNODE Pnew = (PNODE)malloc(sizeof(NODE));
        if (Pnew == NULL)
        {
            printf("分配失败！终止！");
            exit(-1);
        }
        // 尾插法
        Pnew->data = val;
        PTAIL->PNext = Pnew; // 每次循环单次 而不是 直接定义完全部的链表节点 ，一次循环只定义一个
        Pnew->PNext = NULL;
        PTAIL = Pnew; // 让ptail指向最后一个节点
    }
    return HEAD;
}

void bianli(PNODE HEAD)
{
    PNODE P = HEAD->PNext; // 让P指向头节点的下一个节点即第一个有效节点。
    while (P != NULL)
    {
        printf("%d->", P->data);
        P = P->PNext;
    }
}

/*经验与总结：因为head指向了头节点为一个没有值的垃圾节点所以若这样输出 则为
  void bianli(PNODE HEAD){
    while (HEAD != NULL)
    {
        printf("%d->", HEAD->data);
        HEAD = HEAD->PNext;
    }
}

请输入链表的长度：3
请输入第1个节点的值：1
请输入第2个节点的值：2
请输入第3个节点的值：3
-1163005939->1->2->3->请按任意键继续. . .
有一个垃圾值 为头节点带的无效值


*/