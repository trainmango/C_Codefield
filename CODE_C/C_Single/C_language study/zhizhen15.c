/* 
      2022年10月31日16点31分
      （不想通过返回值修改）要想改变一个变量的值，只能发送这个变量的地址
 */
#include <stdio.h>
#include<stdlib.h>
void f(int * p) //如果不用指针，不用return，被调函数永远无法改变主函数中i的值
{
    *p = 10;  //   即i = 10;
}             //即int * p = &i;
int main()
{
    int i = 5;
    f(&i);
    printf("i = %d\n", i);

    system("pause");
    return 0;
}