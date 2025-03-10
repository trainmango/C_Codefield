/* 
        2022年10月17日17点11分
        经典指针程序——两个数字互换
 */
#include <stdio.h>
#include<stdlib.h>
/* 
      //不能完成互换功能
       void huhuan_1(int a, int b)
{
    int t;
    t = a;
    a = b;
    b = t;
    return;

}
 */
/*
  void huhuan_2(int * p, int * q)
{
         int * t;// 如果要互换p和q的值 t必须是int *类型，不能是int
         t = p;
         p = q;
         q = t;
}  不能完成互换共功能
*/
void huhuan_3(int * p, int * q) //可以完成互换功能
{
         int  t;// 如果要互换*p和*q的值 t必须是int 类型，不能是int *，否则出错
         t = *p;  //p是int *类型，*p是int类型
         *p = *q;
         *q = t;
}
int main(void)
{   
    int a = 3;
    int b = 5;
  
    huhuan_3(&a, &b);  //huhuan_2(*p, *q);是错误的还是实参形参的问题  huhuan_2(a, b); 也是错的
    //互换了形参a，b  与主函数的实参a，b无关所以下边还是输出3，5
   /* 
        int a = 3;
        int b = 5;
        int t;
        t = a;
        a = b;
        b = t;
        printf("a = %d, b = %d\n", a, b);
        交换两个数字的常规写法
    */ 
    printf("a = %d, b = %d\n", a, b);
    system("pause");
    return 0;
}