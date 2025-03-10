/* 
    2022年10月14日15点57分 
    注意的问题:
             全局变量和局部变量命名冲突的问题
                 在一个函数内部如果定义的局部变量的名字和全局变量名异样时，局部变量会屏蔽掉
                 全局变量

    
 */
#include <stdio.h>
#include<stdlib.h>

int i = 99;

void f(int i)
{   
    //int i;   此时就不能在这个函数内部再定义一个变量i了  上面的f（int i）中已经定义了一个i了
    //上面的全局变量 i = 99; 被此函数屏蔽以此函数中的i为主
    printf("i = %d\n", i);
}

int main(void)
{
    f(8);
    system("pause");
    return 0;
}