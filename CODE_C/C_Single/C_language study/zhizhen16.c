/* 
       2022年10月31日16点39分
       指针变量的运算
 */
#include <stdio.h>
#include<stdlib.h>
int main()
{ 
    int * p;
    int * q; 
    int a[5];
   /* 
    int i = 5;
    int j = 10;
    int * p = &i;
    int * q = &j;
    // p - q 没有实际意义
    */   // 因为i于j的存储空间不同，所以相减没有意义
    p = &a[1];
    q = &a[4];

    printf("p所占地址号： %d   q所占地址号：  %d  p和q所指向的单元相隔%d个单元\n", p, q, q - p);

    system("pause");
    return 0;
}