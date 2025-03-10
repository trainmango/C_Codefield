/*
      2023年2月12日20点27分
      跨函数使用内存
 */
#include <stdio.h>
#include <stdlib.h>
int f();
int main()
{
    int i = 10;

    i = f();
    printf("i = %d\n", i);

    system("pause");
    return 0;
}
int f()
{
    int j = 20;
    return j;
}
