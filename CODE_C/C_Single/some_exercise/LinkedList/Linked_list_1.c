/**
 * @file Linked_list_1.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-07-19
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct Linked_list
{
    int data;
    struct Linked_list *next;
} node;
void creat(node **); // 另一种创造函数，使用了双指针 不用返回值了
node *creatLinkedList();
node *creat_new_node(int);
void insert_in_last(node *, int);
void insert_in_last1(node **head, int element);
void insert_in_first(node *, int);
void insert_position(node *, int, int);
void delete_last(node *);
void delete_first(node *);
void delete_choose_position(node *, int);
void delete_choose_position2(node *, int);
void print(node *);
void getLength(node *);
void *reverseList(node *);


int main()
{
    // node *head = creatLinkedList(); // 这种也可以
    node *head = NULL;
    creat(&head);
    
    reverseList(head);
    printf("反转后的链表为：");
    print(head);

    insert_in_first(head, 567);
    insert_in_last(head, 234);

    delete_last(head); // 删除了first 567

    delete_first(head);

    delete_choose_position2(head, 4);

    insert_position(head, 5, 256);

    getLength(head);

    printf("+++++++++");
    node *head1 = NULL;
    insert_in_last1(&head1, 2323);

    insert_in_last1(&head1, 23233333);
    print(head1);
    // system("pause");
    return 0;
}

void creat(node **head)
{
    *head = malloc(sizeof(node));
    if (*head == NULL)
    {
        puts("error,out of space");
        return;
    }
    (*head)->next = NULL;

    node *temp = *head; // 直接操作也是需要临时指针的， 不然*head找不到了

    int element1, element2;
    printf("输入需要的节点个数：");
    scanf("%d", &element1);
    for (int i = 1; i <= element1; i++)
    {
        printf("输入第%d节点值：", i);
        scanf("%d", &element2);
        node *new = creat_new_node(element2);

        temp->next = new;
        temp = temp->next;
    }
}

node *creatLinkedList()
{
    node *head = malloc(sizeof(node));
    if (head == NULL)
    {
        puts("error,out of space");
        return NULL;
    }
    head->next = NULL;

    node *temp = head;

    int element1, element2;
    printf("输入需要的节点个数：");
    scanf("%d", &element1);
    for (int i = 1; i <= element1; i++)
    {
        printf("输入第%d节点值：", i);
        scanf("%d", &element2);
        node *new = creat_new_node(element2);

        temp->next = new;
        temp = temp->next;
    }
    return head;
}

node *creat_new_node(int element)
{
    node *new = malloc(sizeof(node));
    if (new == NULL)
    {
        puts("error, out of space");
    }

    new->data = element;
    new->next = NULL;
    return new;
}

void print(node *head)
{
    if (head == NULL)
    {
        puts("error, out of space");
        return;
    }
    node *p = head->next;
    printf("遍历输出为：");
    while (p != NULL)
    {
        printf("%d->", p->data);
        p = p->next;
    }
    puts(" ");
}

void insert_in_last(node *head, int element) // 只能处理 有头指针的 若想处理为NULL的 则需要 将 void 变为 node*的 再return head;
{                                            // 在main中调用的时候为 head = insert_in_last(head, int element); 比较繁琐
    if (head == NULL)
    {
        puts("error, out of space");
        return;
    }
    node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = creat_new_node(element);
    printf("在最后插入元素后：   ");
    print(head);
}

void insert_in_last1(node **head, int element) // 可以处理头指针为空的情况  void若不用二级指针，会导致创造副本，而不是直接操纵链表
{                                              //  当然，也可以用node *insert_in_last1(node *head, int element){ return head;  }来操纵
    if ((*head) == NULL)
    {
        (*head) = malloc(sizeof(node));
        (*head)->next = creat_new_node(element); // 将头指针指向新节点
        return;
    }
    node *p = *head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = creat_new_node(element);
    printf("在最后插入元素后：   ");
    print(*head);
}

void insert_in_first(node *head, int element)
{
    if (head == NULL)
    {
        puts("error, out of space");
        return;
    }
    node *s = creat_new_node(element);
    s->next = head->next;
    head->next = s;
    printf("在头部插入元素之后：   ");
    print(head);
}

void insert_position(node *head, int pos, int val)
{
    if (head == NULL)
    {
        puts("error, out of space");
        return;
    }

    if (pos < 0)
    {
        puts("Error: Invalid position");
        return;
    }

    node *p = head;
    for (int i = 0; i < pos; i++)
    {
        if (p->next == NULL)
        {
            puts("超出插入范围了");
            return;
        }
        p = p->next;
    }
    node *temp = creat_new_node(val);
    temp->next = p->next;
    p->next = temp;

    printf("在第%d个节点之后插入：   ", pos);
    print(head);
}

void delete_last(node *head)
{
    if (head == NULL) // 如果链表为空，直接返回
    {
        return;
    }
    node *SecondLastNode = head;
    while (SecondLastNode->next->next != NULL)
    { 
        SecondLastNode = SecondLastNode->next;
    }
    free(SecondLastNode->next);
    SecondLastNode->next = NULL;
    printf("删除最后一个元素后：  ");
    print(head);
}

void delete_first(node *head)
{
    if (head == NULL) // 如果链表为空，直接返回
    {
        return;
    }
    node *p = head->next;
    node *temp = p->next;
    head->next = temp;
    free(p);
    printf("删除第一个元素之后：  ");
    print(head);
}

void delete_choose_position(node *head, int pos)
{
    node *p = head;
    node *temp;
    for (int i = 1; i <= pos; i++)
    {
        temp = p; // 两个指针，滑动的选出要删除元素前的 那个节点
        p = p->next;
    }
    temp->next = p->next;
    free(p);
}

// 也可以这样子写，不用临时指针，直接找此位置前边的那个节点
void delete_choose_position2(node *head, int pos)
{
    if ((head == NULL) || (head->next == NULL))
    {
        puts("error,list is empty");
        return;
    }

    if (pos < 1)
    {
        puts("出错，不能删除无效节点！");
        return;
    }

    node *p = head;
    for (int i = 1; i < pos; i++)
    {
        if (p->next == NULL)
        {
            puts("超出删除范围了");
            return;
        }
        p = p->next;
    }

    // 检查要删除的节点是否存在
    if (p->next == NULL)
    {
        puts("超出删除范围了");
        return;
    }

    node *temp = p->next;
    p->next = p->next->next;
    free(temp);
    printf("删除第%d个节点之后：  ", pos);
    print(head);
}

void getLength(node *head)
{
    if (head == NULL) // 如果链表为空，直接返回
    {
        return;
    }
    int length = 0;
    node *temp = head->next;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    printf("链表的长度为：%d\n", length);
}
void *reverseList(node *head)
{
    node *pre = NULL;
    node *cur = head->next;
    node *next = NULL;
    while (cur != NULL)
    {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    head->next = pre;
}

