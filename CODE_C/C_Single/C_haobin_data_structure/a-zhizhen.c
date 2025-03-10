/* 
     2023年2月12日14点46分
     指针的复习
 */
#include <stdio.h>
#include<stdlib.h>
void Show_Array(int * pArr, int len)//接收数组首地址和长度
{
    pArr[0] = -1;   //pArr[0] == *(p+0)  p[2] == *(p+2) == a[2]
    int i;
    for ( i = 0; i < len; i++)
    {
        printf("PArr[i]的值依次为：%d\n", pArr[i]);
    }
    
}
int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    Show_Array(a, 5);  //a等价于&a[0],&a[0]本身就是int *类型
    printf("a[0]的值为：%d\n", a[0]);
    printf("a[0]的值为：%d\n", *(a+0));
    printf("a[1]的值为：%d\n", *(a+1));
    printf("a[0]的地址为%p\n", (a+0));
    printf("a[1]的地址为%p\n", (a+1));  // 每个数组间 地址 相差 sizeof(int){即4个} 
    printf("a[2]的地址为%p\n", (a+2));
    printf("a[3]的地址为%p\n", (a+3));
    printf("a[4]的地址为%p\n", (a+4));

    int * p;  //p是个变量名字，int *表示p变量只能存储int类型变量的地址 如若 例如：让p接收到char ch = 'A';中 ch 的地址 
              //p = &ch;则会报错
    int i = 10;
    int j;
    p = &i;
    j = *p;  //等价于j = i;
    printf("i = %d, j = %d, *p = %d\n", i, j, *p);
    system("pause");
    return 0;
}