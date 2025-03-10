/**
 * @file A_linkedlist.c
 * @author your name (you@domain.com)
 * @brief 自己实现一次链表
 * @version 0.1
 * @date 2024-03-27
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct A_linkedlist
{
    int element;
    struct A_linkedlist *NEXT;
} NODE, *PNODE;
/**
 * @brief 头插法，尾插法都可以实现栈，pop相当于头插或者尾插，push相当于删除时只能删除第一个或者最后一个元素
 *
 * @return PNODE
 */

/**
 * @brief 队列中：  用尾插法入队，用一直删除第一个有效节点来出队
 *
 * @return PNODE
 */
PNODE createlinkedlist(void); // 尾插法创建链表
PNODE creat_in_first(void);   // 头插法建立链表
bool isempty(PNODE);
void bianli(PNODE);
PNODE findoutnumber(PNODE, int val);
PNODE findoutposition(PNODE, int pos); // 思路：用一个变量计数
void delete_pos(PNODE, int);
void delete_num(PNODE, int);
PNODE insert(PNODE, int pos, int val); // pos记录插入的位置，val记录插入的数值
PNODE insert_in_last(PNODE, int val);  // 相当于尾插法 也即栈的push操作 同理若定义一个pop函数 从尾部删除，即完成了这个栈的实现
PNODE cr(void);
PNODE cr_in_first(void);           // 类似cr()的不同第三个temp指针创建链表 头插 的方法 这种方法需要定义一个一直指向第二个节点的（类似滑动指针）的指针
PNODE delete_firstone_node(PNODE); // 若从头开始删除，从尾部插入，即实现了队列  delete_firstone_node()得和尾插法搭配
/**
 *
 * cr()和creat()系列的创建链表函数的不同之处在于，cr系列是用一个临时指针指向固定位置而后直接挂载在要挂载节点后
 * 而没有定义temp指针指向一片空间 在经过倒换来创建链表
 */
int main()
{

   PNODE afdasd = createlinkedlist();
   bianli(afdasd);
   delete_num(afdasd, 1);
   delete_pos(afdasd, 1);
   
   bianli(afdasd);


    PNODE er = cr_in_first();
    bianli(er);
    insert(er, 1, 666);
    insert(er, 3, 999);
    bianli(er);

    PNODE zd = creat_in_first();
    bianli(zd);

    PNODE Pstack = (PNODE)malloc(sizeof(NODE)); // 让Pstack指向一个头节点
    Pstack->NEXT = NULL;
    insert_in_last(Pstack, 345);
    bianli(Pstack);
    insert_in_last(Pstack, 12);
    insert_in_last(Pstack, 33);
    insert_in_last(Pstack, 5657);
    insert_in_last(Pstack, 777);
    bianli(Pstack);

    PNODE ph = cr(); // cr我自己想的，比原先的少定义一个temp指针，两个都可以 理解原理即可
    if (isempty(ph))
    {
        printf("创建完成\n");
    }
    bianli(ph);
    puts("插入");
    insert(ph, 3, 4545);
    bianli(ph);
    /**
     * @brief 用头插法（个人感觉尾插更实用，好理解）  尾插法详情：参考cr() 和 createlinkedlist()
     * 大致为：z->element = val;
     *        z-next = pta-next;
     *        pta->next = z;
     *        保证其每次插到头部
     */

    PNODE Phead = createlinkedlist(); // 这里时头指针指向了链表的头节点
    if (isempty(Phead))
    {
        printf("创建完成\n");
    }
    bianli(Phead);
    int vv;
    puts("输入要查找的元素：");
    scanf("%d", &vv);
    PNODE nd = findoutnumber(Phead, vv);
    if (nd == NULL)
    {
        puts("查找失败");
    }
    else
    {
        puts("查找成功");
        printf("%d是要查找的元素\n", nd->element);
    }
    puts("输入要查找的元素的位置：");
    int pos;
    scanf("%d", &pos);
    PNODE md = findoutposition(Phead, pos);
    if (nd == NULL)
    {
        puts("查找失败");
    }
    else
    {
        puts("查找成功");
        printf("%d是要查找的元素\n", md->element);
    }
    puts("请输入像删除的节点位置：");
    int vx;
    scanf("%d", &vx);
    delete_pos(Phead, vx); // 按位置删除
    bianli(Phead);
    int numm;
    puts("要删除的节点数值为：");
    scanf("%d", &numm);
    delete_num(Phead, numm);
    bianli(Phead);

    insert(Phead, 3, 100);
    bianli(Phead);
    system("pause");

    return 0;
}

