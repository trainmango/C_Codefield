/* 
    2023年1月31日18点16分
    多级指针-2
 */
#include <stdio.h>
#include<stdlib.h>
#include<malloc.h>
void f(int ** q)
{
   //*q就是p 
}
void g()
{
    int i = 10;
    int * p = &i; 

    f(&p); //p是int *类型，&p是int **类型
}
int main()
{
    g();
    
    
    system("pause");
    return 0;
}