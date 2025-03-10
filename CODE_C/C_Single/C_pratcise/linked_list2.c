/* 
    2023年11月23日20点21分
    双指针实现链表 
 */
#include <stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct linked_list2
{
    int data;
    struct linked_list2 * next;
}node;
node * create_list(int data);
void insert_list(node**head,int data);
void print_list(node *head);
int main()
{
    node * head = NULL;//head一开始指向null
    insert_list(&head,1); //取了head 的地址 head是指针变量为 int*类型 所以要用 int**类型的变量来接收
    insert_list(&head,2);
    insert_list(&head,3);
    insert_list(&head,4);
    insert_list(&head,5);
    print_list(head);
    system("pause");
    return 0;
}
//此函数实现创建 【一个节点】 并为节点的值域 赋值 data
node * create_list(int data){
    node * new_node = (node*)malloc(sizeof(node));  //为new_node分配一快空间
    new_node->data = data;
    new_node->next = NULL;
    return new_node;//返回值返回这个节点指向的空间
}
//向链表开头插入新的节点  //用int ** 来接收head【int *类型】的地址  此处的 **head1 等价于main函数里的*head
//类似int *head = null;  int **head1 = &head;    【现在*head1 就等价于 head】 
void insert_list(node **head1,int data){
    node * new_node = create_list(data); //让new_node 指向创建的链表  
    if (*head1 == NULL)//即 如果 main函数中的head指向null  第一次head1指向null执行循环，后边就不指向null了，执行下面的
    {
        *head1 = new_node; //即 main函数中的head 指向 new_node 【即新创建的节点】 
        return;
    }
    node *current =  *head1; //让 current指向 main函数中的head 也即current指向new_node
    while (current->next != NULL)
    {
        current = current->next; //自己打断点执行就清楚了 本次理清是在 2023年11月23日21点54分的  第18行打断点实现
    }
    current->next = new_node;//同47行理解
    
}
void print_list(node *head){
    node *P = head;
    while (P != NULL)
    {
        printf("%d->",P->data);
        P = P->next;
    }
    
}
