#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#define MAXSIZE 100
typedef struct
{
    char name[10]; //姓名
    char no[8];   //8位学号
    int price;     //成绩
}Student;
typedef  struct
{
  Student  elem[100]; //指向数据元素的基地址
  int  length; //线性表的当前长度
  int listsize;//表长
}Sqlist,*Seqlist;


void initlist( Seqlist L)//建立一个空的顺序线性表
{
    L->length=0;
    L->listsize=MAXSIZE;
}

void displist(Seqlist L)//输出学生信息
{
    int i;
    for( i=1;i<=L->length;i++)
    {
      printf("姓名:%s\n",L->elem[i-1].name);
      printf("学号:%s\n",L->elem[i-1].no);
      printf("成绩:%d\n",L->elem[i-1].price);
    }
    printf("\n");
}

void inputlist(Seqlist L)//学生信息的输入
{
    int i,n;
    printf("请输入学生的个数：");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("请输入学生的信息：\n");
        printf("姓名：");
        scanf("%s",&L->elem[i].name);
        printf("学号：");
        scanf("%s",&L->elem[i].no);
        printf("成绩：");
        scanf("%d",&L->elem[i].price);
        L->length++;
    }
    printf("\n");
}

void seeklist(Seqlist L)//根据学生节点位置查找学生信息
{
    int i;
    printf("请输入查找学生的结点：");
    scanf("%d",&i);
    while(i<1||i>L->length)
    {
          printf("输入超出学生的总数，请重新输入查找学生的节点：");
          scanf("%d",&i);
    }
    printf("该学生的信息：\n");
    printf("姓名：%s\n学号：%s\n成绩：%d\n",L->elem[i-1].name,L->elem[i-1].no,L->elem[i-1].price);
}

void nameseeklist(Seqlist L)//根据学生姓名查找学生信息
{
       int i;
       char name[20];
       printf("请输入查找学生姓名：");
       scanf("%s",&name);
       for(i=0;i<L->length;i++)
       {
            if(strcmp(L->elem[i].name,name)==0)
            {
                break;
            }
       }
       if(strcmp(L->elem[i].name,name)==0)
            {
                printf("该学生的信息：\n");
                printf("学号：%s\n成绩：%d\n",L->elem[i].no,L->elem[i].price);
            }
      else
            printf("该表中没有该学生！\n");

}

void deletelist(Seqlist L)//学生信息的删除
{
      int i;
      int j;
      printf("请输入删除学生的节点：");
      scanf("%d",&i);
      while(i<1||i>L->length)
      {
          printf("输入超出学生的总数，请重新输入删除学生的节点：");
          scanf("%d",&i);
      }
      for(j=i;j<=L->length-1;j++)
      {
          L->elem[j-1]=L->elem[j];
      }
      L->length--;
}
void insertlist(Seqlist L)//学生信息的插入
{
      int i,j,x;
      printf("请输入要插入学生的节点位置：");
      scanf("%d",&i);
      if(L->length==MAXSIZE)
         printf("存储已满，无法插入\n");
      while(i<1||i>(L->length+1))
      {
         printf("无法插入，请重新输入插入学生的节点位置：");
         scanf("%d",&i);
      }
         for(j=L->length-1;j>=i-1;j--)
         {
              L->elem[j+1]=L->elem[j];
         }
         printf("请输入学生的信息：\n");
         printf("姓名：");
         scanf("%s",&L->elem[i-1].name);
         printf("学号：");
         scanf("%s",&L->elem[i-1].no);
         printf("成绩：");
         scanf("%d",&L->elem[i-1].price);
         ++L->length;
         printf("\n");
}

int lengthlist(Seqlist L)//求表中学生的总数
{
    return L->length;
}

void main()//学生信息管理系统的主函数
{
    Sqlist L1;
    Seqlist L=&L1;
    int k;
    initlist(L);//建立一个空的顺序线性表
    inputlist(L);//输入学生的信息。
    printf("\n");
    displist(L);//打印学生的信息。
    printf("学生信息输入成功！\n");
    printf("\n");
    printf("学生信息管理系统的操作目录:\n");
    printf("__________________________\n");
    printf("__________________________\n");
    printf("1、根据学生的结点位置查找学生信息；2、根据学生的姓名查找学生信息；3、插入学生的信息；4、删除学生的信息；5、求表中学生的总数。\n");
    printf("__________________________\n");
    while(1)
    {
        printf("请选择操作：");
        scanf("%d",&k);
        switch(k)
        {
             case 0:printf("谢谢使用！");exit(0);
             case 1:seeklist(L);break;
             case 2:nameseeklist(L);break;
             case 3:insertlist(L);displist(L);break;
             case 4:deletelist(L);displist(L);break;
             case 5:printf("该表中学生总数：%d\n",lengthlist(L));break;
        }
    }
}