PNODE createlinkedlist(void)
{
    puts("插入元素的尾插法createlinkedlist():【使用temp指针版本】");//注：使用temp指针是指插入的新节点用不用指针指它，而不是有没有pTail
    PNODE Phead = (PNODE)malloc(sizeof(NODE)); // 分配了一个不存放有效数据的头节点
    PNODE PTail = Phead;                       // 只是好操作了定义这个
    PTail->NEXT = NULL;                        // 定义ptail可以不牵扯phead来定义尾节点。因为后面的操作如果用phead直接进行操作，则会找不到phead
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
        PNODE temp = (PNODE)malloc(sizeof(NODE)); // 用一个临时指针指向 想插入的新节点
        if (temp == NULL)
        {
            printf("分配失败");
            return NULL;
        }
        printf("请输入第%d个结点的element值：", i);
        scanf("%d", &val);

        temp->element = val;
        temp->NEXT = NULL;
        PTail->NEXT = temp;
        PTail = temp; // 尾插法
    }

    return Phead;
}
bool isempty(PNODE Phead)
{
    if (Phead == NULL)
    {
        puts("出错");
        return NULL;
    }
}
void bianli(PNODE head)
{
    if (head == NULL)
    {
        puts("error, out of space");
        return;
    }
    PNODE p = head->NEXT;
    printf("遍历输出为：");
    while (p != NULL)
    {
        printf("%d->", p->element);
        p = p->NEXT;
    }
    puts(" ");
}
PNODE findoutnumber(PNODE Phead, int val)
{
    PNODE ppp = Phead->NEXT;
    while (ppp != NULL && ppp->element != val)
    {
        ppp = ppp->NEXT;
    }
    return ppp;
}
PNODE findoutposition(PNODE Phead, int pos)
{
    int count = 1;
    PNODE po = Phead->NEXT;
    if (pos <= 0)
    {
        puts("查询失败，有问题");
        return NULL;
    }
    while (po != NULL)
    {
        if (count == pos)
        {
            return po;
        }
        po = po->NEXT;
        count++;
    }
}
void delete_pos(PNODE Phead, int pos) // 
{
    PNODE ps = Phead; // ps指向头节点
    PNODE de;               // 一会用它指向要删除的节点，不然找不到了就删除不了
    int count = 1;

    while (count != pos) // 即找到要删除节点的前一个节点  
    {
        if (ps->NEXT == NULL)
        {
            puts("位置有问题,程序错误退出");
            return;
        }

        ps = ps->NEXT;
        count++;
    }

    de = ps->NEXT;
    ps->NEXT = ps->NEXT->NEXT;
    free(de);
}
void delete_num(PNODE Phead, int val) // 完美实现了选定数字删除  //利用了指向前面的指针
{
    PNODE pz = Phead;
    PNODE de, pr;//pr指向pz的前一个节点，才能删除选定的数字
    if (pz->element != val)
    {
        pr = pz;
        pz = pz->NEXT;
        if (pz->NEXT == NULL)
        {
            puts("查无此数");
        }
    }
    de = pr->NEXT;
    pr->NEXT = pr->NEXT->NEXT;
    free(de);
}

