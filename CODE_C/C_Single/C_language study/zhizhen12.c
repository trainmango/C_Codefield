/*
     2022年10月21日17点02分
     确定一维数组需要几个参数-3
 */
#include <stdio.h>
#include <stdlib.h>
void f(int *pArr, int len) // 把b（b是int *类型）发送给 pArr（pArr也是int *类型）
{                          // 即 把&b[0]发送给 pArr，即*(&b[0])就是b[0]
  // 类似的 即a[i]等价于*(a+i)等价于*(&a[0+i])
    int i;
    for (i = 0; i < len; i++)
    {
        printf("%d ", pArr[i]); // *(pArr+i) 等价于 pArr[i] 也等价于b[i] 也等价于 *(b+i)
        printf("\n");
        printf("%d ", *(pArr + i));
        printf("\n");
    }
    /*a相当于 &a[0],*(地址)是取值运算符，这里*是解引用操作符，可以理解成打开对应地址编号
    的盒子，取出里面的数据。
    *(&a) 就是打开a对应的小盒子，取出里面的数据，即*(&a)和a等价。
    zhizhen9.c详见
    */
}
int main(void)
{

    int a[5] = {1, 2, 3, 4, 5};
    int b[6] = {-1, -2, -3, 4, 5, -6};
    int c[100] = {1, 99, 22, 33};
    f(b, 6);
    system("pause");
    return 0;
}