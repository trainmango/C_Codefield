/*
    2022年9月9日17点08分  
 */
#include <stdio.h>
#include<stdlib.h>
int main()
{
    int i, sum = 0;
    for ( i = 1; i <= 100; i+=2)
    {
      sum = sum + i;
    }
    printf("1~100之间所有奇数之和：%d\n", sum);
    printf("奇数和的平均值为：%d\n", sum/50);


    system("pause");
    return 0;
}