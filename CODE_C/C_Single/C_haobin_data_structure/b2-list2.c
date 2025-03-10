/* 
   2023年3月30日20点58分
   链表创建和链表遍历算法的演示
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Node
{
    int data;  //数据域
    struct Node * pNext;  //指针域  //即指针是struct Node *类型的
}NODE, *PNODE;  //NODE等价于struct Node,   PNODE等价于struct Node * 
 //函数声明  
PNODE create_list(void); 

/*一般来说插入一个新节点有两种 类似于 t=p->PNext; p->PNext = q; q->PNext = t;  相当于 t = a ,a=b ,b=t s换一下
法二： q->PNext = p->PNext; p->PNext = q;
*/

/*
 删除一个节点  t = p->PNext;  p->PNext = p->PNext->PNext;   free(t);
     //若不先把要删除的节点指一下保存，即会内存越用越少没释放它  
     free(p);讲解： p是栈内存，p所指向的是堆内存 //free(p)相当于把p 指向的节点所占的内存删除，不是删除p本身所占的内存
*/

void traverse_list(PNODE pHead);
int main()
{
    PNODE pHead = NULL; //等价于 struct Node * pHead = NULL;

    pHead = create_list();  //create_list();功能：创建一个非循环单链表，并将该链表的头结点的地址赋给pHead
    //相当于 int * a; a = &b; 上边把该链表的头结点的地址赋给pHead 即pHead = &头结点的地址;
    traverse_list(pHead);  //遍历 //在这里即把该链表的头结点的地址赋给这个函数
    
    system("pause");
    return 0;
}
PNODE create_list(void)
{
    int len; //用来存放有效节点的个数
    int i;
    int val; //用来临时存放用户输入的结点的值

    //分配了一个不存放有效数据的头节点
    PNODE pHead = (PNODE)malloc(sizeof(NODE));//让头指针指向一块(PNODE)malloc(sizeof(NODE))大小的空间，即指向头节点
    if (NULL == pHead)
    {
        printf("分配失败，程序终止！\n");
        exit(-1);
    }
    PNODE pTail = pHead;//目前pTail 和 pHead都指向了头节点
    pTail->pNext = NULL;//有可能一个节点都没有，所以多加一句尾部指向null，这样再len = 0时头指针，尾指针都指向了null 
    
    
    printf("请输入您需要生成的链表结点的个数：len = ");
    scanf("%d", &len);

    for ( i = 0; i < len; i++)
    {
        printf("请输入第%d个结点的值： ", i+1); //i=0时输入的是第一个结点，i=1时输入的是第2个结点
        scanf("%d", &val);
        
        PNODE pNew = (PNODE)malloc(sizeof(NODE));  //执行len次，每次分配一个【NODE等价于struct Node】大小的空间，再令pNew指向它
        if (NULL == pNew)                          //相当于pNew造新节点
        {
            printf("分配失败，程序终止！\n");
            exit(-1);
        }
        pNew->data = val;// 每次循环中 为 pNew的data域赋值val 
        pTail->pNext = pNew; //每次将pNew挂到pTail上 ，相当于每次都把一个新节点挂到尾节点上
        pNew->pNext = NULL;  //再让新节点成为尾节点
        pTail = pNew;//相当于还原 让pTail重新成为尾节点
        //尾插法
        

    }
    return pHead;//最后返回的是PNODE类型的pHead给int main中的pHead 两pHead不是一个
}
                                 //形参的类型需要与实参一致
void traverse_list(PNODE pHead)  //形参需要有数据类型 例：pHead为PNODE类型
{                                  //此pHead不是main函数中的pHead 就是写PNODE x也可以
    PNODE p = pHead->pNext; //相当于用了 【上边把该链表的头结点的地址赋给pHead】的地址赋给形参，就可以改变主函数中的值了
       //让p指向 头指针所指向头节点的下一个节点 
    while (NULL != p)
    {
        printf("%d ", p->data);
        p = p->pNext; 
    }
    printf("\n");

    return;
    
    
}