/*
   2023年2月6日14点55分
   动态内存可以跨函数使用
 */
#include <stdio.h>
#include<stdlib.h>
#include<malloc.h>
void f(int ** q)
{                                 //malloc(sizeof(int)动态分配实在堆里面分配的，函数终止的时候不会释放【函数终止本质上是出栈】堆里面和栈无关
    *q = (int *)malloc(sizeof(int)); //sizeof(数据类型)返回值是该数据类型所占字节数
        //等价于p = (int *)malloc(sizeof(int));
    //*q = 5; 即 p = 5;不行，p是指针变量，存放的是地址  【*p是以p的内容为地址的变量】
    **q = 5;  //即*p = 5;
}
int main()
{
    
    int * p;
    f(&p);
    printf("%d\n", *p);
    system("pause");
    return 0;
}
/* 
用动态内存可以做到
例如：
  main()
  {
    f(); 可以在f内部造出个空间
    g(); 用g函数对这个空间进行操作
    m(); 在用m函数对操作结果进行输出
  }
  


 */