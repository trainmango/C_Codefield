/* 
   2023年1月28日16点34分

 */
#include <stdio.h>
#include<stdlib.h>
#include<malloc.h>
void f(int * q)
{
   // *p = 200; 错误，p在main函数中调用，不能在f函数中使用
   *q = 200;
   //如果加了free(q); 则会把q所指向的内存释放掉，导致第22行出错

}
int main()
{
    int * p = (int *)malloc(sizeof(int)); //sizeof(int)返回值是int所占的字节数
    *p = 10;

    printf("%d\n", *p);  //10
    f(p);  //p是int *类型
    printf("%d\n", *p);  //200
    system("pause");
    return 0;
}