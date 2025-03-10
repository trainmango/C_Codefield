/* 
    2022年9月26日19点45分  函数例子
 */
#include <stdio.h>
#include<stdlib.h>
void max(int i, int j);
void max(int i, int j) //max是函数的名字，i和j是形式参数（简称形参）void表示函数没有返回值
{                       //i和j被分配的内存空间会在处理完结果后被释放掉（例a和b比完大小）从而重新被赋予
    if (i > j)
        printf("%d\n", i);
    else
        printf("%d\n", j);
}
//当多个函数中的同一个变量 例如 主函数中的int i； 和另一个函数中的int i；互不干扰
int main()
{
    int a, b, c, d, e, f;
    a = 1, b = 2, c = 3, d = 9, e = -5, f = 100; //,  是,表达式意思是限制性第一个a=1 ,再执行b=2
    //若用i=(a = 1, b = 2, c = 3, d = 9, e = -5, f = 100);则i=100
    max(a, b);
    max(c, d);
    max(e, f);
    

    /*
    if (a > b)
        printf("%d\n", a);
    else
        printf("%d\n", b);
    if (c > d)
        printf("%d\n", c);
    else
        printf("%d\n", d);
    if (e > f)
        printf("%d\n", e);
    else
        printf("%d\n", f);
        用if语句将数值进行两两比较取最大值，用if语句很麻烦。
    */ 
    
    
    system("pause");
    return 0;
}