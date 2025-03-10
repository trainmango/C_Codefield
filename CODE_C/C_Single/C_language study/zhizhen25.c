/* 
      2023年2月6日14点09分
      跨函数使用内存_1
 */
#include <stdio.h>
#include<stdlib.h>
#include<malloc.h>
void f(int ** q)  //q是个指针变量
{
   int i = 5;
   //*q等价于p q和**q都不等价于p
   //*q = i;//error  因为*q = i; 等价于 p = i;这样写是错误的
   *q = &i;  //p = &i;

}
int main()
{ 
    int * p;  //18行
    f(&p);    //19行
    printf("%d\n", *p); //20行   //本语句语法没有问题，但逻辑上有问题。
                        //因为19行的f(&p); 函数运行完就释放了，i就不存在了。p保存i的地址，但p无权访问i的空间
    system("pause");
    return 0;
}