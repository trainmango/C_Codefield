/*  
    2022年10月21日15点37分
    指针使函数返回一个以上的值举例
 */ 
#include <stdio.h>
#include<stdlib.h>
f(int i, int j)
{
   return 100;//例：本句return含义：结束被调函数，向主调函数返回100
}//利用return返回值来改变主函数的实参的值太繁琐，远不如指针。 
void g(int * p, int * q)
{
    *p = 1;
    *q = 2;
}
int main(void)
{
    int a = 5;
    int b = 5;
    g(&a, &b);
    printf("%d %d\n", a, b);
    int z =  f(a, b);
    printf("%d \n", z);

   
    system("pause");
    return 0;
}
