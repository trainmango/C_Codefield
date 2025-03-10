/*
    2022年9月9日17点08分  
 */
#include <stdio.h>
#include<stdlib.h>
int main()
{
    int i, sum = 0;
    for ( i = 0; i <= 100; i++)
    {
      sum = sum + i;
    }
    printf("1~100之间所有数之和：");
    printf("%d\n", sum);
    

    system("pause");
    return 0;
}