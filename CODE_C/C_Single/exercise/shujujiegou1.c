#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
typedef struct {
    char no[10];   //8位学号
    char name[20]; //姓名
    int price;     //成绩
}Student;

typedef struct LNode
{
    Student data;
    struct LNode *next;
}LNode,*Linklist;


Linklist creatlist()//（头插入法）输入学生信息。
{
    Linklist L,p;
    int i,n;
    L=(Linklist)malloc(sizeof(LNode));
    L->next=NULL;
    printf("请输入要录入学生的个数：");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        p=(Linklist)malloc(sizeof(LNode));
        printf("请输入学生的信息：\n");
        printf("姓名：");
        scanf("%s",&p->data.name);
        printf("学号：");
        scanf("%s",&p->data.no);
        printf("成绩：");
        scanf("%d",&p->data.price);
        p->next=L->next;
        L->next=p;
    }
    return L;
}

void putlist(Linklist L)//打印学生信息。
{
    Linklist p;
    p=L->next;
    while(p)
    {
        printf("姓名：%s\n学号：%s\n成绩：%d\n",p->data.name,p->data.no,p->data.price);
        p=p->next;
        printf(" ");
    }printf("\n");
}

int lengthlist(Linklist L)//求学生的总数。
{
    Linklist p;
    int j;
    p=L->next;
    j=0;
    while(p!=NULL)
    {
        j++;
        p=p->next;
    }
    printf("表中的学生总数为:%d\n",j);
}
void namegetlist(Linklist L)//根据学生姓名查找学生的信息。
{
    char name[10];
    int j=1;
    Linklist p;
    printf("请输入查找学生的姓名:");
    scanf("%s",&name);
    p=L->next;
    while(p&&strcmp(p->data.name,name)!=0)
    {
        p=p->next;
        j++;
    }
    if(p)
        printf("该学生的信息：\n学号：%s\n成绩：%d\n",p->data.no,p->data.price);
    else
        printf("该表中没有该学生的信息。");
    }
void getlist(Linklist L)//根据学生结点位置查找学生信息。
{
    int i,j=1,l=0;
    Linklist p;
    printf("请输入查找学生的位置结点：");
    scanf("%d",&i);
    p=L->next;
    while(p!=NULL)
    {
             l++;
             p=p->next;
    }
    p=L->next;
    while((p->next)&&(j<i))
    {
             p=p->next;
             ++j;
    }
    while(i>l)
    {
              printf("输入的结点值超过学生总数 ，请重新输入学生的位置结点：");
              scanf("%d",&i);
    }
    while((p!=NULL)&&(j<i))
    {
             p=p->next;
             j++;
    }
    printf("查找学生信息：\n姓名:%s\n学号：%s\n成绩：%d\n",p->data.name,p->data.no,p->data.price);
}

void insertlist(Linklist L)//学生信息插入。
{
    int i,j,l;
    Linklist p,s;
    p=L;l=0;
    while(p!=NULL)
    {
        l++;
        p=p->next;
    }
    printf("请输入插入学生的结点位置:");
    scanf("%d",&i);
    while(l<i)
    {
         printf("输入的结点值已超过总数,请重新输入插入学生的结点位置:");
         scanf("%d",&i);
    }
    p=L;j=1;
    while(p&&(j<i))
    {
        p=p->next;
        ++j;
    }
    s=(Linklist)malloc(sizeof(LNode));
    printf("请输入学生的信息：\n");
    printf("姓名：");
    scanf("%s",&s->data.name);
    printf("学号：");
    scanf("%s",&s->data.no);
    printf("成绩：");
    scanf("%d",&s->data.price);
    s->next=p->next;
    p->next=s;
    printf("学生信息插入成功！");
    printf("\n");
}
void deletelist(Linklist L)//学生信息的删除。
{
    int i,j,l=0;
    Linklist p,q;
    p=L->next;
    while(p!=NULL)
    {
        l++;p=p->next;
    }
    printf("请输入要删除学生的位置结点：");
    scanf("%d",&i);
    while(l<i)
    {
        printf("输入的结点值超过总数,请重新输入要删除学生的位置结点：");
        scanf("%d",&i);
    }
    p=L; j=1;
    while((p->next)&&(j<i))
    {
        p=p->next;
        ++j;
    }
    q=p->next;
    p->next=q->next;
    free(q);
    printf("删除成功！\n");
}


int main()//主函数
{
    Linklist L;
    int k;
    L=creatlist();
    printf("\n");
    putlist(L);
    printf("学生信息输入成功！\n");
    printf("学生信息管理系统的操作目录:\n");
    printf("__________________________\n");
    printf("__________________________\n");
    printf("1、根据学生的结点位置查找学生信息；2、求表中学生的总数；3、插入学生的信息；4、删除学生的信息；5、根据学生的姓名查找学生信息。\n");
    printf("__________________________\n");
    while(1)
    {
        printf("请选择操作：");
        scanf("%d",&k);
        switch(k)
        {
             case 0:printf("谢谢使用！");exit(0);
             case 1:getlist(L);break;
             case 2:lengthlist(L);break;
             case 3:insertlist(L);putlist(L);break;
             case 4:deletelist(L);putlist(L);break;
             case 5:namegetlist(L);break;
        }
    }
}
