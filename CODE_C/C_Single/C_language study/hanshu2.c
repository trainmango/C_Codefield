/* 
   2022年9月26日20点14分
 */
#include <stdio.h>
#include<stdlib.h>
int f(void)//括号中的void表示该函数不能接受数据，int表示函数的返回值是int类型
{
    return 10;//向主调函数（main函数）返回10
}
void g()//函数名前面的void表示该函数没有返回值  
{
// return 0; // 与10行的行首的void相矛盾
}
int main()
{
    int j = 88;
    j = f();
    printf("%d\n", j);
    // j = g();  //error 因为g函数没有返回值
    system("pause");
    return 0;
}  