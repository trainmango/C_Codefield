/* 
   2023年4月5日15点44分
   判断 链表是否为空 和 求链表长度算法 的演示
   通过链表排序算法的演示 再次详细讨论到底什么是算法以及到底什么是泛型
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>


typedef struct Node
{
    int data;  //数据域
    struct Node * pNext;  //指针域  //即指针是struct Node *类型的
}NODE, *PNODE;  //NODE等价于struct Node,   PNODE等价于struct Node * 
 //函数声明  
PNODE create_list(void); 
void traverse_list(PNODE pHead); //遍历 //同下
bool is_empty(PNODE pHead); //是否为空 //同下
int length_list(PNODE); //求链表长度 //声明的时候形参名写不写无所谓
bool insert_list(PNODE, int, int);//插入 //需要三个参数 1.哪个链表 2.哪个位置 3.插入哪个值
bool delete_list(PNODE, int, int *);//删除 //三个参数 1.哪个链表 2.哪个节点 3.把要删除的那个结点放在第三个参数里面去
void sort_list(PNODE); //排序  

int main()
{
    PNODE pHead = NULL; //等价于 struct Node * pHead = NULL;

    pHead = create_list();  //create_list();功能：创建一个非循环单链表，并将该链表的头结点的地址赋给pHead
    traverse_list(pHead);  //遍历
    if (is_empty(pHead))
    {
        printf("链表为空！\n");
    }
    else
    {
        printf("链表不为空！\n");
    }
    int len = length_list(pHead);
    printf("链表的长度为%d\n", len);
    sort_list(pHead);
    traverse_list(pHead);
    insert_list(pHead, 1, 666);
    insert_list(pHead, 4, 33);
    traverse_list(pHead);
    system("pause");
    return 0;
}
PNODE create_list(void)
{
    int len; //用来存放有效节点的个数
    int i;
    int val; //用来临时存放用户输入的结点的值

    //分配了一个不存放有效数据的头节点
    PNODE pHead = (PNODE)malloc(sizeof(NODE));
    if (NULL == pHead)
    {
        printf("分配失败，程序终止！\n");
        exit(-1);
    }
    PNODE pTail = pHead;//定义ptail可以不牵扯phead来定义尾节点。因为后面的操作如果用phead直接进行操作，则会找不到phead
    /*然后挂载其余节点*/
    pTail->pNext = NULL;
    
    
    printf("请输入您需要生成的链表结点的个数：len = ");
    scanf("%d", &len);

    for ( i = 0; i < len; i++)
    {
        printf("请输入第%d个结点的值： ", i+1); //i=0时输入的是第一个结点，i=1时输入的是第2个结点
        scanf("%d", &val);
        
        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if (NULL == pNew)
        {
            printf("分配失败，程序终止！\n");
            exit(-1);
        }
        pNew->data = val;
        pTail->pNext = pNew;
        pNew->pNext = NULL;
        pTail = pNew;
        //尾插法
        

    }
    return pHead;
}

void traverse_list(PNODE pHead)
{
    PNODE p = pHead->pNext;

    while (NULL != p)
    {
        printf("%d ", p->data);
        p = p->pNext; 
    }
    printf("\n");

    return;
    
    
}
bool is_empty(PNODE pHead)
{
    if (NULL == pHead->pNext)
    {
        return true;
    }
    else
    {
        return false;
    }
    
    
}
int length_list(PNODE pHead)
{
    PNODE p = pHead->pNext;
    int len = 0;
    while (NULL != p)
    {
        len++;
        p = p->pNext;
    }
    return len;
}
void sort_list(PNODE pHead)
{

    /*
    在数组中用选择排序来进行排序
     int i, j, t;   
     //例：第一步：第一个元素分别和其他元素比较大小
    for ( i = 0; i < len-1; i++)  //选择排序： 例： 8个数， 第一个需要比较7次，同理5个4次。
    {    
        for ( j=i+1; j < len; j++)  //第二个for循环中，让 a[i]和a[j]比较大小完成排序
        {
            if (a[i]>a[j])
            {
                t = a[i];
                a[i] = a[j];
                a[j] = t;    
            }
            
        }
        
    }
     */
    //利用泛型的思想，若是利用某种技术达到的效果就是：不同的存储方式，执行的操作是一样的。即可
    //即是利用上述的注释中的选择排序，让其改变存储结构也成立
     int i, j, t;   
     int len = length_list(pHead);
     PNODE p, q;
      //此句中i = 0,p = pHead->pNext;是第一句，共三句。 注：泛型思想，其他语言中的容器也是这一思想
    for ( i = 0,p = pHead->pNext; i < len-1; i++, p = p->pNext)  
    {    
        for ( j=i+1,q = p->pNext; j < len; j++, q = q->pNext)  
        {
            if (p->data > q->data)  //类似于数组中的： a[i]>a[j]
            {
               t = p->data;
               p->data = q->data;
               q->data = t;
            }
            
        }
        
    }
    return;
}
bool insert_list(PNODE Phead, int pos, int val)// 在Phead节点所指向的链表 的 pos节点的前面 插入一个新的节点 其值为val
{                                                 //pos的值从1开始     【例 pos为4】  1 2 3 4 中插入 66  【即 第四个前边 也即 第三个后边】
   int i = 0;                                      //                                        为1 2 3 66 4
   PNODE p = Phead;  //p指向这个链表                     //                        而 1 2 3 中插入 66
                                                 //                                          为 1 2 3 66
   while (NULL!=p && i<pos-1)// 判断出共有多少个节点  【p没有循环到最后一个节点 且 i的值小于节点总数 - 1的值 】
   {                            //画图 理解 例：当len = 4; pos = 4时，pos -1 为 3，第一次时，p = phead;让p指向 头指针【phead】指向的头节点的下一个节点
      p = p->pNext;              //  本程序中p = phead一共执行三次，         即指向第一个有效节点 ………最终选定了第三个节点 也即第四个节点的前一个节点
      i++;                       //      从第三个节点后用尾插法插入这个新节点   即从第四个节点前插入新的节点            【pos = 4】
   }
   printf("%d\n", i);
   if (i>pos-1 || NULL==p)
   {
     return false;
   }
   PNODE pNew = (PNODE)malloc(sizeof(NODE));
   if (NULL == pNew)
   {
    printf("动态内存分配失败！");
    exit(-1);
   }
   //这一块的 是插入 节点
   pNew->data = val;    // 也可以这样写 PNODE q = p->pNext;  q = p->pNext;  p->pNext = pNew;  pNew->pNext = q;
   pNew->pNext = p->pNext;
   p->pNext = pNew;

   
}