/* 
    2022年10月21日16点14分
    确定一维数组需要几个参数-1
 */
#include <stdio.h>
#include<stdlib.h>
//f函数可以输出任何一个一维数组的内容
void f(int * pArr, int len)  //a是第一个元素地址，普通变量不能存地址，所以pArr得用int *类型
{                            //即得用指针变量来存储地址
     int i;
     for ( i = 0; i < len; i++)
     
        printf("%d ",*(pArr+i));  //依次*pArr *(pArr+1) *(pArr+2)
     printf("\n");               //即a[i]等价于*(a+i)等价于*(&a[0+i])
}
int main(void)
{
    int a[5] = {1,2,3,4,5};
    int b[6] = {-1,-2,-3,4,5,-6};
    int c[100] = {1, 99, 22, 33};
    f(a, 5); //a是int * 类型   a是a[0]的地址 即a == &a[0]
    f(b, 6);
    f(c, 100);
   
    system("pause");
    return 0;
}