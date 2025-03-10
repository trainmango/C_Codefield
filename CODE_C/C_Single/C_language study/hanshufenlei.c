/* 
   2022年9月30日09点59分
   函数的分类
         有参函数 和 无参函数 例：void f(void) //f(void)中void就是无参
         有返回值 和 无返回值
         库函数 和 用户自定义函数
         值传递函数 和 地址传递函数

         普通函数和主函数(main函数)
            一个程序必须有且只能有一个主函数
            主函数可以调用普通函数 普通函数不能调用主函数
            普通函数可以相互调用
            主函数是程序的入口，也是程序的出口

 */
#include <stdio.h>
#include<stdlib.h>
void max1(int i, int j) //max是函数的名字，i和j是形式参数（简称形参）void表示函数没有返回值
{
    if (i > j)
        printf("%d\n", i);
    else
        printf("%d\n", j);
}
int max2(int i, int j)
{
    if(i > j)
         return i;
    else
         return j;
}       
int main()
{
    int a, b, c, d, e, f;
    a = 1, b = 2, c = 3, d = 9, e = -5, f = 100;
    printf("%d\n", max2(a, b));
    printf("%d\n", max2(c, d));
    printf("%d\n", max2(e, f));
    
    max1(a, b);
    max1(c, d);
    max1(e, f);
    
 system("pause");
    return 0;
} 