PNODE insert(PNODE Phead, int pos, int val) // 在数组中 与链表很不相同，数组中插入，需要循环后移，而链表不需要//也可以用一个指向此节点上一个节点的前驱指针
{
    PNODE p = Phead;            // 现在p指向链表
    for (int i = 0; i < pos - 1; i++) // 画图，如果pos为三号位置，则需要往后指两位,所以要找到第二号位置
    {                                 //当向头节点后插入元素时，相当于没有执行for循环
        p = p->NEXT;
    }
    PNODE r = (PNODE)malloc(sizeof(NODE));
    if (r == NULL)
    {
        puts("分配失败");
        return NULL;
    }
    r->element = val;
    r->NEXT = p->NEXT;
    p->NEXT = r;

    return Phead;
}

PNODE cr(void)
{
    puts("在队尾插入元素的尾插法cr():【未使用temp指针版本】");
    PNODE ppp = (PNODE)malloc(sizeof(NODE));
    PNODE pta; // 用ppp操作容易找不到头节点了
    pta = ppp;
    pta->NEXT = NULL;
    int b;
    int zz;
    puts("请输入想创建的节点个数");
    scanf("%d", &b);
    for (int i = 1; i <= b; i++)
    {
        pta->NEXT = (PNODE)malloc(sizeof(NODE));
        printf("请输入第%d个date域的值：", i);

        scanf("%d", &zz);
        pta->NEXT->element = zz;

        pta = pta->NEXT;
        pta->NEXT = NULL;
    }

    return ppp;
}

PNODE insert_in_last(PNODE Phead, int val)
{

    PNODE Ptemp = Phead; // 临时指针指向第一个有效节点，一会用它操作，不至于phead找不到了

    int i = 1;
    while (Ptemp->NEXT != NULL)
    {
        Ptemp = Ptemp->NEXT;
        i++;
    }

    PNODE z = (PNODE)malloc(sizeof(NODE));
    z->element = val;
    z->NEXT = NULL;
    Ptemp->NEXT = z;
    Ptemp = z;

    return Phead;
}

PNODE creat_in_first(void)
{
    puts("插入元素的头插法creat_in_first():【使用temp指针版本】");
    PNODE Phead = (PNODE)malloc(sizeof(NODE)); // 定义一个指向头节点的头指针 //与尾插法不同的是，其不需要一个尾指针指向最后一个元素
    Phead->NEXT = NULL;
    if (Phead == NULL)
    {
        puts("分配空间失败");
        return NULL;
    }
    int b;
    puts("请输入想要插入的节点个数");
    scanf("%d", &b);
    int val;
    for (int i = 1; i <= b; i++)
    {
        PNODE s = (PNODE)malloc(sizeof(NODE));
        printf("请输入第%d个节点的data域的值：", i);
        scanf("%d", &val);
        s->element = val;
        s->NEXT = Phead->NEXT;
        Phead->NEXT = s;
    }
    return Phead;
}

PNODE cr_in_first(void) // 类似cr()的不同第三个temp指针创建链表 头插 的方法 这种方法需要定义一个一直指向第二个节点的（类似滑动指针）的指针
{
    puts("插入元素的头插法creat_in_first():【未使用temp指针版本】");
    PNODE Phead = (PNODE)malloc(sizeof(NODE));
    Phead->NEXT = NULL;
    PNODE pz = Phead->NEXT; // 定义一个永远指向第一个有效节点的指针
    int val;
    if (Phead == NULL)
    {
        puts("分配空间失败");
        return NULL;
    }
    puts("请输入要分配的节点个数：");
    int b;
    scanf("%d", &b);

    for (int i = 1; i <= b; i++)
    {
        printf("请输入第%d个节点的val值：", i);
        scanf("%d", &val);

        pz = Phead->NEXT;//永远指向第一个有效节点的指针
        Phead->NEXT = (PNODE)malloc(sizeof(NODE));
        Phead->NEXT->NEXT = pz;//在第一次循环中 pz = Phead->NEXT = NULL 详：365行 经此一步，null为第一个插入的有效节点所携带，因为头插，所以尾节点指向null完成
        Phead->NEXT->element = val;
    } 
    return Phead;
}

PNODE delete_firstone_node(PNODE Phead)//永远只删除第一个有效节点
{
    PNODE ps = Phead->NEXT;
    Phead->NEXT = ps->NEXT;
    free(ps);
    return Phead;
}