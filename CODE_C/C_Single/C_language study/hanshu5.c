/* 
     2022年10月14日10点26分  
     函数的实参和形参 :
              个数相同 位置一一对应 数据类型必须互相兼容
              
 */
#include <stdio.h>
#include<stdlib.h>
void f(int i,float x)
{
    printf("%d\n", i);
}
int main(void)
{
    f(9,6.6);

    system("pause");
    return 0;
}