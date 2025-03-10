/**
 * @file c-Stack.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-04-20
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *pNext;
} NODE, *PNODE;

typedef struct Stack
{
    PNODE pTop;
    PNODE pBottom;
} STACK, *PSTACK;

void init(PSTACK);
void push(PSTACK, int);
bool pop(PSTACK, int *);
void trasverse(PSTACK);
bool empt(PSTACK); // 判断是否为空
void clear(PSTACK);
int main()
{
    STACK S;
    int val;
    init(&S);
    push(&S, 1);
    push(&S, 2);
    push(&S, 3);
    push(&S, 4);
    push(&S, 5);
    push(&S, 6);
    push(&S, 7);
    push(&S, 8);
    trasverse(&S);

    if (pop(&S, &val))
    {
        printf("出战成功，出栈的元素是%d\n", val);
    }
    else
    {
        printf("出栈失败");
    }
    trasverse(&S);

    clear(&S);
    trasverse(&S);

    system("pause");
    return 0;
}

void init(PSTACK pS) // 相当于创建了一个有头节点，头指针的链表
{
    pS->pTop = malloc(sizeof(NODE)); // 最开始 S栈中的pTop指向头节点
    if (NULL == pS->pTop)
    {
        puts("分配失败");
        return;
    }
    else
    {
        pS->pBottom = pS->pTop; //pBottom不动了，类似头指针
        pS->pTop->pNext = NULL; // pS->pBottom->pNext = NULL;也可以
    }
}

void push(PSTACK pS, int val)
{
    PNODE p = malloc(sizeof(NODE));
    p->data = val;
    p->pNext = pS->pTop;
    pS->pTop = p;
}

void trasverse(PSTACK pS) // 注意：只是遍历，而不是出栈！
{
    if (empt(pS))
    {
        puts("空栈！");
        return;
    }
    else
    {
        PNODE p = pS->pTop; // 让一个指针指向栈顶元素
        while (p != pS->pBottom)
        {
            printf("%d\n", p->data);
            p = p->pNext;
        }
    }
}

bool empt(PSTACK pS)
{
    if (pS->pTop == pS->pBottom)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 把pS所指向的栈出栈一次，并把出栈的元素存入pVal中形参所指向的变量中
// 出栈失败返回false，成功返回true
bool pop(PSTACK pS, int *pVal)
{
    if (empt(pS))
    {
        return false;
    }
    else
    {
        PNODE r = pS->pTop; // 保存栈顶来free，避免找不到，内存泄漏了
        *pVal = r->data;
        pS->pTop = pS->pTop->pNext;
        free(r);
    }
}

void clear(PSTACK pS) // 是清空栈，而不是销毁
{
    if (empt(pS))
    {
        return;
    }
    else
    {
        PNODE p = pS->pTop;
        PNODE q = p->pNext;
        while (p != pS->pBottom)
        {
            q = p->pNext;
            free(p);
            p = q;
        }
        pS->pTop = pS->pBottom;
    }
}


