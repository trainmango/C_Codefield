/* 
    2022年10月21日15点13分
 */
#include <stdio.h>
#include<stdlib.h>
void swap_3(int *p, int *q)//形参名字是p和q，接受实参数据的是p和q，而不是*p和*q
{
   int t;   // 如果要互换*p和*q的值 t必须是int 类型，不能是int *，否则出错
   t = *p;
   *p = *q; //相当于把*p指向的变量和*q指向的变量互换了，所以
   *q = t;  //即便运行完后被释放了，也不影响把a，b的值互换了。
}
int main()
{
    int a = 3;
    int b = 5;
    swap_3(&a, &b);//若为swap_3(a, b);则会错误，a不能发送给p，因为a存放的是整形变量
                   //p存放的是整形地址，所以要变为&a,&b
    printf("a = %d b = %d\n", a, b);
    system("pause");
    return 0;
}
//下边两个swap没在main函数上边，没加前置声明所以不运行
void swap_1(int i, int j)
{
     int t;
     t = i;
     i = j;
     j = t;

}
void swap_2(int * p, int * q)//形参名字是p和q，接受实参数据的是p和q，而不是*p和*q
{                            //即int * p = &a;即int * p; p = &a;
   int * t;                  
   t = p;                    //相当于把p和q互换了，形参p和a，q和b不是一个变量。
   p = q;                    //所以运行结束就被释放了不影响a和b的值，所以不能完成互换
   q = t;
}